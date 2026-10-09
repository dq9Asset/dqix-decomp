#if defined(jpn)
#include <globaldefs.h>

extern "C" unsigned int func_ov016_0218f158(const void* object);

// JPN: func_ov016_0218e8cc
extern "C" ARM unsigned int func_ov016_0218e8cc(const void* object) {
    if (object == 0) {
        return 0;
    }
    return func_ov016_0218f158(object);
}

#endif

