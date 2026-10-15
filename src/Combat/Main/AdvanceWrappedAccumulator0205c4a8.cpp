#include <globaldefs.h>
#include "Resource/MessageSystem.h"
extern "C" void func_0205bb04(void*, int);

// USA: func_0205c4a8
ARM void AdvanceWrappedAccumulator0205c4a8(struct Struct_0205ba2c* s, int delta) {
    int base;
    s->page += delta;
    if (s->pages <= s->page) {
        s->page -= s->pages;
    } else if (s->page < 0) {
        s->page += s->pages;
    }
    base = s->count;
    if (base <= ComputeScaledSum0205bb84(s)) {
        func_0205bb04(s, base - 1);
    }
}
