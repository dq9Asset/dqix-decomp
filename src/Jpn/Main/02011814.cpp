#if defined(jpn)
#include <globaldefs.h>

struct GameStateRecord {
    unsigned char data[32];
};

struct GameStateRecords {
    unsigned char unknown0[0x621e];
    GameStateRecord records[4];
};

// JPN: func_02011814
extern "C" ARM GameStateRecord* func_02011814(GameStateRecords* state, unsigned int index)
{
    GameStateRecord* result = NULL;
    if (index <= 3)
        result = &state->records[index];
    return result;
}

#endif

