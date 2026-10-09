#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200fd00(GameState* battleStruct, int combatantId);

struct Inner021577e8 {
    char pad[0xa];
    unsigned short lowBits : 7;
    unsigned short nibble : 4;
    unsigned short bit11 : 1;
    unsigned short bit12 : 1;
    unsigned short rest : 3;
};

// JPN: func_ov000_021577e8  (semantic: CheckCombatantFlagBit_021577e8)
extern "C" ARM int func_ov000_021577e8(int unused0, int id, int a2, int a3) {
    int flag = (id >= 0 && id <= 3);
    if (flag) {
        return 0;
    }
    GameState* bs = GameState::GetInstance();
    GameObject* c = func_0200fd00(bs, id);
    if (c == NULL) {
        return 0;
    }
    struct Inner021577e8* inner = *(struct Inner021577e8**)((char*)c + 0x144);
    if (inner == NULL) {
        return 0;
    }
    if (a3 > 0) {
        if (a3 == 1) {
            if (inner->bit12) return 1;
        } else {
            if (inner->bit11) return 1;
        }
    } else {
        if (inner->nibble == a2) return 1;
    }
    return 0;
}

#endif
