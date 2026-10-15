#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_ov023_021e71b4
// JPN: func_ov023_021e7414
ARM void CreateThreeAllocators_021e71b4(void* obj, SafeAllocator* src) {
    if (src == NULL) return;

    void* buf = src->Allocate(0x5000);
    ((SafeAllocator*)obj)->CreateTypeA(buf, 0x5000);

    buf = src->Allocate(0x3400);
    ((SafeAllocator*)((char*)obj + 0x14))->CreateTypeA(buf, 0x3400);

#if defined(jpn)
    const unsigned int thirdArenaSize = 0xc00;
#else
    const unsigned int thirdArenaSize = 0xccc;
#endif
    buf = src->Allocate(thirdArenaSize);
    ((SafeAllocator*)((char*)obj + 0x28))->CreateTypeA(buf, thirdArenaSize);
}
