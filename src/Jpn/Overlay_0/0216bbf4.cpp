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

struct Struct02030b7c;
extern "C" extern void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

extern char data_ov000_021850f0[];
extern char data_ov000_021850f5[];

struct Node0216bbf4 {
    int tag;
    void* field4;
    char* strBuf;
};

// JPN: func_ov000_0216bbf4  (semantic: AllocateVariantNodeTag_0216bbf4)
extern "C" ARM int func_ov000_0216bbf4(struct Struct02030b7c* p) {
    struct Node0216bbf4* node = (struct Node0216bbf4*)data_ov000_02185364.alloc->Allocate(sizeof(struct Node0216bbf4));
    node->tag = 0;
    node->field4 = 0;
    node->tag = 0x12;
    char* name = (char*)_ZNK6Script9Parameter8ToStringEv(p);
    node->strBuf = (char*)data_ov000_02185364.alloc->Allocate(strlen(name) + 1);
    strcpy(node->strBuf, name);
    char* found = strstr(node->strBuf, data_ov000_021850f0);
    if (found != NULL) {
        strcpy(found, data_ov000_021850f5);
    }
    func_ov000_0216b2a4(node);
    return 1;
}

#endif
