#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020a5358(unsigned char* obj, unsigned int index);
extern "C" void func_0204ac20(void);

// JPN: func_ov000_02169514
extern "C" ARM void func_ov000_02169514(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        if (func_020a5358(*(unsigned char**)(obj + 0x21c), (unsigned char)i)) {
            if (battle->GetCombatantByIndex(i)) func_0204ac20();
        }
    }
    for (int i = 0xc0; i < 0xc8; i++) {
        if (battle->GetCombatantByIndex(i)) func_0204ac20();
    }
    unsigned char b = *(unsigned char*)(obj + 0x5000 + 0xb41);
    b = (b & ~3) | 2;
    *(unsigned char*)(obj + 0x5000 + 0xb41) = b;
}

#endif
