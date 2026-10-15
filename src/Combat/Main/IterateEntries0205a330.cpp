#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"

extern "C" void func_0205a254(Container0205a3d0*, int, int);

// USA: func_0205a330
ARM void IterateEntries0205a330(Container0205a3d0* c, int arg) {
    unsigned short i;
    for (i = 0; i < c->count; i++) {
        func_0205a254(c, i & 0xff, arg);
    }
}
