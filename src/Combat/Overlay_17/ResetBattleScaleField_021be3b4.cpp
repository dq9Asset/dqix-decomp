#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"


// USA: func_ov017_021be3b4
ARM void ResetBattleScaleField_021be3b4(void*) {
    GameState* battleStruct = GameState::GetInstance();
    MessageSystem* obj = GetGlobalField0x1c020421a0();
    int count = battleStruct->GetTickCount();
    Forward0204359c(obj, count);
    func_020439b0(obj, 0);
}
