#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern SafeAllocator* data_ov016_0219cfa0;

// JPN: func_ov016_0218c788
extern "C" ARM void func_ov016_0218c788(void* data) {
    data_ov016_0219cfa0->Free(data);
}

#endif

