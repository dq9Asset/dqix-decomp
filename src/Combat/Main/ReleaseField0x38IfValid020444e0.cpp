#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_020444e0
ARM void ReleaseField0x38IfValid020444e0(MessageSystem* window) {
    MessageFrame* frame = window->frame;
    if (frame != NULL) {
        if (func_020e1f1c(frame) == 0) return;
        func_02066cf0(window, 0);
        func_020e23f4(window->frame);
        InvokeSubHandlerIfPresent_020e2478(window->frame);
    } else {
        func_02066cf0(window, 0);
    }
}
