#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_0216b2a4(void*);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02185364;

struct Variant02030b0c { int tag; int u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" extern struct TaggedValue02030b44* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44* obj, int* outVec);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct VariantNodeTag0x56 {
    int tag;
    int unused;
    unsigned char value;
    int vec1[3];
    int vec2[3];
    unsigned char flag;
};

// JPN: func_ov000_0216d598  (semantic: AllocateVariantNodeTag_0216d598)
extern "C" ARM int func_ov000_0216d598(struct Variant02030b0c* v, int count) {
    struct VariantNodeTag0x56* node = (struct VariantNodeTag0x56*)data_ov000_02185364.alloc->Allocate(sizeof(struct VariantNodeTag0x56));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x56;
    node->value = (unsigned char)_ZNK6Script9Parameter5ToIntEv(v);
    struct TaggedValue02030b44* next = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct TaggedValue02030b44*)((char*)v + 8), node->vec1);
    node->vec2[0] = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(next + 0));
    node->vec2[1] = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(next + 1));
    node->vec2[2] = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(next + 2));
    node->flag = 0;
    if (count >= 8) {
        node->flag = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(next + 3));
    }
    func_ov000_0216b2a4(node);
    return 1;
}

#endif
