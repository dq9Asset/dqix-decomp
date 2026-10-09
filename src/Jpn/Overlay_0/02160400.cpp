#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_0200fee4(struct S_10088* obj);
extern "C" int func_ov000_0215538c(GameObject* combatant);

struct CombatGroup_02160400 {
    unsigned short field_0x0;
    unsigned char ids[8];
    unsigned char total : 4;
    unsigned char matched : 4;
    unsigned char pad[0x18 - 0xb];
};

struct Battle_02160400 {
    unsigned char pad[0x81b4];
    struct CombatGroup_02160400 groups[1];
};

// JPN: func_ov000_02160400
extern "C" ARM int func_ov000_02160400(struct Battle_02160400* obj, short* out, int maxCount, int groupIdx, int flags) {
    int count = 0;
    int i;
    for (i = 0; i < obj->groups[groupIdx].total; i++) {
        short id = (short)(obj->groups[groupIdx].ids[i] + 0xc0);
        GameObject* c = GameState::GetInstance()->GetCombatantByIndex(id);
        if (c == NULL) continue;
        if (func_ov000_0215538c(c)) continue;
        if ((flags & 1) && func_0200fee4((struct S_10088*)c)) continue;
        out[count++] = id;
        if (count == maxCount) return count;
    }
    return count;
}

#endif
