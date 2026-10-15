#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"
#if defined(jpn)
#define func_02043224 func_02043998
#endif
void ReinitEightSubStructsAndAllocator_0202f1dc(MessageSlotController*);

extern "C" void func_02043224(MessageSystem* self);

// USA: func_02043000
ARM void InitControllerObject_02043000(MessageSystem* self) {
    ReinitEightSubStructsAndAllocator_0202f1dc(&self->controller);
    func_02043224(self);
    InitCombatSlots02043040(self);
    func_02043124(self);
    ResetControllerState020430b0(self);
    self->frame = 0;
}
