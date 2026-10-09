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

struct Struct0216a9ac {
    char pad0[0x10f4];
    void* p264;
    void* p268;
    char pad1[0x1150 - 0x10fc];
    void* p2c0;
    void* p2c4;
    void* p2c8;
    char pad2[0x1160 - 0x115c];
    SafeAllocator* alloc;
};

// JPN: func_ov003_0216a9ac
extern "C" ARM void func_ov003_0216a9ac(void* objRaw, SafeAllocator* allocator) {
    if (allocator == 0) return;
    struct Struct0216a9ac* obj = (struct Struct0216a9ac*)objRaw;

    obj->alloc = allocator;
    obj->p2c0 = obj->alloc->Allocate(0xbc);
    obj->p2c4 = obj->alloc->Allocate(0x40);
    obj->p2c8 = obj->alloc->Allocate(0xe0);
    func_0205e304((struct InitTarget0205cfd4*)obj->p2c0);

    for (int i = 0; i < 2; i++) {
        func_0204bd84((struct List0204af64*)((char*)obj->p2c4 + i * 0x20));
    }
    for (int i = 0; i < 1; i++) {
        func_0204d4a4((char*)obj->p2c8 + i * 0xe0);
    }

    obj->p264 = obj->alloc->Allocate(0x258);
    obj->p268 = obj->alloc->Allocate(8);

    for (int i = 0; i < 0xf; i++) {
        func_0205b510((struct Struct0205a198*)((char*)obj->p264 + i * 0x28));
    }
    func_0205b5ac((struct ClearTarget0205a234*)obj->p268);
}

#endif
