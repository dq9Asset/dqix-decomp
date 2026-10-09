#if defined(jpn)
#include <globaldefs.h>

struct GameStateByteLookup {
    unsigned char unknown0[0x54bd];
    signed char values[4];
    unsigned char count;
};

// JPN: func_02011288
extern "C" ARM int func_02011288(const GameStateByteLookup* state, unsigned int index)
{
    return index < state->count ? state->values[index] : -1;
}

#endif

