#if defined(jpn)
#include <globaldefs.h>

extern "C" unsigned int func_ov016_0218f148(const void* object);

// JPN: func_ov016_0218e89c
extern "C" ARM unsigned int func_ov016_0218e89c(const void* object) {
    if (object == 0) {
        return 0;
    }
    return func_ov016_0218f148(object);
}

#endif

