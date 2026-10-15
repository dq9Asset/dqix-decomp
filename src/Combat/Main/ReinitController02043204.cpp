#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

// USA: func_02043204
ARM void ReinitController02043204(MessageSystem* window) {
    InitCombatSlots02043040(window);
    func_02043124(window);
    ResetControllerState020430b0(window);
}
