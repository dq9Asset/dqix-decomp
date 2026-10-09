#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_02173348(int* obj);
extern "C" void* func_02054fe4(unsigned char* obj);

struct Entry021809e8 {
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

// JPN: func_ov000_021809e8  (semantic: FindReadyOrDefaultCombatantId_021809e8)
extern "C" ARM int func_ov000_021809e8(char* obj) {
    GameState* bs = GameState::GetInstance();
    struct Entry021809e8* entry;
    int i;
    for (i = 0; i < 4; i++) {
        signed char idx = *(signed char*)(obj + 0x6c + i);
        entry = (struct Entry021809e8*)(obj + 0x958) + idx;
        if (entry->field4c < 0) continue;
        if (entry->field87 == 0) continue;
        if (entry->field24 & 4) continue;
        signed char v = *(signed char*)((char*)entry + entry->field18 + 0x10);
        if (v == 0x64) continue;
        if (func_ov000_02173348((int*)entry)) continue;
        if (entry->field445 == 0) continue;
        GameObject* c = bs->GetPartyMemberByIndex(*(signed char*)(obj + 0x6c + i));
        if (c == 0 || (signed char)(*(int*)((char*)func_02054fe4((unsigned char*)c) + 0x8b4)) == 5) {
            return entry->field4c;
        }
    }
    return -1;
}

#endif
