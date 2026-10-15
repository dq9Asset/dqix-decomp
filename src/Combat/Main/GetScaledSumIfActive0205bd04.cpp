#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0205bd04
ARM int GetScaledSumIfActive0205bd04(struct Struct_0205bbcc* s) {
    if (s->field4e == 0) return -1;
    return ComputeScaledSum0205bb84(&s->base);
}
