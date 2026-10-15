#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_020e0484(void* destination, void* allocator,
    const char* filename, void* entries, unsigned short count, bool lock);

// JPN: func_020e04f8
extern "C" ARM int func_020e04f8(void* destination, void* allocator,
    const char* filename, short entry, bool lock)
{
    return func_020e0484(destination, allocator, filename, &entry, 1, lock);
}
#endif
