#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct DescB020dea64;
extern "C" void* func_020e0968(const char* filename, unsigned int* outLength);
extern "C" int func_020dea64(DescB020dea64* destination, void* allocator,
    void* data, void* length, void* entries, short count);

// JPN: func_020e052c
extern "C" ARM int func_020e052c(void* destination, void* allocator,
    const char* filename, void* entries, short count, unsigned char lock)
{
    if (lock)
        BackgroundLoader::AddLockGlobal();
    unsigned int length;
    void* data = func_020e0968(filename, &length);
    int result = func_020dea64(static_cast<DescB020dea64*>(destination), allocator,
        data, reinterpret_cast<void*>(length), entries, count);
    if (lock)
        BackgroundLoader::RemoveLockGlobal();
    return result;
}
#endif
