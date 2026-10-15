#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0205cde8
ARM int CheckGlobalObjState2AndInit0205cde8(MessageChoicePanel* p) {
    MessageSystem* base = GetGlobalField0x1c020421a0();
    SetField0x1e20_02042b10(base, &p->bounds);
    int result = CheckField0x440State2_0205cd6c(&base->controller) != 0;
    InitSelfPointer_02042b1c(base);
    return result;
}
