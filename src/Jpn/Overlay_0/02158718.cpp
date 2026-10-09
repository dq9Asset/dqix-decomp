#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215771c(struct Random* rand, int combatantId, int zero);
extern "C" float func_ov000_021579f0(struct Random* rand, int combatantId);
extern "C" int func_ov000_02157b84(GameObject* combatant);

struct FlagsObj02158718 {
    char pad[0x10];
    unsigned int field10;
};

// JPN: func_ov000_02158718  (semantic: RollActionChance_02158718)
extern "C" ARM int func_ov000_02158718(struct Random* rand, int combatantId, struct FlagsObj02158718* flagsObj) {
    GameState::GetInstance();
    if (!(flagsObj->field10 & 0x20)) {
        return 0;
    }
    if (func_ov000_0215771c(rand, combatantId, 0) != 0) {
        return 0;
    }
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetCombatantByIndex(combatantId);
    if (combatant == 0) {
        return 0;
    }
    if (func_ov000_02157b84(combatant)) {
        short val = *(short*)((char*)rand + 0x8e00 + 0x6e);
        return val < 0x32;
    }
    float chance = func_ov000_021579f0(rand, combatantId);
    int roll = NextRandomMax(rand, 100);
    return roll < (int)chance;
}

#endif
