#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov000_02180958(void* obj);
extern "C" void func_ov000_021818c0(void* obj, int param, int flag);

struct Entry02181cc8 {
    char pad0[0x24];
    unsigned char field24;
    char pad1[0x4c - 0x25];
    int field4c;
    char pad2[0x488 - 0x50];
};

// JPN: func_ov000_02181cc8
extern "C" ARM void func_ov000_02181cc8(void* objRaw, int param) {
    char* obj = (char*)objRaw;
    for (int i = 0; i < 4; i++) {
        struct Entry02181cc8* entry = (struct Entry02181cc8*)(obj + 0x958) + *(signed char*)(obj + i + 0x6c);
        if (*(int*)(obj + 0x17c) == entry->field4c) {
            if (!(entry->field24 & 0x4)) {
                if (!func_ov000_02180958(obj)) {
                    return;
                }
                func_ov000_021818c0(obj, param, 0);
                *(unsigned short*)(obj + 0x1f00 + 0xaa) &= ~0x8;
                *(unsigned short*)(obj + 0x1f00 + 0xaa) = (*(unsigned short*)(obj + 0x1f00 + 0xaa) | 0x10) & ~0x20;
                return;
            }
            *(int*)(obj + 0x910) = 0;
            *(int*)(obj + 0x914) = 0;
            *(int*)(obj + 0x918) = 0;
            *(int*)(obj + 0x91c) = 0;
            *(unsigned short*)(obj + 0x1f00 + 0xaa) &= ~0x38;
            return;
        }
    }
}

#endif
