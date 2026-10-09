#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Variant02030b0c { int tag; int u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct Struct02030b7c;
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

extern "C" void func_ov000_0216b2a4(void* node);

struct Data02184264 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Data02184264 data_ov000_02185364;

struct EventNode0216cee4 {
    int tag;
    int unused;
    unsigned char b8;
    unsigned char b9;
    char pad[2];
    char* str;
};

// JPN: func_ov000_0216cee4  (semantic: BuildVariantEvent_0216cee4)
extern "C" ARM int func_ov000_0216cee4(char* arg) {
    struct EventNode0216cee4* node = (struct EventNode0216cee4*)data_ov000_02185364.alloc->Allocate(0x10);
    if (node == NULL) return 0;
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x3b;
    node->b8 = (_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)arg) & 0xff) - 0x1a;
    node->b9 = (_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(arg + 0x8)) & 0xff) - 0x1a;
    char* text = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(arg + 0x10));
    if (text != NULL) {
        char* buf = (char*)data_ov000_02185364.alloc->Allocate(strlen(text) + 1);
        node->str = buf;
        if (buf != NULL) {
            strcpy(buf, text);
        }
    } else {
        node->str = 0;
    }
    func_ov000_0216b2a4(node);
    return 1;
}

#endif
