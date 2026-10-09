#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern SafeAllocator* data_ov016_0219cfa0;

// JPN: func_ov016_0218c788
// Releases an allocation through the movie player's shared allocator.
// This is also the deallocation callback used by the MODS decoder.
extern "C" ARM void FreeMovieMemory(void* allocation) {
    data_ov016_0219cfa0->Free(allocation);
}

#endif

