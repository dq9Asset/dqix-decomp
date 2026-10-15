#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0202f6d4
ARM void SetupField440Type3(MessageSlotController* obj) {
    if (obj->currentBounds == NULL) {
        return;
    }
    obj->currentBounds->field10 = 0x1000;
    obj->currentBounds->field14 = 0x1000;
    obj->currentBounds->state = 3;
}
