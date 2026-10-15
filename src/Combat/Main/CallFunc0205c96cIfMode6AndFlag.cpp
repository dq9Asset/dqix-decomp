#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_02044530
ARM void CallFunc0205c96cIfMode6AndFlag_02044530(MessageSystem* base, int arg) {
    if (base->mode != 6) return;
    if (base->choiceEnabled == 0) return;
    func_0205c96c(&base->choicePanel, arg);
}
