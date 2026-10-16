#if defined(jpn)
#include <globaldefs.h>

struct NameResourceHeader {
    unsigned int count : 12;
    unsigned int textBytes : 19;
    unsigned int relocated : 1;
};

// JPN: func_ov009_02185ed8
extern "C" ARM unsigned int func_ov009_02185ed8(void* resource)
{
    NameResourceHeader* header = (NameResourceHeader*)resource;
    return header->count * sizeof(unsigned short);
}
#endif
