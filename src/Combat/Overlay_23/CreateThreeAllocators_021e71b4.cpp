#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_ov023_021e71b4
// JPN: func_ov023_021e7414
ARM void CreateThreeAllocators_021e71b4(void* obj, SafeAllocator* src) {
    if (src == NULL) return;
    SafeAllocator* arenas = static_cast<SafeAllocator*>(obj);

    void* buf = src->Allocate(0x5000);
    arenas[0].CreateTypeA(buf, 0x5000);

    buf = src->Allocate(0x3400);
    arenas[1].CreateTypeA(buf, 0x3400);

#if defined(jpn)
    const unsigned int thirdArenaSize = 0xc00;
#else
    const unsigned int thirdArenaSize = 0xccc;
#endif
    buf = src->Allocate(thirdArenaSize);
    arenas[2].CreateTypeA(buf, thirdArenaSize);
}
