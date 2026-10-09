#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200fd00(GameState* battleStruct, int combatantId);

// JPN: func_ov000_02164c90
extern "C" ARM short func_ov000_02164c90(int id, float a, float b) {
    GameState* bs = GameState::GetInstance();
    int inRange = (id >= 0xc0 && id <= 0xc7);
    if (!(inRange && bs != NULL)) {
        return 0x10a;
    }
    GameObject* c = func_0200fd00(bs, id);
    if (c == NULL) {
        return 0x10a;
    }
    short baseline = *(short*)((char*)c + 0x100 + 0x8e);
    int lo = (int)(a * 4096.0f);
    if (baseline <= lo) {
        return baseline;
    }
    int hi = (int)(b * 4096.0f);
    int delta = baseline - lo;
    int rounded = (int)(((long long)delta * hi + 0x800) >> 12);
    return (short)(lo + rounded);
}

#endif
