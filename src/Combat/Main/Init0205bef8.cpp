#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0205bef8
ARM void Init0205bef8(struct Struct_0205bef8* s) {
    InitStruct_0205ba2c(&s->base);
    s->step = 0;
    s->key = 0;
    s->rowRepeat = 0;
    s->columnRepeat = 0;
    s->countdown = 0;
    s->initialDelay = 0x14;
    s->repeatDelay = 0xa;
    s->wrapColumns = 1;
    s->wrapRows = 1;
}
