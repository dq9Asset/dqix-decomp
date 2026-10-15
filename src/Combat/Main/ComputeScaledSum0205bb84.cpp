#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0205bb84
ARM int ComputeScaledSum0205bb84(struct Struct_0205ba2c* s) {
    int p = *s->secondaryDimension * *s->primaryCursor + *s->secondaryCursor;
    int q = s->page * s->rows * s->columns;
    return (short)q + (short)p;
}
