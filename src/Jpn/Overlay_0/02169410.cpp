#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_0200f9e8(int* obj);
extern "C" int func_ov000_0216029c(struct Random* rand, short* buf, int count, int flag);
extern "C" int func_0204a1c4(unsigned char* obj);
extern "C" void func_0204a1b0(unsigned char* obj, unsigned char value);
extern "C" void func_0204a9f4(unsigned char* obj, int* src);
extern "C" void func_0204aa80(unsigned char* obj, int* src);
extern "C" void __clear(void* dst, int count);

struct BattleGridPosition { int x; int y; };
extern "C" struct BattleGridPosition func_ov000_02170e78(int* in);

extern unsigned char data_ov000_021841c4[][8];
struct BattleFormationVector { unsigned int v[3]; };
extern struct BattleFormationVector data_ov000_02184178;

// JPN: func_ov000_02169410
// Assigns combatants their count-dependent positions on the staggered battle grid.
// An existing per-combatant cell overrides the default formation table.
extern "C" ARM void AssignBattleGridFormation(unsigned char* battleView) {
    GameState* gameState = GameState::GetInstance();
    func_0200f9e8((int*)gameState);
    struct Random* battleState = *(struct Random**)(battleView + 0x218);
    short combatantIds[8];
    int count = func_ov000_0216029c(battleState, combatantIds, 8, 0);
    int combatantIndex = 0;
    while (combatantIndex < count) {
        GameObject* combatant = gameState->GetCombatantByIndex(combatantIds[combatantIndex]);
        if (combatant != 0) {
            int gridCell = data_ov000_021841c4[count - 1][combatantIndex];
            if (func_0204a1c4((unsigned char*)combatant) != 0xff) {
                gridCell = func_0204a1c4((unsigned char*)combatant);
            }
            struct BattleGridPosition gridPosition = func_ov000_02170e78(&gridCell);
            struct BattleFormationVector formationPosition = data_ov000_02184178;
            formationPosition.v[0] = gridPosition.x;
            formationPosition.v[2] = gridPosition.y;
            int zeroOffset[3];
            __clear(zeroOffset, 0xc);
            func_0204a1b0((unsigned char*)combatant, (unsigned char)(gridCell & 0xff));
            func_0204a9f4((unsigned char*)combatant, (int*)&formationPosition);
            func_0204aa80((unsigned char*)combatant, zeroOffset);
        }
        combatantIndex++;
    }
}

#endif
