#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern SafeAllocator* data_ov016_0219cfa0;

// JPN: func_ov016_0218c76c
extern "C" ARM void* func_ov016_0218c76c(unsigned int size) {
    return data_ov016_0219cfa0->Allocate(size);
}

#endif

