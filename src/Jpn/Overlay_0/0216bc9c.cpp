#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_0216b2a4(void* node);

struct Data02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Data02184264 data_ov000_02185364;

extern char data_ov000_021850f0[];
extern char data_ov000_021850f5[];

struct Node0216bc9c {
    int tag;
    void* field4;
    signed char index;
    char* strBuf;
};

// JPN: func_ov000_0216bc9c
extern "C" ARM int func_ov000_0216bc9c(Script::Parameter* params) {
    struct Node0216bc9c* node = (struct Node0216bc9c*)data_ov000_02185364.alloc->Allocate(sizeof(struct Node0216bc9c));
    if (params[0].type == 0) {
        node->tag = 0;
        node->field4 = 0;
        node->tag = 0x14;
        node->index = -1;
        const char* name = params[0].ToString();
        node->strBuf = (char*)data_ov000_02185364.alloc->Allocate(strlen(name) + 1);
        strcpy(node->strBuf, name);
        char* found = strstr(node->strBuf, data_ov000_021850f0);
        if (found != NULL) {
            strcpy(found, data_ov000_021850f5);
        }
    } else if (params[0].type == 1) {
        node->tag = 0;
        node->field4 = 0;
        node->tag = 0x14;
        node->index = params[0].ToInt();
        const char* name = params[1].ToString();
        node->strBuf = (char*)data_ov000_02185364.alloc->Allocate(strlen(name) + 1);
        strcpy(node->strBuf, name);
        char* found = strstr(node->strBuf, data_ov000_021850f0);
        if (found != NULL) {
            strcpy(found, data_ov000_021850f5);
        }
    }
    func_ov000_0216b2a4(node);
    return 1;
}

#endif
