#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_0200fee4(struct S_10088* obj);
extern "C" int func_ov000_0215538c(GameObject* combatant);
extern "C" int func_ov000_021577b8(GameObject* combatant);
extern "C" int func_02088bf4(unsigned char* obj);
extern "C" int func_ov000_021577d0(GameObject* combatant);
extern "C" int func_ov000_02155b74(GameObject* combatant);

// JPN: func_ov000_0215771c  (semantic: IsCombatantIneligible_02155f9c)
extern "C" ARM int func_ov000_0215771c(void* unused, int combatantId, int checkSubFlag) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(combatantId);
    if (c == 0) {
        return 1;
    }
    if (func_0200fee4((struct S_10088*)c) ||
        func_ov000_0215538c(c) ||
        func_ov000_021577b8(c) ||
        func_02088bf4((unsigned char*)c->currentStats_) ||
        func_ov000_021577d0(c)) {
        return 1;
    }
    if (checkSubFlag != 0 && func_ov000_02155b74(c)) {
        return 1;
    }
    return 0;
}

#endif
