#!/usr/bin/env python3
"""Focused tests for configure.py's opt-in regional source selection.

Run from the repository root: python3 -m unittest discover -s tools -p 'test_configure_sources.py'
"""
import importlib.util
import io
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

TOOLS = Path(__file__).resolve().parent
sys.path.insert(0, str(TOOLS))
with patch.object(sys, "argv", ["configure.py", "jpn"]):
    spec = importlib.util.spec_from_file_location("configure_test", TOOLS / "configure.py")
    cfg = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cfg)


class SourceSelectionTests(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory()
        self.root = Path(self.directory.name)
        self.old_cwd = Path.cwd()
        os.chdir(self.root)
        self.addCleanup(self.directory.cleanup)
        self.addCleanup(os.chdir, self.old_cwd)

    def source(self, name):
        path = Path(name)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("// fixture\n")
        return path

    def delinks(self, name, content):
        path = Path(name)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(content)
        return str(path)

    def test_complete_incomplete_assembly_library_and_duplicates(self):
        sources = [self.source(name) for name in
                   ("src/complete.cpp", "src/incomplete.cpp", "src/start.s", "libs/sdk/helper.c")]
        self.source("src/unreferenced.cpp")
        first = self.delinks("config/jpn/arm9/delinks.txt", """
    .text start:0x02000000 end:0x02000040 kind:code
src/complete.cpp:
    complete
    .text start:0x02000000 end:0x02000010
src/incomplete.cpp:
    .text start:0x02000010 end:0x02000020
//src/commented.cpp:
//    complete
libs/sdk/helper.c: // a library source
    complete
src/start.s:
    complete
""")
        second = self.delinks("config/jpn/arm9/overlays/ov000/delinks.txt", "src/complete.cpp:\n    complete\n")
        self.assertEqual(cfg.get_delink_sources([first, second]), sorted(sources))
        project = cfg.Project("jpn")
        with patch.object(cfg.args, "sources_from_delinks", True):
            self.assertEqual(project.source_files(), sorted(sources))
            self.assertEqual(project.source_object_files(),
                             [str(Path("build/jpn") / source.with_suffix(".o")) for source in sorted(sources)])
            output = io.StringIO()
            cfg.add_mwcc_builds(cfg.ninja_syntax.Writer(output), project, [])
            graph = output.getvalue()
            for source in sources:
                self.assertIn(str(Path("build/jpn") / source.with_suffix(".o")), graph)
            self.assertNotIn("unreferenced", graph)
            self.assertIn("build/jpn/src/incomplete.ctx.cpp", graph)

    def test_missing_active_source_fails_explicitly(self):
        path = self.delinks("delinks.txt", "src/missing.cpp:\n    complete\n")
        with self.assertRaisesRegex(FileNotFoundError, "source unit does not exist: src/missing.cpp"):
            cfg.get_delink_sources([path])

    def test_default_keeps_full_tree_for_every_region(self):
        self.source("src/unreferenced.cpp")
        self.source("src/start.s")
        self.source("libs/sdk/helper.c")
        expected = list(cfg.get_source_files([Path("src"), Path("libs")]))
        with patch.object(cfg.args, "sources_from_delinks", False):
            for region in ("jpn", "usa", "eur"):
                self.assertEqual(cfg.Project(region).source_files(), expected)

    def test_regions_do_not_leak_source_references(self):
        jp = self.source("src/jp.cpp")
        self.source("src/us.cpp")
        self.delinks("config/jpn/arm9/delinks.txt", "src/jp.cpp:\n")
        self.delinks("config/usa/arm9/delinks.txt", "src/us.cpp:\n")
        with patch.object(cfg.args, "sources_from_delinks", True):
            self.assertEqual(cfg.Project("jpn").source_files(), [jp])


if __name__ == "__main__":
    unittest.main()
