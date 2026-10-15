#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0205cd6c
ARM int CheckField0x440State2_0205cd6c(MessageSlotController* obj) {
    Foo02042fcc* bounds = obj->currentBounds;
    if (bounds != NULL) {
        return bounds->state == 2;
    }
    return 0;
}
