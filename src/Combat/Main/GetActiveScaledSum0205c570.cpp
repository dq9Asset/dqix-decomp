#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0205c570
ARM int GetActiveScaledSum0205c570(struct Struct_0205c53c* s) {
    int result = -1;
    if (s->field94 != 0 && s->first.field4c != 0) {
        result = GetScaledSumIfActive0205bd04(&s->first);
    }
    if (s->field95 == 0) {
        return result;
    }
    return ComputeScaledSum0205bb84(&s->second.base);
}
