#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Variant02030b0c { int tag; int u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct Zeroable02169a40;
extern "C" void func_ov000_0216b16c(struct Zeroable02169a40* s);

struct Node0216b31c {
    unsigned short* data;
    unsigned short count;
    unsigned int reserved8;
    struct Node0216b31c* next;
};

struct Struct02184264_0216b31c {
    struct Node0216b31c* head;
    struct Node0216b31c* tail;
    SafeAllocator* alloc;
};
extern struct Struct02184264_0216b31c data_ov000_02185364;

// JPN: func_ov000_0216b31c  (semantic: AllocateAndEnqueueVariantArrayNode_0216b31c)
extern "C" ARM int func_ov000_0216b31c(struct Variant02030b0c* v, int count) {
    struct Node0216b31c* node = (struct Node0216b31c*)data_ov000_02185364.alloc->Allocate(0x10);
    func_ov000_0216b16c((struct Zeroable02169a40*)node);
    node->count = count;
    if (node->count != 0) {
        unsigned short buffer[0x20];
        unsigned short sawFlag = 0;
        int i = 0;
        for (; i < node->count; v++, i++) {
            buffer[i] = (unsigned short)_ZNK6Script9Parameter5ToIntEv(v);
            if (buffer[i] == 1) sawFlag = 1;
        }
        if (sawFlag) {
            buffer[node->count] = 2;
            buffer[node->count + 1] = 0xdb;
            node->count = node->count + 2;
        }
        node->data = (unsigned short*)data_ov000_02185364.alloc->Allocate(node->count * 2);
        memcpy(node->data, buffer, node->count * 2);
    }
    struct Node0216b31c* tail = data_ov000_02185364.tail;
    if (tail == 0) {
        data_ov000_02185364.tail = node;
    } else {
        tail->next = node;
        data_ov000_02185364.tail = node;
    }
    if (!data_ov000_02185364.head) {
        data_ov000_02185364.head = node;
    }
    return 1;
}

#endif
