#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_0205b510(void* p);
extern "C" void func_0205b5ac(void* p);
extern "C" int func_02042940();

struct Obj02167f58 {
    SafeAllocator alloc0;
    SafeAllocator alloc14;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator alloc50;
    char pad64[0x7c - 0x64];
    int field7c;
    char pad80[0x4d0 - 0x80];
    void* field4d4;
    void* field4d8;
};

// JPN: func_ov003_02167f58
extern "C" ARM void func_ov003_02167f58(struct Obj02167f58* obj, SafeAllocator* alloc) {
    if (alloc == 0) return;
    void* p1 = alloc->Allocate(0x4000);
    obj->alloc0.CreateTypeA(p1, 0x4000);
    void* p2 = alloc->Allocate(0x8000);
    obj->alloc14.CreateTypeA(p2, 0x8000);
    void* p3 = alloc->Allocate(0x8000);
    obj->alloc28.CreateTypeA(p3, 0x8000);
    void* p4 = alloc->Allocate(0x400);
    obj->alloc3c.CreateTypeA(p4, 0x400);
    void* p5 = alloc->Allocate(0x400);
    obj->alloc50.CreateTypeA(p5, 0x400);
    void* p6 = alloc->Allocate(0x140);
    obj->field4d4 = p6;

    int i;
    for (i = 0; i < 8; i++) {
        func_0205b510((char*)obj->field4d4 + i * 0x28);
    }

    void* p7 = alloc->Allocate(8);
    obj->field4d8 = p7;
    func_0205b5ac(p7);

    obj->field7c = *(int*)(func_02042940() + 0x28);
}

#endif
