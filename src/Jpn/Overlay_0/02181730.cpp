#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov000_02180848(char* obj);

struct TableEntry0217f8c0 {
    char pad0[0x4c];
    int field0x4c;
    char pad1[0x488 - 0x50];
};
struct Struct0217f8c0 {
    char pad[0x6c];
    signed char idx[4];
    char pad2[0x17c - 0x70];
    int field0x17c;
};
extern "C" struct TableEntry0217f8c0* func_ov000_02180bec(struct Struct0217f8c0* s);

struct Entry02180404 {
    char pad0[0x4c];
    int field4c;
    char pad1[0xc7 - 0x50];
    unsigned char field87;
    char pad2[0x488 - 0xc8];
};

// JPN: func_ov000_02181730
extern "C" ARM void func_ov000_02181730(char* obj) {
    int i;
    for (i = 0; i < 4; i++) {
        struct Entry02180404* entry = (struct Entry02180404*)(obj + 0x958) + *(signed char*)(obj + i + 0x6c);
        int inRange = (entry->field4c >= 0 && entry->field4c <= 3) ? 1 : 0;
        if (inRange && entry->field87 != 0) {
            func_ov000_02180848((char*)entry);
        }
    }
    struct TableEntry0217f8c0* e = func_ov000_02180bec((struct Struct0217f8c0*)obj);
    if (e) {
        *((unsigned char*)e + 0x24) |= 4;
    }
}

#endif
