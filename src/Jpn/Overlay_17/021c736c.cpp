#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8988(void* obj);
extern "C" int func_ov017_021b8978(void* obj);
extern "C" void* func_ov017_021b8980(void* obj);
extern "C" int func_0200ff04(GameState* battleStruct);
struct Obj02088818;
extern "C" void func_02089114(struct Obj02088818* obj, unsigned short mode);

struct PackedBits021c6ebc {
    unsigned short fieldA : 2;
    unsigned short fieldB : 4;
    unsigned short fieldC : 3;
    unsigned short state : 3;
    unsigned short : 4;
};

struct SrcEntry021c6ebc {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    struct PackedBits021c6ebc bits8;
    unsigned char fielda;
    unsigned char pad_b;
    unsigned short fieldc;
    unsigned short fielde;
};

// JPN: func_ov017_021c736c
extern "C" ARM void func_ov017_021c736c(int unused0, struct SrcEntry021c6ebc* src, GameState* battleStruct, unsigned char* base) {
    unsigned char* table = *(unsigned char**)(base + 0x3000 + 0x508);
    unsigned char* obj = (unsigned char*)func_ov017_021b8988(table);
    if (obj == 0) {
        return;
    }
    if (func_ov017_021b8978(table) == 0) {
        return;
    }
    if (func_ov017_021b8980(table) == 0) {
        return;
    }
    if (*(signed char*)(obj + 0x2a) == func_0200ff04(battleStruct)) {
        return;
    }
    if (*(unsigned short*)(obj + 8) != src->field4) {
        return;
    }
    GameObject* combatant = battleStruct->GetCombatantByIndex(src->field6);
    if (combatant == 0) {
        return;
    }
    struct PackedBits021c6ebc* dst;
    unsigned char a = src->bits8.fieldA;
    dst = (struct PackedBits021c6ebc*)((unsigned char*)(*(void**)((char*)combatant + 0x138)) + 0x22);
    dst->fieldA = a;
    unsigned char b = src->bits8.fieldB;
    dst = (struct PackedBits021c6ebc*)((unsigned char*)(*(void**)((char*)combatant + 0x138)) + 0x22);
    dst->fieldB = b;
    unsigned char c = src->bits8.fieldC;
    dst = (struct PackedBits021c6ebc*)((unsigned char*)(*(void**)((char*)combatant + 0x138)) + 0x22);
    dst->fieldC = c;
    unsigned char st = src->bits8.state;
    func_02089114((struct Obj02088818*)(*(void**)((char*)combatant + 0x138)), st);
    *((unsigned char*)(*(void**)((char*)combatant + 0x138)) + 0x24) = src->fielda;
    *(unsigned short*)((unsigned char*)(*(void**)((char*)combatant + 0x138)) + 4) = src->fieldc;
    *(unsigned short*)((unsigned char*)(*(void**)((char*)combatant + 0x138)) + 6) = src->fielde;
}

#endif
