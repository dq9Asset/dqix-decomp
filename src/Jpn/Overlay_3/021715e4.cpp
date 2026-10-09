#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct0205a198;
extern "C" void func_0205b510(struct Struct0205a198* p);

struct ClearTarget0205a234;
extern "C" void func_0205b5ac(struct ClearTarget0205a234* target);

// JPN: func_ov003_021715e4
extern "C" ARM void func_ov003_021715e4(char* obj, SafeAllocator* allocator) {
    int i;

    if (allocator == 0) return;

    *(SafeAllocator**)(obj + 0x1cc) = allocator;
    *(void**)(obj + 0x134) = allocator->Allocate(0x1e0);
    *(void**)(obj + 0x138) = (*(SafeAllocator**)(obj + 0x1cc))->Allocate(8);

    for (i = 0; i < 0xc; i++) {
        func_0205b510((struct Struct0205a198*)(*(char**)(obj + 0x134) + i * 0x28));
    }

    func_0205b5ac((struct ClearTarget0205a234*)*(void**)(obj + 0x138));

    void* p1 = (*(SafeAllocator**)(obj + 0x1cc))->Allocate(0x1000);
    ((SafeAllocator*)(obj + 0x1b8))->CreateTypeA(p1, 0x1000);
    ((SafeAllocator*)(obj + 0x1b8))->Reset();

    void* p2 = (*(SafeAllocator**)(obj + 0x1cc))->Allocate(0x1c00);
    ((SafeAllocator*)(obj + 0x190))->CreateTypeA(p2, 0x1c00);
    ((SafeAllocator*)(obj + 0x190))->Reset();

    void* p3 = (*(SafeAllocator**)(obj + 0x1cc))->Allocate(0x400);
    ((SafeAllocator*)(obj + 0x1a4))->CreateTypeA(p3, 0x400);
    ((SafeAllocator*)(obj + 0x1a4))->Reset();
}

#endif
