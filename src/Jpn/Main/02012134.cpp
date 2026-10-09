#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012134
extern "C" ARM int func_02012134(const unsigned short* flags)
{
    return (*flags & 0x40) != 0;
}

#endif

