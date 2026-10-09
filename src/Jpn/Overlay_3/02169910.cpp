#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov003_021693bc(void* obj);
extern "C" int func_ov003_02169334(void* obj);
extern "C" void func_ov003_0216a588(void* obj, int mode, int flag);
extern "C" void func_ov003_0216a62c(void* obj);

extern "C" void func_0205e228(void* obj);
extern "C" void func_0205e234(void* obj);
extern "C" void func_0205e240(void* obj);

struct Struct0205cf1c;
extern "C" void func_0205e24c(struct Struct0205cf1c* s);

struct Struct_0205c570;
extern "C" int func_0205eaa8(struct Struct_0205c570* s);

struct Obj0205eaa0;
extern "C" void func_0205fd8c(struct Obj0205eaa0* obj, int a, int b);

extern "C" int func_ov003_0216937c(void* obj);

extern int data_021086a4;

// JPN: func_ov003_02169910  (semantic: StepStateMachine02169910)
extern "C" ARM int func_ov003_02169910(void* p) {
    char* obj = (char*)p;
    unsigned char state = *(unsigned char*)(obj + 0x4e5);
    if (state == 0) {
        func_ov003_021693bc(obj);
        func_0205e228(obj + 0xe0);
        func_0205e234(obj + 0xe0);
        *(unsigned char*)(obj + 0x4e5) = *(unsigned char*)(obj + 0x4e5) + 1;
    } else if (state == 1) {
        *(unsigned char*)(obj + 0x59b) |= 1;
        int e = func_0205eaa8((struct Struct_0205c570*)(obj + 0xe0));
        *(unsigned char*)(obj + 0x4e9) = (unsigned char)e;
        if (func_ov003_02169334(obj) != 0) {
            func_ov003_0216a588(obj, 1, 1);
            *(unsigned char*)(obj + 0x59b) &= ~1;
            func_ov003_0216a62c(obj);
            *(unsigned char*)(obj + 0x4e6) = 0;
            func_0205fd8c((struct Obj0205eaa0*)&data_021086a4, 1, 0);
            func_0205e240(obj + 0xe0);
            func_0205e24c((struct Struct0205cf1c*)(obj + 0xe0));
            *(unsigned char*)(obj + 0x4e5) = 0;
            return *(signed char*)(obj + 0x4e9);
        } else {
            if (func_ov003_0216937c(obj) != 0) {
                *(unsigned char*)(obj + 0x59b) &= ~1;
                func_0205e240(obj + 0xe0);
                func_0205e24c((struct Struct0205cf1c*)(obj + 0xe0));
                *(unsigned char*)(obj + 0x4e5) = 0;
                return -2;
            }
        }
    }
    return -1;
}

#endif
