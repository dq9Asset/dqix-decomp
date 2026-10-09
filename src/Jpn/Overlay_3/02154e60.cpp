#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Sizes1_02154e60 { unsigned int v[1]; };
extern Sizes1_02154e60 data_ov003_0217df84[];

// JPN: func_ov003_02154e60  (semantic: InitAllocatorArray1_02154e60)
extern "C" ARM void func_ov003_02154e60(void* obj, SafeAllocator* alloc) {
    *(void**)obj = alloc->Allocate(0x14);
    struct Sizes1_02154e60 sizes = data_ov003_0217df84[1];
    for (unsigned char i = 0; i < 1; i++) {
        ((SafeAllocator*)((char*)*(void**)obj + i * 0x14))->ResetAllocatorPointer();
        unsigned int sz = sizes.v[i];
        void* p = alloc->Allocate(sz);
        ((SafeAllocator*)((char*)*(void**)obj + i * 0x14))->CreateTypeA(p, sz);
    }
}

#endif
