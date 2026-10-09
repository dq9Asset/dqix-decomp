#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov003_0215c7fc(void* obj);
extern "C" int func_ov003_0215c768(void* obj);
extern "C" void func_ov003_0215d334(void* obj, int a, int b, int c);

extern "C" void func_0205e228(void* obj);
extern "C" void func_0205e234(void* obj);
extern "C" void func_0205e240(void* obj);

struct Struct0205cf1c;
extern "C" void func_0205e24c(struct Struct0205cf1c* s);

struct Struct_0205c570;
extern "C" int func_0205eaa8(struct Struct_0205c570* s);

struct Obj0205eaa0;
extern "C" void func_0205fd8c(struct Obj0205eaa0* obj, int a, int b);

extern "C" int func_ov003_0215c7b0(void* obj, int flag);

extern int data_021086a4;

// JPN: func_ov003_0215cba4
extern "C" ARM int func_ov003_0215cba4(void* p) {
    char* obj = (char*)p;
    unsigned char state = *(unsigned char*)(obj + 0x581);
    if (state == 0) {
        func_ov003_0215c7fc(obj);
        func_0205e228(obj + 0xf4);
        func_0205e234(obj + 0xf4);
        *(unsigned char*)(obj + 0x581) = *(unsigned char*)(obj + 0x581) + 1;
    }
    if (state == 1) {
        *(unsigned char*)(obj + 0x59f) |= 1;
        int e = func_0205eaa8((struct Struct_0205c570*)(obj + 0xf4));
        *(unsigned char*)(obj + 0x584) = (unsigned char)e;
        if (func_ov003_0215c768(obj) != 0) {
            unsigned char v = *(unsigned char*)(obj + 0x59f);
            int masked = v & ~1;
            *(unsigned char*)(obj + 0x59f) = masked;
            func_ov003_0215d334(obj, 1, 1, masked);
            func_0205fd8c((struct Obj0205eaa0*)&data_021086a4, 1, 0);
            func_0205e240(obj + 0xf4);
            func_0205e24c((struct Struct0205cf1c*)(obj + 0xf4));
            *(unsigned char*)(obj + 0x581) = 0;
            signed char idx = *(signed char*)(obj + 0x584);
            return *(signed char*)(obj + idx + 0x58a);
        } else {
            if (func_ov003_0215c7b0(obj, 1) != 0) {
                func_0205e240(obj + 0xf4);
                func_0205e24c((struct Struct0205cf1c*)(obj + 0xf4));
                *(unsigned char*)(obj + 0x581) = 0;
                return -2;
            }
        }
    }
    return -1;
}

#endif
