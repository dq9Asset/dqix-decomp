#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov000_0218283c(void* obj);

struct Entry02176574 {
    char pad0[0x18];
    signed char field18;
    char pad1[0x24 - 0x19];
    unsigned char field24;
    char pad2[0x28 - 0x25];
    int field28;
    char pad3[0x4c - 0x2c];
    int field4c;
    char pad4[0x488 - 0x50];
};

// JPN: func_ov000_02176574
extern "C" ARM void func_ov000_02176574(char* obj) {
    int adjusted = func_ov000_0218283c(obj);
    struct Entry02176574* entry;
    for (signed char i = 0; i < 4; i++) {
        entry = (struct Entry02176574*)(obj + 0x958) + *(signed char*)(obj + i + 0x6c);
        int inRange = (adjusted >= 0 && adjusted <= 3) ? 1 : 0;
        if (inRange) {
            if (adjusted == entry->field4c) {
                continue;
            }
        }
        if (!(entry->field28 & 1)) {
            continue;
        }
        char* p = (char*)entry + entry->field18;
        *(unsigned char*)(p + 0x10) = 0x64;
        entry->field24 = entry->field24 & ~4;
        entry->field24 = entry->field24 & ~1;
    }
}

#endif
