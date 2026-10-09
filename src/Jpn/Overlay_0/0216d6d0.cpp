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
struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);
extern "C" extern struct TaggedValue02030b44* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44* obj, int* outVec);

struct VariantNodeTag0x58 {
    int tag;
    int unused;
    int vec1[3];
    int vec2[3];
};

// JPN: func_ov000_0216d6d0  (semantic: AllocateVariantNodeTag_0216d6d0)
extern "C" ARM int func_ov000_0216d6d0(struct Variant02030b0c* v) {
    struct VariantNodeTag0x58* node = (struct VariantNodeTag0x58*)data_ov000_02185364.alloc->Allocate(sizeof(struct VariantNodeTag0x58));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x58;
    struct TaggedValue02030b44* tv = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct TaggedValue02030b44*)v, node->vec1);
    node->vec2[0] = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(tv + 0));
    node->vec2[1] = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(tv + 1));
    node->vec2[2] = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(tv + 2));
    func_ov000_0216b2a4(node);
    return 1;
}

#endif
