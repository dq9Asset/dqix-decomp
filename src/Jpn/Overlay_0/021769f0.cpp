#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02010684(GameState* battleStruct);
extern "C" void* func_02054fe4(unsigned char* obj);
extern "C" void* func_ov000_02162a84(void* obj, int id);

// JPN: func_ov000_021769f0
extern "C" ARM void func_ov000_021769f0(void* obj) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* field2a04 = (unsigned char*)func_02010684(battleStruct);
    unsigned char count = field2a04[0xf7c];
    unsigned char i;
    for (i = 0; i < count; i++) {
        signed char combIdx = *(signed char*)(field2a04 + i + 0xf00 + 0x78);
        GameObject* combatant = battleStruct->GetPartyMemberByIndex(combIdx);
        if (combatant == 0) {
            continue;
        }
        void* p = func_02054fe4((unsigned char*)combatant);
        signed char statusVal = (signed char)*(int*)((char*)p + 0x8b4);
        if (statusVal == 5) {
            continue;
        }
        char* entry = (char*)func_ov000_02162a84(obj, combIdx);
        if (entry) {
            signed char off = *(signed char*)(entry + 0x18);
            *(entry + off + 0x10) = 0x64;
        }
    }
}

#endif
