#include <globaldefs.h>
#include "Resource/MessageSystem.h"

int GetWordFromTable02042648(int idx);

// USA: func_0206b894
ARM int StoreDecodedDelta0206b894(const char* input, int* target, int c, int unusedMargin) {
    int val;
    func_020696bc(input, &val, 1);
    *target = val - (GetWordFromTable02042648(c) + 1);
    return 0;
}
