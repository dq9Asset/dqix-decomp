#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0205ce94
ARM void ResetGlobalObjAndInitSelfPointer0205ce94(MessageChoicePanel* panel) {
    MessageSystem* base = GetGlobalField0x1c020421a0();
    SetField0x1e20_02042b10(base, &panel->bounds);
    Foo02042fcc* q = base->controller.currentBounds;
    if (q != NULL) {
        q->state = 0;
    }
    InitSelfPointer_02042b1c(base);
}
