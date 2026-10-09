#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012184
extern "C" ARM int func_02012184(const unsigned short* flags)
{
    return (*flags & 0x400) != 0;
}

#endif

