#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);
extern "C" void func_ov000_0216b2a4(void* p);

struct Data02184264 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Data02184264 data_ov000_02185364;

// JPN: func_ov000_0216ba90
extern "C" ARM int func_ov000_0216ba90(char* obj, int count) {
    char* p = (char*)data_ov000_02185364.alloc->Allocate(0x18);
    *(int*)(p + 0x0) = 0xc;
    int val0 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)obj);
    *(short*)(p + 0x8) = (short)val0;
    *(unsigned char*)(p + 0xa) = 0;
    *(int*)(p + 0xc) = 0;
    *(int*)(p + 0x10) = 0;
    *(int*)(p + 0x14) = 0;

    obj += 8;
    if (*(unsigned short*)(p + 0x8) == 5 || *(unsigned short*)(p + 0x8) == 6) {
        *(int*)(p + 0x14) = 0x3fe66666;
    }

    if (count >= 2) {
        int val1 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)obj);
        *(unsigned char*)(p + 0xa) = (unsigned char)val1;
        obj += 8;
    }

    if (count >= 3) {
        float f0 = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)obj);
        *(float*)(p + 0xc) = f0;
        float f1 = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(obj + 8));
        *(float*)(p + 0x10) = f1;
        float f2 = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)(obj + 0x10));
        *(float*)(p + 0x14) = f2;
    }

    func_ov000_0216b2a4(p);
    return 1;
}

#endif
