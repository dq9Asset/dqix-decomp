#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern const signed char data_020e7e10[];
extern const signed char data_020e7e1c[];

// USA: func_0206b804
ARM void LoadStateBytePair0206b804(MessageSystem* obj, int* out1, int* out2) {
    *out2 = 0;
    *out1 = 0;
    if (obj->b19c0 != 0) {
        int idx;
        obj->b19cd = 1;
        obj->stream40 = 0;
        idx = obj->b195d & 3;
        *out1 = data_020e7e10[idx];
        *out2 = data_020e7e1c[idx];
    }
}
