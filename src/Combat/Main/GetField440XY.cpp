#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_02066cc0
ARM void GetField440XY_02066cc0(MessageSlotController* controller, short* x, short* y) {
    if (controller->currentBounds != NULL) {
        *x = controller->currentBounds->x;
        *y = controller->currentBounds->y;
    }
}
