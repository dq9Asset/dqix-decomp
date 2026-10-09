#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" GameObject* func_0200fd78(GameState* battleStruct, int combatantId);
extern "C" int func_0208440c(unsigned char* obj, int index);
extern unsigned char data_ov000_02183b7d[];

struct Field150_02157c4c {
    char pad[0x8b8];
    int idx;
};

// JPN: func_ov000_02157c4c
extern "C" ARM int func_ov000_02157c4c(struct Random* rand, int id) {
    GameState* bs = GameState::GetInstance();
    int inRange = (id >= 0 && id <= 3);
    if (!inRange) return 0;
    GameObject* combatant = func_0200fd78(bs, id);
    if (combatant == NULL) return 0;
    unsigned char* field150 = *(unsigned char**)((char*)combatant + 0x144);
    if (!func_0208440c(field150, 0xd0)) return 0;
    struct Field150_02157c4c* field150b = *(struct Field150_02157c4c**)((char*)combatant + 0x144);
    int idx = field150b->idx;
    int tableVal = data_ov000_02183b7d[idx];
    int pick = NextRandomMax(rand, tableVal);
    return (pick == 1);
}

#endif
