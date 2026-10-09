#if defined(jpn)
#include <globaldefs.h>

struct S020a3570;
struct GlobalObj0202e6a8;
struct Obj0202e71c;

extern "C" void func_020a4a8c(void* obj);
extern "C" int func_020a52e8(struct S020a3570* p);
extern "C" void func_ov000_02170b00(void* obj);
extern "C" void func_ov000_02170164(void* obj);
extern "C" void func_ov000_021707fc(void* obj);
extern "C" int func_0202e360(void* obj);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int angle);
extern "C" void func_0202e218(struct GlobalObj0202e6a8* obj, int value);
extern "C" int func_0202e370(void* obj);
extern "C" void func_0202e28c(struct Obj0202e71c* obj, int p);
extern "C" void func_ov000_021709e4(void* obj);

struct Struct0216eb90 {
    unsigned char pad[0x238];
    int f238;
    int f23c;
};

// JPN: func_ov000_0216eb90
extern "C" ARM void func_ov000_0216eb90(struct Struct0216eb90* obj) {
    func_020a4a8c(obj);
    if (func_020a52e8((struct S020a3570*)obj) != 0) {
        func_ov000_02170b00(obj);
        return;
    }
    func_ov000_02170164(obj);
    func_ov000_021707fc(obj);
    if (obj->f238 != 0) {
        int a = func_0202e360(obj);
        int angle = _Z22fix32ReduceAngle0To2Pii(a + obj->f238);
        func_0202e218((struct GlobalObj0202e6a8*)obj, angle);
    }
    if (obj->f23c != 0) {
        int cur78 = func_0202e370(obj);
        int f23c = obj->f23c;
        int limit = (f23c < cur78) ? (cur78 + f23c) : 0;
        if (limit < 0x3000) {
            limit = 0x3000;
        }
        func_0202e28c((struct Obj0202e71c*)obj, limit);
    }
    func_ov000_021709e4(obj);
    func_ov000_02170b00(obj);
}

#endif
