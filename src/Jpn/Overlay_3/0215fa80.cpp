#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// JPN: func_ov003_0215fa80  (semantic: InitEightAllocators_0215fa80)
extern "C" ARM void func_ov003_0215fa80(void* self, SafeAllocator* other) {
    if (other == 0) return;

    void* buf = other->Allocate(0x1000);
    ((SafeAllocator*)((char*)self + 0x110))->CreateTypeA(buf, 0x1000);

    buf = other->Allocate(0x7000);
    ((SafeAllocator*)((char*)self + 0x124))->CreateTypeA(buf, 0x7000);

    buf = other->Allocate(0x2000);
    ((SafeAllocator*)((char*)self + 0x14c))->CreateTypeA(buf, 0x2000);

    buf = other->Allocate(0x7400);
    ((SafeAllocator*)((char*)self + 0x160))->CreateTypeA(buf, 0x7400);

    buf = other->Allocate(0x4c00);
    ((SafeAllocator*)((char*)self + 0x174))->CreateTypeA(buf, 0x4c00);

    buf = other->Allocate(0xc00);
    ((SafeAllocator*)((char*)self + 0x188))->CreateTypeA(buf, 0xc00);

    buf = other->Allocate(0x3c00);
    ((SafeAllocator*)((char*)self + 0x19c))->CreateTypeA(buf, 0x3c00);

    buf = other->Allocate(0x200);
    ((SafeAllocator*)((char*)self + 0x1b0))->CreateTypeA(buf, 0x200);
}

#endif
