#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern char data_ov016_0219d0c0[];

#if defined(jpn)
static const int allocatorOffset = 0;
#else
static const int allocatorOffset = 8;
#endif

// USA: func_ov016_0218bca8
// JPN: func_ov016_0218c788
ARM void SafeAllocatorFree_0218bca8(void* data) {
    SafeAllocator* alloc = *(SafeAllocator**)(data_ov016_0219d0c0 + allocatorOffset);
    alloc->Free(data);
}
