#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Field0x22_0215e43c {
    unsigned short low2:2;
    unsigned short mid4:4;
    unsigned short rest:10;
};

struct OutStruct0215e43c {
    int word0;
    int word4;
    char pad1[0xc - 8];
    short short0xc;
    short short0xe;
    short short0x10;
    short short0x12;
    short short0x14;
    char pad2[0x18 - 0x16];
    int word0x18;
    unsigned char byte0x1c;
    unsigned char byte0x1d;
    unsigned char byte0x1e;
};

// JPN: func_ov000_0215e43c
extern "C" ARM void func_ov000_0215e43c(int unused, struct OutStruct0215e43c* out, GameObject* combatant,
                                 short valC, short valA, short valB, int wordC, int wordD, unsigned char byteE) {
    if (out == NULL) return;
    out->short0xc = valC;
    out->short0xe = valA;
    out->short0x10 = valB;
    out->short0x12 = combatant->currentStats_->primaryStats.maxHP;
    out->short0x14 = combatant->currentStats_->primaryStats.maxMP;
    out->word0x18 = *(int*)((char*)combatant->currentStats_->unk1 + 0);
    out->byte0x1d = ((struct Field0x22_0215e43c*)((char*)combatant->currentStats_->unk1 + 0xe))->mid4;
    out->byte0x1e = ((struct Field0x22_0215e43c*)((char*)combatant->currentStats_->unk1 + 0xe))->low2;
    out->word0 = wordC;
    out->word4 = wordD;
    out->byte0x1c = byteE;
}

#endif
