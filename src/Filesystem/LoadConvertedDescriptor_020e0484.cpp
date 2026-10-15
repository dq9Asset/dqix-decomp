#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct DescA020de9a4;
extern "C" void* func_020e0968(const char* filename, unsigned int* outLength);
extern "C" int func_020de9a4(DescA020de9a4* destination, void* allocator,
    void* data, void* length, void* entries, unsigned short count);

// JPN: func_020e0484
extern "C" ARM int func_020e0484(void* destination, void* allocator,
    const char* filename, void* entries, unsigned short count, bool lock)
{
    if (lock)
        BackgroundLoader::AddLockGlobal();
    unsigned int length;
    void* data = func_020e0968(filename, &length);
    int result = func_020de9a4(static_cast<DescA020de9a4*>(destination), allocator,
        data, reinterpret_cast<void*>(length), entries, count);
    if (lock)
        BackgroundLoader::RemoveLockGlobal();
    return result;
}
#endif
