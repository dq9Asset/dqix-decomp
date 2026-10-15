#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0205ce50
ARM void SetupGlobalObjType3AndInitSelfPointer_0205ce50(MessageChoicePanel* arg0) {
    MessageChoicePanel* self = arg0;
    MessageSystem* global = GetGlobalField0x1c020421a0();
    SetField0x1e20_02042b10(global, &self->bounds);
    if (IsField440Empty_0205ce28(&global->controller) == 0) {
        SetupField440Type3(&global->controller);
    }
    InitSelfPointer_02042b1c(global);
}
