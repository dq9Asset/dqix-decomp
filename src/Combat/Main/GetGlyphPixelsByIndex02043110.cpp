#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"
#include "Resource/FontBankLoader.h"

#if defined(jpn)
// JPN: func_02043110
extern "C" ARM char* func_02043110(int pixelSize, int glyphIndex) {
    if (glyphIndex < 0) return NULL;

    FontGlyphTable* table;
    if (glyphIndex & 0x40000000) {
        table = static_cast<FontGlyphTable*>(
            AlwaysFalse02094b44(GetGlobal02109400_02094a00(), pixelSize));
        glyphIndex &= ~0x40000000;
    } else {
        table = GetFontGlyphTable_020429bc(pixelSize);
    }

    if (table == NULL) return NULL;
    if (table->glyphCount <= glyphIndex) return NULL;
    return table->glyphs + glyphIndex * table->glyphBytes;
}
#endif
