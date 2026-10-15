#include <globaldefs.h>
#include "Resource/MessageSystem.h"
int GetField0_0205bafc(void*);
extern "C" void func_0205bb04(Struct_0205ba2c*, int);
void SetIndexIfValid0205bcdc(Struct_0205bbcc*, int);

// USA: func_0205d7a0  (semantic: UpdateIndexPair0205d7a0)
extern "C" ARM void func_0205d7a0(Struct_0205c53c* obj, int val) {
    int cur;
    if (obj->field95) {
        cur = GetField0_0205bafc(&obj->second.base);
    } else if (obj->field94) {
        cur = GetField0_0205bafc(&obj->first.base);
    }
    if (val < 0) {
        if (cur <= val) return;
    }
    if (obj->field95) {
        func_0205bb04(&obj->second.base, val);
    }
    if (obj->field94 == 0) return;
    SetIndexIfValid0205bcdc(&obj->first, val);
}
