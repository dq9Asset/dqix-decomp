#include <globaldefs.h>
#include "Resource/MessageSystem.h"
int CheckGlobalObjState2AndInit0205cde8(MessageChoicePanel*);
extern "C" int func_0205c5b0(Struct_0205c53c*, unsigned int);

// USA: func_0205c904
// KEEP-NAME
ARM void SetupAndDispatch0205c904(MessageChoicePanel* obj, int flag) {
    if (obj->showBounds == 0) {
        return;
    }

    if (obj->enabled == 0) {
        return;
    }

    MessageSystem* ctx = GetGlobalField0x1c020421a0();
    SetField0x1e20_02042b10(ctx, &obj->bounds);
    UpdateTimedState0202f380(&ctx->controller, flag);
    InitSelfPointer_02042b1c(ctx);

    if (CheckGlobalObjState2AndInit0205cde8(obj) == 0) {
        return;
    }

    func_0205c5b0(&obj->channels, flag);
}
