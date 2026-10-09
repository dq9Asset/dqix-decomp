#if defined(jpn)
#include <globaldefs.h>

struct Struct_0205c570;
struct Obj0205eaa0;
struct Entry_0205d6a0;
struct Struct0217f8c0;
struct TableEntry0217f8c0;

extern "C" int func_0205eaa8(struct Struct_0205c570* s);
extern "C" void func_0205fd8c(struct Obj0205eaa0* obj, int a, int b);
extern "C" void func_0205e9b4(struct Entry_0205d6a0* a, int flag);
extern "C" struct TableEntry0217f8c0* func_ov000_02180bec(struct Struct0217f8c0* s);
extern "C" int func_ov000_0217d948(void* objRaw);
extern "C" int func_ov000_0217d8e8(void* objRaw, int limit);
extern "C" void func_ov000_021779e8(void* obj, struct TableEntry0217f8c0* entry, int mode, int arg1, int arg2);
extern "C" void func_ov000_0217d98c(void* obj, int arg1, int arg2);
extern struct Obj0205eaa0 data_021086a4;

// JPN: func_ov000_0217e71c
extern "C" ARM void func_ov000_0217e71c(char* obj, int arg1, int arg2) {
    *(unsigned short*)(obj + 0x1faa) |= 0x100;
    int sum = func_0205eaa8((struct Struct_0205c570*)(obj + 0x188));
    if (sum < 0) {
        sum = 0;
    }
    *(signed char*)(obj + 0x1fa3) = sum;
    if (func_ov000_0217d8e8(obj, 0) != 0) {
        func_0205fd8c(&data_021086a4, 1, 0);
        *(signed char*)(obj + 0x1fa0) = *(signed char*)(obj + 0x1fa0) + 1;
        *(unsigned char*)(obj + *(signed char*)(obj + 0x1fa0) + 0x1f98) = 4;
        struct TableEntry0217f8c0* e = func_ov000_02180bec((struct Struct0217f8c0*)obj);
        func_ov000_021779e8(obj, e, 4, arg1, arg2);
    } else if (func_ov000_0217d948(obj) != 0) {
        func_0205e9b4((struct Entry_0205d6a0*)(obj + 0x188), 0);
        *(unsigned char*)(obj + *(signed char*)(obj + 0x1fa0) + 0x1f98) = 0;
        *(signed char*)(obj + 0x1fa0) = *(signed char*)(obj + 0x1fa0) - 1;
        *(signed char*)(obj + 0x1fa3) = -1;
        func_ov000_0217d98c(obj, arg1, arg2);
    }
}

#endif
