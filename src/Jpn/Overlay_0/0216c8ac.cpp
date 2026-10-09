#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct02030b7c;
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);
extern "C" void func_ov000_0216b2a4(void* p);

struct Data02185364 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Data02185364 data_ov000_02185364;

// JPN: func_ov000_0216c8ac
extern "C" ARM int func_ov000_0216c8ac(struct Struct02030b7c* obj, int count) {
    char* p = (char*)data_ov000_02185364.alloc->Allocate(0xc);
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x0) = 0x2e;
    *(void**)(p + 0x8) = 0;

    if (count <= 1) {
        char* text = (char*)_ZNK6Script9Parameter8ToStringEv(obj);
        if (text) {
            int len = strlen(text);
            char* buf = (char*)data_ov000_02185364.alloc->Allocate(len + 1);
            *(void**)(p + 0x8) = buf;
            strcpy(buf, text);
        }
    }

    func_ov000_0216b2a4(p);
    return 1;
}

#endif
