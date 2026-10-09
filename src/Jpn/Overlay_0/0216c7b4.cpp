#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);
extern "C" void func_ov000_0216b2a4(void* p);

struct Data02185364 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Data02185364 data_ov000_02185364;

// JPN: func_ov000_0216c7b4
extern "C" ARM int func_ov000_0216c7b4(char* obj, int count) {
    char* p = (char*)data_ov000_02185364.alloc->Allocate(0x10);
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x0) = 0x2b;

    int val0 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)obj);
    *(unsigned char*)(p + 0x8) = (unsigned char)val0;
    int val1 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(obj + 8));
    *(unsigned char*)(p + 0x9) = (unsigned char)val1;

    if (count >= 3) {
        float f = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(obj + 0x10));
        *(int*)(p + 0xc) = (int)(f * 4096.0f);
    }

    func_ov000_0216b2a4(p);
    return 1;
}

#endif
