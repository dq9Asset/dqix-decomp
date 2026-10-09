#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* func_0200fd78(GameState*, int);

extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* member, int arg3);
extern char data_ov000_02184a1f[];

// JPN: func_ov000_0216508c
// Counts down the four pending battle-actor animation timers.
// An expired timer plays the animation named "start" and releases its timer slot.
extern "C" ARM void TickBattleAnimationTimers(char* battleView) {
    GameState* gameState = GameState::GetInstance();
    int timerSlot;
    for (timerSlot = 0; timerSlot < 4; timerSlot++) {
        signed char actorId = *(signed char*)(battleView + 0x792c + timerSlot);
        if (actorId < 0) continue;
        int framesRemaining = *(unsigned char*)(battleView + 0x7930 + timerSlot);
        framesRemaining--;
        if (framesRemaining <= 0) {
            *(signed char*)(battleView + 0x792c + timerSlot) = -1;
            GameObject* actor = func_0200fd78(gameState, actorId);
            if (actor != 0) {
                _ZN8Object3D24MaybeSetRegularAnimationEPKci(actor, data_ov000_02184a1f, 1);
            }
        } else {
            *(unsigned char*)(battleView + 0x7930 + timerSlot) = framesRemaining;
        }
    }
}

#endif
