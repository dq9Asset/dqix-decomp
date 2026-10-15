#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0208be94
ARM void ClearField0xd0AndSetFlag0x1IfByte0xd4Not2_0208be94(MessageControlOwner* obj) {
    if (obj->state != 2) {
        obj->timer = 0;
        obj->flags |= 1;
    }
}
