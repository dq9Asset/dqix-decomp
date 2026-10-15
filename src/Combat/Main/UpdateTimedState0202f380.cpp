#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0202f380
ARM void UpdateTimedState0202f380(MessageSlotController* controller, int amount) {
    Foo02042fcc* bounds = controller->currentBounds;
    if (amount == 0) amount = 1;
    if (bounds == 0) return;
    switch (bounds->state) {
    case 1:
        bounds->state = 2;
        controller->currentBounds->field14 = 0x1000;
        break;
    case 3:
        bounds->field14 -= amount * 0x199;
        if (controller->currentBounds->field14 <= 0) {
            controller->currentBounds->state = 0;
            controller->currentBounds->field14 = 0;
        }
        break;
    case 0:
    case 2:
    default:
        return;
    }
}
