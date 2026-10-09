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

// JPN: func_ov000_0216c108
extern "C" ARM int func_ov000_0216c108(char* obj, int count) {
    char* p = (char*)data_ov000_02185364.alloc->Allocate(0xc);
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x0) = 0x1a;

    int idx = 1;
    int tag = *(int*)obj;
    if (tag == 2) {
        *(unsigned char*)(p + 0x8) = 7;
        *(unsigned short*)(p + 0xa) = 0x1000;
    } else if (tag == 1) {
        int val = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)obj);
        *(unsigned char*)(p + 0x8) = (unsigned char)val;
        *(unsigned short*)(p + 0xa) = 0x1000;
        obj += 8;
        idx = 2;
    }

    if (idx <= count) {
        int tag2 = *(int*)obj;
        if (tag2 == 2) {
            float f = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)obj);
            *(unsigned short*)(p + 0xa) = (unsigned short)(int)(f * 4096.0f);
        } else if (tag2 == 1) {
            int v = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)obj);
            float vf = (float)v;
            *(unsigned short*)(p + 0xa) = (unsigned short)(int)((vf / 1000.0f) * 4096.0f);
        }
    }

    func_ov000_0216b2a4(p);
    return 1;
}

#endif
