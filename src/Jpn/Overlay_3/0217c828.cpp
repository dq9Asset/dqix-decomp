#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_0205e378(void* obj);
struct List0204afb4;
extern "C" void func_0204bdd4(struct List0204afb4* obj);
struct Obj0204c754;
extern "C" void func_0204d570(struct Obj0204c754* obj);
struct ClearTarget0205a244;
extern "C" void func_0205b5bc(struct ClearTarget0205a244* target);
extern "C" void func_0205b830(void* obj);
struct Struct020dfc40;
extern "C" void func_020e1840(struct Struct020dfc40* p);

// JPN: func_ov003_0217c828  (semantic: ResetOverlayStateAndSetDispcnt_0217c828)
extern "C" ARM void func_ov003_0217c828(void* obj) {
    unsigned char* o = (unsigned char*)obj;

    func_0205e378(*(void**)(o + 0x8c));

    int i;
    for (i = 0; i < 2; i++) {
        func_0204bdd4((struct List0204afb4*)(*(char**)(o + 0x90) + i * 0x20));
    }

    int j;
    for (j = 0; j < 1; j++) {
        func_0204d570((struct Obj0204c754*)(*(char**)(o + 0x94) + j * 0xe0));
    }

    func_0205b5bc((struct ClearTarget0205a244*)(*(void**)(o + 0x34)));

    if (((SafeAllocator*)(o + 0xa0))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + 0xa0))->Destroy();
    }
    if (((SafeAllocator*)(o + 0xb4))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + 0xb4))->Destroy();
    }
    func_0205b830(o + 0x38);
    func_020e1840((struct Struct020dfc40*)(o + 0xc8));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | ((unsigned int)*(int*)o << 8);
}

#endif
