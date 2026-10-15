#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0202f6a4
ARM void SetupField440Type1(MessageSlotController* obj) {
    if (obj->currentBounds == 0) {
        return;
    }
    obj->currentBounds->field10 = 0x1000;
    obj->currentBounds->field14 = 0;
    obj->currentBounds->state = 1;
}
