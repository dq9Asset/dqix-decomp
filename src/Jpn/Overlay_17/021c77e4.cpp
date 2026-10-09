#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8988(void* obj);
extern "C" void* func_ov017_021b8978(void* obj);
extern "C" ARM void* func_ov017_021b8980(void* obj);
extern "C" ARM int func_0200ff04(GameState* battleStruct);

struct EventSrc_021c7334 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    char pad1[9];
    struct {
        unsigned char bit0 : 1;
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char nibble : 4;
    } bits;
    char pad2;
    struct {
        unsigned char pad : 7;
        unsigned char bit7 : 1;
    } flag0x13;
};

struct StatsFlags_021c7334 {
    char pad[0x3a];
    unsigned char flag0x3a;
    struct {
        unsigned char bit0 : 1;
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char nibble : 4;
    } bits0x3b;
};

// JPN: func_ov017_021c77e4
extern "C" ARM void func_ov017_021c77e4(void* unused0, struct EventSrc_021c7334* src, GameState* battleStruct, char* data) {
    void* obj = *(void**)(data + 0x3508);
    void* p1c = func_ov017_021b8988(obj);
    if (!p1c) {
        return;
    }
    if (!func_ov017_021b8978(obj)) {
        return;
    }
    if (!func_ov017_021b8980(obj)) {
        return;
    }
    int val = func_0200ff04(battleStruct);
    if (*(signed char*)((char*)p1c + 0x2a) == val) {
        return;
    }
    if (*(unsigned short*)((char*)p1c + 0x8) != src->field4) {
        return;
    }
    GameObject* combatant = battleStruct->GetCombatantByIndex(src->field6);
    if (!combatant) {
        return;
    }
    ((struct StatsFlags_021c7334*)(*(void**)((char*)combatant + 0x138)))->bits0x3b.bit0 = src->bits.bit0;
    ((struct StatsFlags_021c7334*)(*(void**)((char*)combatant + 0x138)))->bits0x3b.bit1 = src->bits.bit1;
    ((struct StatsFlags_021c7334*)(*(void**)((char*)combatant + 0x138)))->bits0x3b.bit2 = src->bits.bit2;
    ((struct StatsFlags_021c7334*)(*(void**)((char*)combatant + 0x138)))->bits0x3b.bit3 = src->bits.bit3;
    ((struct StatsFlags_021c7334*)(*(void**)((char*)combatant + 0x138)))->bits0x3b.nibble = src->bits.nibble;
    ((struct StatsFlags_021c7334*)(*(void**)((char*)combatant + 0x138)))->flag0x3a = src->flag0x13.bit7 != 0;
}

#endif
