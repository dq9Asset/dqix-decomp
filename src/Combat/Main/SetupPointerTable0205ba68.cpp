#include <globaldefs.h>
#include "Resource/MessageSystem.h"


// USA: func_0205ba68
ARM void SetupPointerTable0205ba68(struct Struct_0205ba2c* s, int a, int b, int mode) {
    s->columns = a;
    s->rows = b;
    s->orientation = mode;
    if (mode == 0) {
        s->primaryDimension = &s->columns;
        s->secondaryDimension = &s->rows;
        s->primaryCursor = &s->column;
        s->secondaryCursor = &s->row;
    } else if (mode == 1) {
        s->primaryDimension = &s->rows;
        s->secondaryDimension = &s->columns;
        s->primaryCursor = &s->row;
        s->secondaryCursor = &s->column;
    }
}
