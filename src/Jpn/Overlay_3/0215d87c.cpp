#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_020cb6ac(void);
extern "C" int func_02042940(void);

// JPN: func_ov003_0215d87c  (semantic: InitFiveAllocators_0215d87c)
extern "C" ARM void func_ov003_0215d87c(void* self, SafeAllocator* other) {
    if (other == 0) return;

    void* buf = other->Allocate(0x2000);
    if (buf == 0) func_020cb6ac();
    ((SafeAllocator*)self)->CreateTypeA(buf, 0x2000);

    buf = other->Allocate(0x800);
    if (buf == 0) func_020cb6ac();
    ((SafeAllocator*)((char*)self + 0x14))->CreateTypeA(buf, 0x800);

    buf = other->Allocate(0x3000);
    if (buf == 0) func_020cb6ac();
    ((SafeAllocator*)((char*)self + 0x28))->CreateTypeA(buf, 0x3000);

    buf = other->Allocate(0x400);
    if (buf == 0) func_020cb6ac();
    ((SafeAllocator*)((char*)self + 0x3c))->CreateTypeA(buf, 0x400);

    buf = other->Allocate(0x2000);
    if (buf == 0) func_020cb6ac();
    ((SafeAllocator*)((char*)self + 0x50))->CreateTypeA(buf, 0x2000);

    int g = func_02042940();
    *(int*)((char*)self + 0x94) = *(int*)(g + 0x28);
}

#endif
