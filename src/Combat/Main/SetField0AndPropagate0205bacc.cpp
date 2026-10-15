#include <globaldefs.h>
#include "Resource/MessageSystem.h"
extern "C" void func_0205bb04(void*, int);

// USA: func_0205bacc
ARM void SetField0AndPropagate0205bacc(struct Struct_0205ba2c* s, int val) {
    if (val < 0) return;
    s->count = val;
    if (ComputeScaledSum0205bb84(s) < val) return;
    func_0205bb04(s, val - 1);
}
