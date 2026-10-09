#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct0205a198 {
    char data[0x28];
};
struct ClearTarget0205a234;
struct EntryManager020e2490;

extern "C" void func_0205b510(Struct0205a198* s);
extern "C" void func_0205b5ac(ClearTarget0205a234* t);
extern "C" void func_020e4030(EntryManager020e2490* mgr, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);

struct Obj02159f70 {
    SafeAllocator alloc0;
    SafeAllocator alloc14;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator alloc50;
    char pad64[0xec - 0x64];
    Struct0205a198* entries;
    ClearTarget0205a234* clearTarget;
    char padf4[0x570 - 0xf4];
    EntryManager020e2490* entryManager;
};

// JPN: func_ov003_02159f70
extern "C" ARM void func_ov003_02159f70(Obj02159f70* self, SafeAllocator* alloc) {
    if (alloc == NULL) {
        return;
    }
    self->alloc0.CreateTypeA(alloc->Allocate(0x4000), 0x4000);
    self->alloc14.CreateTypeA(alloc->Allocate(0x7000), 0x7000);
    self->alloc28.CreateTypeA(alloc->Allocate(0x8000), 0x8000);
    self->alloc3c.CreateTypeA(alloc->Allocate(0x800), 0x800);
    self->alloc50.CreateTypeA(alloc->Allocate(0x200), 0x200);
    self->entries = (Struct0205a198*)alloc->Allocate(0x230);
    for (int i = 0; i < 14; i++) {
        func_0205b510(&self->entries[i]);
    }
    self->clearTarget = (ClearTarget0205a234*)alloc->Allocate(8);
    func_0205b5ac(self->clearTarget);
    self->alloc50.Reset();
    self->entryManager = (EntryManager020e2490*)self->alloc50.Allocate(0x24);
    func_020e4030(self->entryManager, 0, 1, self->clearTarget, &self->alloc50, 3, 0x40);
}

#endif
