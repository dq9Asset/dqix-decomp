#include <globaldefs.h>

#if defined(jpn)
#include "Resource/Script.h"

struct FontScriptState {
    int* values;
};

extern FontScriptState data_02107800;

// JPN: func_020428c4
extern "C" ARM int func_020428c4(Script::Parameter* parameters, int) {
    int* values = data_02107800.values;
    for (int index = 0; index < 10; index++) {
        values[index] = parameters->ToInt();
        parameters++;
    }
    return 1;
}
#endif
