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
struct Struct02030b7c { unsigned char pad[0x8]; };
extern "C" char* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* p);

struct VariantNodeTag0x5b {
    int tag;
    int unused;
    unsigned char byte8;
    unsigned char byte9;
    char* str;
};

// JPN: func_ov000_0216d870  (semantic: AllocateVariantNodeTag_0216d870)
extern "C" ARM int func_ov000_0216d870(struct Variant02030b0c* v, int argc) {
    struct VariantNodeTag0x5b* node = (struct VariantNodeTag0x5b*)data_ov000_02185364.alloc->Allocate(sizeof(struct VariantNodeTag0x5b));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x5b;
    node->byte8 = (unsigned char)_ZNK6Script9Parameter5ToIntEv(v);
    node->byte9 = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)v + 8));
    if (argc >= 3) {
        char* src = _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)((char*)v + 0x10));
        char* dst = (char*)data_ov000_02185364.alloc->Allocate(strlen(src) + 1);
        node->str = dst;
        if (dst != 0) {
            strcpy(dst, src);
        }
    } else {
        node->str = 0;
    }
    func_ov000_0216b2a4(node);
    return 1;
}

#endif
