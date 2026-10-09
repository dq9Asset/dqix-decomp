#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* func_0200fd78(GameState*, int);

extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* member, int arg3);
extern char data_ov000_02184a1f[];

// JPN: func_ov000_0216508c  (semantic: TickTimers0216508c)
extern "C" ARM void func_ov000_0216508c(char* obj) {
    GameState* battle = GameState::GetInstance();
    int i;
    for (i = 0; i < 4; i++) {
        signed char timerId = *(signed char*)(obj + 0x792c + i);
        if (timerId < 0) continue;
        int counter = *(unsigned char*)(obj + 0x7930 + i);
        counter--;
        if (counter <= 0) {
            *(signed char*)(obj + 0x792c + i) = -1;
            GameObject* c = func_0200fd78(battle, timerId);
            if (c != 0) {
                _ZN8Object3D24MaybeSetRegularAnimationEPKci(c, data_ov000_02184a1f, 1);
            }
        } else {
            *(unsigned char*)(obj + 0x7930 + i) = counter;
        }
    }
}

#endif
