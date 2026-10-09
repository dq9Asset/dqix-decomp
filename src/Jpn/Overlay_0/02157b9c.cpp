#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* func_0200fd78(GameState*,int);

struct CombatantExtra02157b9c {
    char unk_0[0xc];
    unsigned int charmBonus : 10;
};

struct Combatant02157b9c {
    char unk_0[0x134];
    BaseCombatStats* baseStats;
    ModifiableCombatStats* currentStats;
    char unk_13c[0x144 - 0x13c];
    CombatantExtra02157b9c* extra;

    unsigned short GetCurrentCharm() {
        unsigned short charm = currentStats->primaryStats.charm;
        return charm;
    }
    unsigned short GetBaseCharm() {
        unsigned short charm = baseStats->primaryStats.charm;
        return charm;
    }
};

// JPN: func_ov000_02157b9c
extern "C" ARM float func_ov000_02157b9c(int unused, int id) {
    GameState* gs = GameState::GetInstance();
    float result = 0.0f;
    int valid = (id >= 0 && id <= 3);
    if (valid) {
        Combatant02157b9c* c = (Combatant02157b9c*)func_0200fd78(gs, id);
        if (c == NULL) {
            return 0.0f;
        }
        int charm = c->GetCurrentCharm() - c->GetBaseCharm();
        charm += (unsigned short)c->extra->charmBonus;
        result = (charm - 100) * 0.02f;
    }
    return result;
}

#endif
