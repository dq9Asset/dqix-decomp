#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020a5358(unsigned char* obj, unsigned int index);
extern "C" void func_0204ab8c(GameObject* combatant);
extern "C" void func_0204a904(unsigned char* obj);

// JPN: func_ov000_021695a8
extern "C" ARM void func_ov000_021695a8(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        if (func_020a5358(*(unsigned char**)(obj + 0x21c), (unsigned char)i)) {
            GameObject* c = battle->GetCombatantByIndex(i);
            if (c) {
                func_0204ab8c(c);
                func_0204a904((unsigned char*)c);
            }
        }
    }
    for (int i = 0xc0; i < 0xc8; i++) {
        GameObject* c = battle->GetCombatantByIndex(i);
        if (c) {
            func_0204ab8c(c);
            func_0204a904((unsigned char*)c);
        }
    }
    unsigned char b = *(unsigned char*)(obj + 0x5000 + 0xb41);
    b = (b & ~3) | 1;
    *(unsigned char*)(obj + 0x5000 + 0xb41) = b;
}

#endif
