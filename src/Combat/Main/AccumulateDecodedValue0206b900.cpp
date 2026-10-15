#include <globaldefs.h>
#include "Resource/MessageSystem.h"


// USA: func_0206b900
ARM int AccumulateDecodedValue0206b900(const char* input, int* target, int unusedFont, int unusedMargin) {
    int val;
    func_020696bc(input, &val, 1);
    *target = *target + val;
    return 0;
}
