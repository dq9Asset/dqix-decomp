#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern char data_ov016_0219d0c0[];

#if defined(jpn)
static const int allocatorOffset = 0;
#else
static const int allocatorOffset = 8;
#endif

// USA: func_ov016_0218bc8c
// JPN: func_ov016_0218c76c
ARM void* SafeAllocatorAllocate_0218bc8c(unsigned int len) {
    SafeAllocator* alloc = *(SafeAllocator**)(data_ov016_0219d0c0 + allocatorOffset);
    return alloc->Allocate(len);
}
