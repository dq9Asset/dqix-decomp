#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern "C" void func_0202f45c(MessageSlotController*, int, int, int, int, int, int);

// USA: func_0202f404
ARM void EmitScaledField0x440_0202f404(MessageSlotController* obj, int a, int b) {
    Foo02042fcc* s = obj->currentBounds;
    if (s != NULL && s->state != 0) {
        func_0202f45c(obj, s->x << 12, s->y << 12,
                      s->width * s->field10, s->height * s->field14, a, b);
    }
}
