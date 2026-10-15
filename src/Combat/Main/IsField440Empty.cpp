#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0205ce28
ARM int IsField440Empty_0205ce28(MessageSlotController* controller) {
    Foo02042fcc* bounds = controller->currentBounds;
    if (bounds != 0) {
        return bounds->state == 0;
    }
    return 1;
}
