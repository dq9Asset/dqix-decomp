#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_021613e0(char* base);
extern "C" int func_ov000_0215771c(struct Random* rand, int combatantId, int checkSubFlag);
extern "C" GameObject* func_0200fd78(GameState* battleStruct, int combatantId);
extern "C" int func_ov000_02157b84(GameObject* combatant);
extern "C" int func_0208440c(unsigned char* obj, int index);
int NextRandomMax(struct Random* random, int maximum);

extern unsigned char data_ov000_02183b70[];

// JPN: func_ov000_02157cd8  (semantic: RollHitOrEvasionChance_02157cd8)
extern "C" ARM int func_ov000_02157cd8(struct Random* rand, int combatantId) {
    if (func_ov000_021613e0((char*)rand) != 0) {
        return 0;
    }

    GameState* bs = GameState::GetInstance();
    int inRange = (combatantId >= 0 && combatantId <= 3) ? 1 : 0;
    if (!inRange) {
        return 0;
    }

    if (func_ov000_0215771c(rand, combatantId, 0) != 0) {
        return 0;
    }

    GameObject* c = func_0200fd78(bs, combatantId);
    if (c == 0) {
        return 0;
    }

    if (func_ov000_02157b84(c)) {
        short val = *(short*)((char*)rand + 0x8e00 + 0x6e);
        if (val >= 0x32) {
            if (val < 0x4b) return 1;
        }
        return 0;
    }

    if (func_0208440c(*(unsigned char**)((char*)c + 0x144), 0x36) == 0) {
        return 0;
    }

    int idx = *(int*)((char*)(*(void**)((char*)c + 0x144)) + 0x8b8);
    int maxVal = data_ov000_02183b70[idx];
    return NextRandomMax(rand, maxVal) == 1;
}

#endif
