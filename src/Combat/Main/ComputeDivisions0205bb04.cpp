#include <globaldefs.h>
#include "Resource/MessageSystem.h"


// USA: func_0205bb04  (semantic: ComputeDivisions0205bb04)
extern "C" ARM void func_0205bb04(struct Struct_0205ba2c* self, int value) {
    if (value < 0) return;
    if (value >= self->count) return;
    int product = self->rows * self->columns;
    if (product == 0) return;
    self->page = value / product;
    value = value % product;
    *self->secondaryCursor = value % *self->secondaryDimension;
    *self->primaryCursor = value / *self->secondaryDimension;
}
