#include <globaldefs.h>
#include "Resource/MessageFrame.h"


// USA: func_020e1568
ARM void ClearZeroStruct_020e1568(struct ZeroStruct* s) {
    s->attributes = 0;
    s->offset = 0;
    s->y = 0;
    s->x = 0;
    s->height = 0;
    s->width = 0;
}
