#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct Obj02049b54;
extern "C" int func_ov000_0216029c(void* p0, short* ids, int count, int flag);
extern "C" Vector3i func_0204a974(struct Obj02049b54* obj);

struct CombatantIdList_0215e520 { short ids[8]; };
extern struct CombatantIdList_0215e520 data_ov000_02183cec;

// JPN: func_ov000_0215e520
extern "C" ARM int func_ov000_0215e520(void* p0) {
    struct CombatantIdList_0215e520 list = data_ov000_02183cec;
    int result = -1;
    int count = func_ov000_0216029c(p0, list.ids, 8, 1);
    Vector3i best;
    for (int i = 0; i < count; i++) {
        short id = list.ids[i];
        GameState* gs = GameState::GetInstance();
        GameObject* c = gs->GetCombatantByIndex(id);
        if (c != NULL) {
            Vector3i pos = func_0204a974((struct Obj02049b54*)c);
            if (result > 0) {
                if (pos.x < best.x) {
                    best = pos;
                    result = list.ids[i];
                }
            } else {
                result = list.ids[i];
                best = pos;
            }
        }
    }
    return result;
}

#endif
