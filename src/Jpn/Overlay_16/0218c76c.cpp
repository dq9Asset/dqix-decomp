#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern SafeAllocator* data_ov016_0219cfa0;

// JPN: func_ov016_0218c76c
// Allocates from the allocator shared by the movie player and its MODS decoder.
// The decoder also installs this wrapper as its allocation callback.
extern "C" ARM void* AllocateMovieMemory(unsigned int byteCount) {
    return data_ov016_0219cfa0->Allocate(byteCount);
}

#endif

