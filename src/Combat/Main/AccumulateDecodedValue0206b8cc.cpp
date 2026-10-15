#include <globaldefs.h>
#include "Resource/MessageSystem.h"


// USA: func_0206b8cc
ARM int AccumulateDecodedValue0206b8cc(const char* input, int* target, int unusedFont, int unusedMargin) {
    int val;
    func_020696bc(input, &val, 1);
    *target = *target + val;
    return 0;
}
