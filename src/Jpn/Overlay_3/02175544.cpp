#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov003_02175604(void* self);
extern "C" int func_ov003_02175730(void* self);

extern "C" int func_020121c0(unsigned short* obj, int mask);

struct Obj0205eaa0;
extern "C" void func_0205fd8c(struct Obj0205eaa0* obj, int a, int b);

struct Obj2081;
extern "C" void func_02080908(struct Obj2081* obj, int key);

struct Obj0208203c;
extern "C" void func_02082978(struct Obj0208203c* obj);

struct Obj020e25e8;
extern "C" void func_020e4188(struct Obj020e25e8* obj);

extern unsigned short data_02114ad0;
extern struct Obj0205eaa0 data_021086a4;

// JPN: func_ov003_02175544  (semantic: RunTurnCheck_02175544)
extern "C" ARM int func_ov003_02175544(unsigned char* self) {
    *(void**)(self + 0xf74) = self + 0xf7e;
    int result = 0;
    if (func_ov003_02175604(self) != 0) {
        goto dispatch;
    }
    if (func_020121c0(&data_02114ad0, 0x200) == 0) {
        goto alt;
    }
dispatch:
    func_0205fd8c(&data_021086a4, 1, 0);
    result = -1;
    if (*(short*)(self + 0xf7e) == 2) {
        result = 1;
    }
    goto merge;
alt:
    if (func_ov003_02175730(self) != 0) {
        result = -1;
    }
merge:
    if (result != 0) {
        short key = *(short*)(self + 0xf7a);
        func_02080908(*(struct Obj2081**)(self + 0x818), key);
        func_02082978((struct Obj0208203c*)(self + 0x808));
        *(void**)(self + 0xf74) = 0;
    }
    if (*(void**)self != 0 && result != 0) {
        func_020e4188(*(struct Obj020e25e8**)self);
    }
    return result;
}

#endif
