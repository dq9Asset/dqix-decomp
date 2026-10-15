#include <globaldefs.h>
#include "Resource/MessageFrame.h"

// USA: func_020e1cb8
ARM void ClearFlag0x1SetFlag0x2_020e1cb8(MessageFrame* frame) {
    frame->panel->flag0 = 0;
    frame->panel->flag1 = 1;
}
