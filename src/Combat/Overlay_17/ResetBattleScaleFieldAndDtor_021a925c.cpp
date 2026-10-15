#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"

extern void EmptyDestructor0205cb60(void* obj);

// USA: func_ov017_021a925c
ARM void ResetBattleScaleFieldAndDtor_021a925c(char* self) {
    GameState* battleStruct = GameState::GetInstance();
    MessageSystem* obj = GetGlobalField0x1c020421a0();
    int count = battleStruct->GetTickCount();
    Forward0204359c(obj, count);
    func_020439b0(obj, 0);
    EmptyDestructor0205cb60(self + 0x2c);
}
