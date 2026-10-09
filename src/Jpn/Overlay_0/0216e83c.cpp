#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_0216b2a4(void* node);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02185364;

struct Variant02030b0c { int tag; int u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* v);

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct VariantNodeTag0216e83c {
    int tag;
    int unused;
    unsigned char value;
    int angle;
};

// JPN: func_ov000_0216e83c  (semantic: AllocateVariantNodeTagAngle_0216e83c)
extern "C" ARM int func_ov000_0216e83c(struct Variant02030b0c* v) {
    struct VariantNodeTag0216e83c* node = (struct VariantNodeTag0216e83c*)data_ov000_02185364.alloc->Allocate(0x10);
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x8c;
    node->value = (unsigned char)_ZNK6Script9Parameter5ToIntEv(v);
    float degrees = _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)v + 8));
    node->angle = (int)(degrees * 3.14159274f / 180.0f * 4096.0f);
    func_ov000_0216b2a4(node);
    return 1;
}

#endif
