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

struct VariantNodeTag0x4f {
    int tag;
    int unused;
    unsigned char value : 7;
    unsigned char flag : 1;
    unsigned char count;
};

// JPN: func_ov000_0216d41c  (semantic: AllocateVariantNodeTag_0216d41c)
extern "C" ARM int func_ov000_0216d41c(struct Variant02030b0c* v, int argc) {
    struct VariantNodeTag0x4f* node = (struct VariantNodeTag0x4f*)data_ov000_02185364.alloc->Allocate(sizeof(struct VariantNodeTag0x4f));
    node->tag = 0x4f;
    node->value = (unsigned char)_ZNK6Script9Parameter5ToIntEv(v);
    node->count = 1;
    node->flag = 1;
    if (argc < 2) goto done;
    node->count = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)v + 8));
    if (argc < 3) goto done;
    node->flag = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)v + 0x10));
done:
    func_ov000_0216b2a4(node);
    return 1;
}

#endif
