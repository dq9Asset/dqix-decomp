#include <globaldefs.h>

#if defined(jpn)
#include "Resource/Script.h"
#include "Resource/MessageSystem.h"

// JPN: func_020428c4
extern "C" ARM int func_020428c4(Script::Parameter* parameters, int) {
    int* values = data_02107800.scriptState;
    for (int index = 0; index < 10; index++) {
        values[index] = parameters->ToInt();
        parameters++;
    }
    return 1;
}
#endif
