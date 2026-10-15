#pragma once

struct PairTableBlock0207df50 {
    int values[10];
};

struct PairTablePair0207df50 {
    int values[2];
};

struct Foo0207df50 {
    PairTableBlock0207df50 liveTable;
    PairTableBlock0207df50 savedTable;
    unsigned int textureAllocationKey;
    int textureBytes;
    PairTablePair0207df50 livePair;
    PairTablePair0207df50 savedPair;
    unsigned int paletteAllocationKey;
    int paletteBytes;
};

extern "C" void func_0207de48(Foo0207df50* encoder, int textureBytes, int paletteBytes);
void CopyInternalFields0207df50(Foo0207df50* encoder);
void RestorePairTables0207df90(Foo0207df50* encoder);
void BackupPairTables0207dfac(Foo0207df50* encoder);
#if defined(jpn)
extern "C" void func_02044104(Foo0207df50* encoder);
#else
void PrepareEncodeStreamBuffer0204394c(Foo0207df50* encoder);
#endif

void CopyState0207dfc8(Foo0207df50* source, Foo0207df50* destination);
