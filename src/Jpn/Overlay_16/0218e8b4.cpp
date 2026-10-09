#if defined(jpn)
#include <globaldefs.h>

extern "C" unsigned int func_ov016_0218f150(const void* object);

// JPN: func_ov016_0218e8b4
extern "C" ARM unsigned int func_ov016_0218e8b4(const void* object) {
    if (object == 0) {
        return 0;
    }
    return func_ov016_0218f150(object);
}

#endif

