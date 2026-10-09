#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void func_ov000_0216b2a4(void*);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02185364;

struct Variant02030b0c { int tag; int u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct VariantNodeTag0x75 {
    int tag;
    int unused;
    short x;
    short y;
    unsigned char type;
};

// JPN: func_ov000_0216e128  (semantic: AllocateVariantNodeTag_0216e128)
extern "C" ARM int func_ov000_0216e128(struct Variant02030b0c* v) {
    struct VariantNodeTag0x75* node = (struct VariantNodeTag0x75*)data_ov000_02185364.alloc->Allocate(sizeof(struct VariantNodeTag0x75));
    if (node == 0) {
        return 0;
    }
    memset(node, 0, sizeof(struct VariantNodeTag0x75));
    int type = _ZNK6Script9Parameter5ToIntEv(v);
    node->type = (unsigned char)type;
    switch (type & 0xff) {
    case 0:
        node->x = (short)(int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)v + 8)));
        node->y = (short)(int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)v + 0x10)));
        break;
    case 1:
        node->x = (short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)v + 8));
        node->y = (short)(int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)v + 0x10)));
        break;
    }
    node->tag = 0x75;
    func_ov000_0216b2a4(node);
    return 1;
}

#endif
