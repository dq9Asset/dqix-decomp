#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/BattleSkillEligibility.h"
extern "C" int func_02011560(GameState*);
#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" GameObject* func_0200fd00(GameState* gameState, int combatantId);
extern "C" void* func_ov000_02154ed8(void* obj, int idx);
extern "C" char* func_02012dac(void);

struct MonsterEntry_0215b53c {
    char pad0[0xa];
    unsigned short level : 7;
};

struct PartyWork_0215b53c {
    char pad[0x25];
    unsigned char field_0x25;
};

// JPN: func_ov000_0215b53c
extern "C" ARM int func_ov000_0215b53c(char* battle, int combatantId) {
    GameState* gs = GameState::GetInstance();
    GameObject* combatant = func_0200fd00(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return 1;
    }
    struct MonsterEntry_0215b53c* entry =
        (struct MonsterEntry_0215b53c*)func_ov000_02154ed8(battle, combatantId);
    if (entry == 0) {
        return 1;
    }
    char* zone = func_02012dac();
    if (func_02011560(gs) && (*(struct PartyWork_0215b53c**)(battle + 0x8e18))->field_0x25 != 0) {
        DetailedTreasureMapData* detail = ((ActiveGrottoClass*)(zone + 0x240c))->GetDetailedData();
        short monsterId = combatant->obj3D_.unknown_2_;
        unsigned short alt = detail->legacy_.MaybeGetCurrentAlternateID();
        if (alt == monsterId) {
            return detail->legacy_.level_;
        }
    }
    return entry->level;
}

#endif
