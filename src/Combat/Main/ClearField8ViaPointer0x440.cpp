#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_02043110
ARM void ClearField8ViaPointer0x440(MessageSlotController* s) {
    Foo02042fcc* t = s->currentBounds;
    if (t != 0) {
        t->state = 0;
    }
}
