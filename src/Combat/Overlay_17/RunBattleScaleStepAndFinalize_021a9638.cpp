#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"


// USA: func_ov017_021a9638
ARM void RunBattleScaleStepAndFinalize_021a9638(void*) {
	GameState* b = GameState::GetInstance();
	MessageSystem* x = GetGlobalField0x1c020421a0();
	unsigned int y = b->GetTickCount();
	Forward0204359c(x, y);
	func_020439b0(x, 0);
}
