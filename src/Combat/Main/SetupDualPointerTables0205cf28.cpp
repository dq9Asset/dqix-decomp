#include <globaldefs.h>
#include "Resource/MessageSystem.h"
void SetupPointerTable0205ba68(Struct_0205ba2c*, int, int, int);
void SetField0AndPropagate0205bacc(Struct_0205ba2c*, int);

// USA: func_0205cf28
ARM void SetupDualPointerTables0205cf28(Struct_0205c53c* p, int a, int b, int c) {
    SetupPointerTable0205ba68(&p->first.base, a, b, c);
    SetupPointerTable0205ba68(&p->second.base, a, b, c);
    int prod = a * b;
    SetField0AndPropagate0205bacc(&p->first.base, prod);
    SetField0AndPropagate0205bacc(&p->second.base, prod);
}
