#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012148
extern "C" ARM int func_02012148(const unsigned short* flags)
{
    return (*flags & 0x80) != 0;
}

#endif

