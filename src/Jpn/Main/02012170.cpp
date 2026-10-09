#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012170
extern "C" ARM int func_02012170(const unsigned short* flags)
{
    return (*flags & 2) != 0;
}

#endif

