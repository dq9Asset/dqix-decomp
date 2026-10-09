#if defined(jpn)
#include <globaldefs.h>

extern "C" void* VectorizedMemset(void* destination, int value, unsigned int size);

struct GameStateRecordsToClear {
    unsigned char unknown0[0x621e];
    unsigned char records[0x80];
};

// JPN: func_02011830
extern "C" ARM void func_02011830(GameStateRecordsToClear* state)
{
    VectorizedMemset(state->records, 0, sizeof(state->records));
}

#endif

