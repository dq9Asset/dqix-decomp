#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue4000_3000 = 0x3000 };
enum { kRegionValue7C_94 = 0x94 };
enum { kRegionValue5C_28 = 0x28 };
#else
enum { kRegionValue4000_3000 = 0x4000 };
enum { kRegionValue7C_94 = 0x7c };
enum { kRegionValue5C_28 = 0x5c };
#endif


extern "C" void func_020c9be0(void);
int GetGlobalField0x1c020421a0(void);

// USA: func_ov003_0215c568
// JPN: func_ov003_0215d87c
extern "C" ARM void func_ov003_0215c568(void* self, SafeAllocator* other) {
    if (other == 0) return;

    void* buf = other->Allocate(0x2000);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)self)->CreateTypeA(buf, 0x2000);

    buf = other->Allocate(0x800);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)((char*)self + 0x14))->CreateTypeA(buf, 0x800);

    buf = other->Allocate(kRegionValue4000_3000);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)((char*)self + 0x28))->CreateTypeA(buf, kRegionValue4000_3000);

    buf = other->Allocate(0x400);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)((char*)self + 0x3c))->CreateTypeA(buf, 0x400);

    buf = other->Allocate(0x2000);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)((char*)self + 0x50))->CreateTypeA(buf, 0x2000);

    int g = GetGlobalField0x1c020421a0();
    *(int*)((char*)self + kRegionValue7C_94) = *(int*)(g + kRegionValue5C_28);
}
