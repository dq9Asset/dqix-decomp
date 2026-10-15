#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"



struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);

// USA: func_ov003_02170280  (semantic: UpdateScaleAndInit_02170280)
extern "C" ARM void func_ov003_02170280(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    GameState* battleStruct;
    MessageSystem* g;
    unsigned int scaleCount;
    if (*(int*)(o + 0x3c) == 0) {
        return;
    }
    if (*(signed char*)(o + 1) <= 1) {
        return;
    }
    battleStruct = GameState::GetInstance();
    g = GetGlobalField0x1c020421a0();
    scaleCount = battleStruct->GetTickCount();
    Forward0204359c(g, scaleCount);
    func_020439b0(g, 0);
    if (*(int*)(o + 0x3c) == 0) {
        return;
    }
    InitEntries0205d2bc((struct Obj0205d2bc*)*(int*)(o + 0x3c));
}
