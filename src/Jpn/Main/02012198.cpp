#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012198
extern "C" ARM int func_02012198(const unsigned short* flags)
{
    return (*flags & 0x800) != 0;
}

#endif

