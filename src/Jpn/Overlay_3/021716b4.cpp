#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj021716b4 {
    char unk_0[0xe8];
    unsigned char state_;
    unsigned char subState_;
};

typedef void (Obj021716b4::*StateFn021716b4)();

struct StateTable021716b4 {
    StateFn021716b4 functions[7];
};

extern "C" const StateTable021716b4 data_ov003_0217e2a4;
extern "C" const StateTable021716b4 data_ov003_0217e2dc;
extern "C" StateFn021716b4 data_020e7604;

// JPN: func_ov003_021716b4
extern "C" ARM bool func_ov003_021716b4(Obj021716b4* self) {
    GameState::GetInstance()->GetTickCount();
    bool done = false;
    bool subDone = false;
    StateTable021716b4 states = data_ov003_0217e2a4;
    StateFn021716b4 none = data_020e7604;
    states.functions[6] = none;
    StateTable021716b4 subStates = data_ov003_0217e2dc;
    subStates.functions[6] = none;
    if (states.functions[self->state_] != 0) {
        (self->*states.functions[self->state_])();
    } else {
        done = true;
    }
    if (subStates.functions[self->subState_] != 0) {
        (self->*subStates.functions[self->subState_])();
    } else {
        subDone = true;
    }
    if (done && subDone) {
        return false;
    }
    return true;
}

#endif
