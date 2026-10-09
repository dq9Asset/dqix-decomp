#if defined(jpn)
#include <globaldefs.h>
#include "Util/Random.h"

// JPN: func_ov000_02164f60  (semantic: PickOpenSlotForId_02164f60)
extern "C" ARM int func_ov000_02164f60(void* obj, int id) {
    int i;
    signed char last;
    char* p;
    if (id < 0 || id >= 4) {
        return 0;
    }
    p = (char*)obj + 0x12c;
    last = -1;
    i = 0;
    p = p + 0x7800;
    while (i < 4) {
        signed char v = p[i];
        if (v < 0) {
            int r;
            struct Random* rng;
            p[i] = (char)id;
            rng = GetBTRandom();
            if (last < 0) {
                r = 0;
            } else {
                r = last + NextRandomBetween(rng, 3, 10);
            }
            *((char*)obj + i + 0x7000 + 0x930) = (char)r;
            return 1;
        }
        last = *((char*)obj + i + 0x7900 + 0x30);
        i++;
    }
    return 0;
}

#endif
