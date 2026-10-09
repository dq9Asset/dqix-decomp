#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct InitTarget0205cfd4;
extern "C" ARM void func_0205e304(struct InitTarget0205cfd4* s);
struct List0204af64;
extern "C" ARM void func_0204bd84(struct List0204af64* obj);
extern "C" void func_0204d4a4(void* obj);
struct Struct0205a198;
extern "C" void func_0205b510(struct Struct0205a198*);
struct ClearTarget0205a234;
extern "C" void func_0205b5ac(struct ClearTarget0205a234* target);

struct Obj0217ba4c {
    char pad0[0x30];
    void* p34;
    void* p38;
    char pad1[0x8c - 0x38];
    void* p90;
    void* p94;
    void* p98;
    char pad2[4];
    SafeAllocator* alloc;
    SafeAllocator allocA4;
    SafeAllocator allocB8;
};

// JPN: func_ov003_0217ba4c
extern "C" ARM void func_ov003_0217ba4c(void* objRaw, SafeAllocator* allocator) {
    if (allocator == 0) return;
    struct Obj0217ba4c* obj = (struct Obj0217ba4c*)objRaw;

    obj->alloc = allocator;
    obj->p90 = obj->alloc->Allocate(0xbc);
    obj->p94 = obj->alloc->Allocate(0x40);
    obj->p98 = obj->alloc->Allocate(0xe0);
    func_0205e304((struct InitTarget0205cfd4*)obj->p90);

    for (int i = 0; i < 2; i++) {
        func_0204bd84((struct List0204af64*)((char*)obj->p94 + i * 0x20));
    }
    for (int i = 0; i < 1; i++) {
        func_0204d4a4((char*)obj->p98 + i * 0xe0);
    }

    obj->p34 = obj->alloc->Allocate(0x118);
    obj->p38 = obj->alloc->Allocate(8);

    for (int i = 0; i < 7; i++) {
        func_0205b510((struct Struct0205a198*)((char*)obj->p34 + i * 0x28));
    }
    func_0205b5ac((struct ClearTarget0205a234*)obj->p38);

    void* buf1 = obj->alloc->Allocate(0x800);
    obj->allocA4.CreateTypeA(buf1, 0x800);

    void* buf2 = obj->alloc->Allocate(0x400);
    obj->allocB8.CreateTypeA(buf2, 0x400);
}

#endif
