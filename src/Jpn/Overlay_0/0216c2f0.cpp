#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern "C" void func_ov000_0216b2a4(void* p);

struct Data02184264 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Data02184264 data_ov000_02185364;

// JPN: func_ov000_0216c2f0
extern "C" ARM int func_ov000_0216c2f0(char* obj, int count) {
    char* p = (char*)data_ov000_02185364.alloc->Allocate(0x10);

    if (count == 1) {
        *(int*)(p + 0x0) = 0;
        *(int*)(p + 0x4) = 0;
        *(int*)(p + 0x0) = 0x1e;
        int val = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)obj);
        *(int*)(p + 0xc) = val;
        *(signed char*)(p + 0x8) = -1;
        func_ov000_0216b2a4(p);
    } else if (count == 2) {
        *(int*)(p + 0x0) = 0;
        *(int*)(p + 0x4) = 0;
        *(int*)(p + 0x0) = 0x1e;
        int val0 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)obj);
        *(unsigned char*)(p + 0x8) = (unsigned char)val0;
        int val1 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(obj + 8));
        *(int*)(p + 0xc) = val1;
        func_ov000_0216b2a4(p);
    }

    return 1;
}

#endif
