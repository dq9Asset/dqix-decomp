#if defined(jpn)
#include <globaldefs.h>

// JPN: func_ov016_0218c750
extern "C" ARM void func_ov016_0218c750(unsigned int enabled) {
    volatile unsigned short* powerControl = (volatile unsigned short*)0x04000304;
    *powerControl = (*powerControl & ~0x8000) | (enabled << 15);
}

#endif

