#if defined(jpn)
#include <globaldefs.h>
#include "Util/Random.h"

// JPN: func_ov000_02164ff8
extern "C" ARM void func_ov000_02164ff8(char* obj) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (*(signed char*)(obj + 0x792c + i) >= 0) {
            count++;
        }
    }
    if (count <= 1) {
        return;
    }
    int n = NextRandomBetween(GetBTRandom(), 2, 10);
    for (int k = 1; k < n; k++) {
        int j = k % count;
        signed char first = *(signed char*)(obj + 0x792c);
        *(signed char*)(obj + 0x792c) = *(signed char*)(obj + 0x792c + j);
        *(signed char*)(obj + 0x792c + j) = first;
    }
}

#endif
