#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8980(void* obj);
extern "C" int func_0200ff04(GameState* gameState);

struct PackedThreeBitValues {
    unsigned int f0 : 3;
    unsigned int f1 : 3;
    unsigned int f2 : 3;
    unsigned int f3 : 3;
    unsigned int f4 : 3;
    unsigned int f5 : 3;
    unsigned int f6 : 3;
    unsigned int f7 : 3;
    unsigned int f8 : 3;
    unsigned int f9 : 3;
    unsigned int unknownBits30 : 2;
};

struct PackedRecordUpdate {
    unsigned char unknown0[4];
    unsigned short field4;
    unsigned short field6;
    PackedThreeBitValues word8;
    PackedThreeBitValues wordc;
    unsigned short field10;
    unsigned char field12;
};

struct SynchronizedRecord {
    unsigned char unknown0[0x36];
    unsigned short field36;
    unsigned char unknown38[0x5c - 0x38];
    unsigned char chars0[0x14];
    unsigned char unknown70[0x7f - 0x70];
    unsigned char chars1[0x14];
    unsigned char unknown93[0xa4 - 0x93];
};

struct SynchronizedRecordSet {
    unsigned char unknown0[8];
    unsigned short field8;
    unsigned char unknownA[0x2a - 0xa];
    signed char field2a;
    unsigned char unknown2b[0x158 - 0x2b];
    SynchronizedRecord entries[8];
};

// JPN: func_ov017_021cb7a4
// Expands two packed words into one of two twenty-value record arrays.
// The record subject and the meaning of its three-bit values are not established.
extern "C" ARM void func_ov017_021cb7a4(int unused0, PackedRecordUpdate* update, GameState* gameState, unsigned char* self) {
    void* recordManager = *(void**)(self + 0x3000 + 0x508);
    void* recordOwner = func_ov017_021b8980(recordManager);
    if (!recordOwner) return;
    SynchronizedRecordSet* recordSet = *(SynchronizedRecordSet**)((unsigned char*)recordOwner + 0x8000 + 0xe18);
    if (!recordSet) return;
    int localOwnerId = func_0200ff04(gameState);
    if (recordSet->field2a == localOwnerId) return;
    if (recordSet->field8 != update->field4) return;
    int recordIndex = (int)update->field6 - 0xc0;
    if (recordIndex < 0) return;
    if (recordIndex >= 8) return;
    SynchronizedRecord* entry = &recordSet->entries[recordIndex];
    if (update->field12 == 1) {
        entry->chars0[0] = (unsigned char)update->word8.f0;
        entry->chars0[1] = (unsigned char)update->word8.f1;
        entry->chars0[2] = (unsigned char)update->word8.f2;
        entry->chars0[3] = (unsigned char)update->word8.f3;
        entry->chars0[4] = (unsigned char)update->word8.f4;
        entry->chars0[5] = (unsigned char)update->word8.f5;
        entry->chars0[6] = (unsigned char)update->word8.f6;
        entry->chars0[7] = (unsigned char)update->word8.f7;
        entry->chars0[8] = (unsigned char)update->word8.f8;
        entry->chars0[9] = (unsigned char)update->word8.f9;
        entry->chars0[10] = (unsigned char)update->wordc.f0;
        entry->chars0[11] = (unsigned char)update->wordc.f1;
        entry->chars0[12] = (unsigned char)update->wordc.f2;
        entry->chars0[13] = (unsigned char)update->wordc.f3;
        entry->chars0[14] = (unsigned char)update->wordc.f4;
        entry->chars0[15] = (unsigned char)update->wordc.f5;
        entry->chars0[16] = (unsigned char)update->wordc.f6;
        entry->chars0[17] = (unsigned char)update->wordc.f7;
        entry->chars0[18] = (unsigned char)update->wordc.f8;
        entry->chars0[19] = (unsigned char)update->wordc.f9;
        entry->field36 = update->field10;
    } else {
        entry->chars1[0] = (unsigned char)update->word8.f0;
        entry->chars1[1] = (unsigned char)update->word8.f1;
        entry->chars1[2] = (unsigned char)update->word8.f2;
        entry->chars1[3] = (unsigned char)update->word8.f3;
        entry->chars1[4] = (unsigned char)update->word8.f4;
        entry->chars1[5] = (unsigned char)update->word8.f5;
        entry->chars1[6] = (unsigned char)update->word8.f6;
        entry->chars1[7] = (unsigned char)update->word8.f7;
        entry->chars1[8] = (unsigned char)update->word8.f8;
        entry->chars1[9] = (unsigned char)update->word8.f9;
        entry->chars1[10] = (unsigned char)update->wordc.f0;
        entry->chars1[11] = (unsigned char)update->wordc.f1;
        entry->chars1[12] = (unsigned char)update->wordc.f2;
        entry->chars1[13] = (unsigned char)update->wordc.f3;
        entry->chars1[14] = (unsigned char)update->wordc.f4;
        entry->chars1[15] = (unsigned char)update->wordc.f5;
        entry->chars1[16] = (unsigned char)update->wordc.f6;
        entry->chars1[17] = (unsigned char)update->wordc.f7;
        entry->chars1[18] = (unsigned char)update->wordc.f8;
        entry->chars1[19] = (unsigned char)update->wordc.f9;
    }
}

#endif
