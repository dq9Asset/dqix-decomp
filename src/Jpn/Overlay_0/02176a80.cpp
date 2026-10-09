#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void* func_02010684(GameState*);

extern "C" void* func_ov000_02162a84(void* obj, int idx);

extern "C" int func_02054fe4(unsigned char* obj);
extern "C" int func_ov000_02173348(int* obj);

// JPN: func_ov000_02176a80  (semantic: NotifyEligibleCombatants_02176a80)
extern "C" ARM void func_ov000_02176a80(void* obj) {
    GameState* bs = GameState::GetInstance();
    unsigned char* p2a04 = (unsigned char*)func_02010684(bs);
    unsigned char count = p2a04[0xf7c];
    unsigned char i;
    for (i = 0; i < count; i++) {
        signed char combatantId = *((signed char*)p2a04 + i + 0xf00 + 0x78);
        GameObject* c = bs->GetPartyMemberByIndex(combatantId);
        if (c == 0) {
            continue;
        }
        int ptrVal = func_02054fe4((unsigned char*)c);
        int val = *(int*)(ptrVal + 0x8b4);
        signed char statusByte = (signed char)val;
        if (statusByte == 5) {
            continue;
        }
        void* e = func_ov000_02162a84(obj, combatantId);
        if (e == 0) {
            continue;
        }
        if (func_ov000_02173348((int*)e) == 0) {
            signed char off = *((signed char*)e + 0x18);
            unsigned char* p = (unsigned char*)e + off;
            p[0x10] = 0xd;
        }
    }
}

#endif
