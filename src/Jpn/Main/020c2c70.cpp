#if defined(jpn)
#include <globaldefs.h>

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020c2c70
extern "C" ARM void Mat3x3_ApplyScale(int* src, int* dst, int scaleX, int scaleY, int scaleZ) {
    dst[0] = (int)(((long long)scaleX * src[0]) >> 12);
    dst[1] = (int)(((long long)scaleX * src[1]) >> 12);
    dst[2] = (int)(((long long)scaleX * src[2]) >> 12);
    dst[3] = (int)(((long long)scaleY * src[3]) >> 12);
    dst[4] = (int)(((long long)scaleY * src[4]) >> 12);
    dst[5] = (int)(((long long)scaleY * src[5]) >> 12);
    dst[6] = (int)(((long long)scaleZ * src[6]) >> 12);
    dst[7] = (int)(((long long)scaleZ * src[7]) >> 12);
    dst[8] = (int)(((long long)scaleZ * src[8]) >> 12);
}


#endif
