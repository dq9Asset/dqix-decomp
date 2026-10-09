#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012120
extern "C" ARM int func_02012120(const unsigned short* flags)
{
    return (*flags & 0x10) != 0;
}

#endif

