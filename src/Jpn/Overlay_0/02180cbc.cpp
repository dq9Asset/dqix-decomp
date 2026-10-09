#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void* func_02010684(GameState*);

extern "C" int func_ov000_02173348(int* obj);
extern "C" void* func_02054fe4(unsigned char* obj);
extern "C" ARM void* func_ov000_02162a84(void* obj, int id);

struct Entry02180cbc {
    char pad0[0x18];
    signed char field18;
    char pad2[0x24 - 0x19];
    unsigned char field24;
    char pad3[0x4c - 0x25];
    int field4c;
    char pad4[0xc7 - 0x50];
    unsigned char field87;
    char pad5[0x485 - 0xc8];
    unsigned char field445;
    char pad6[0x488 - 0x486];
};

// JPN: func_ov000_02180cbc  (semantic: FindAndMarkReadyCombatant_02180cbc)
extern "C" ARM int func_ov000_02180cbc(char* obj) {
    GameState* bs = GameState::GetInstance();
    unsigned char* field2a04 = (unsigned char*)func_02010684(bs);
    unsigned char limit = field2a04[0xf7c];
    int result = 0;
    unsigned char i;
    for (i = 0; i < limit; i++) {
        signed char idx = *(signed char*)(obj + i + 0x70);
        struct Entry02180cbc* entry = (struct Entry02180cbc*)func_ov000_02162a84(obj, idx);
        if (entry == 0) continue;
        if (entry->field4c < 0) continue;
        if (entry->field87 == 0) continue;
        signed char v = *(signed char*)((char*)entry + entry->field18 + 0x10);
        if (v == 0x64) continue;
        if (func_ov000_02173348((int*)entry)) continue;
        if (entry->field445 == 0) continue;
        GameObject* c = bs->GetPartyMemberByIndex(idx);
        if (c != 0 && (signed char)(*(int*)((char*)func_02054fe4((unsigned char*)c) + 0x8b4)) != 5) continue;
        *(int*)(obj + 0x17c) = idx;
        result = 1;
        break;
    }
    return result;
}

#endif
