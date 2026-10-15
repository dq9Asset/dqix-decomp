#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0208beb4
ARM void SetFlag0x2IfByte0xd4Not3_0208beb4(MessageControlOwner* obj) {
    if (obj->state != 3) {
        obj->flags |= 2;
    }
}
