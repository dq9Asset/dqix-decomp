#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"

struct Flags0202ecfc;
extern "C" void func_0202e86c(struct Flags0202ecfc* p);
extern "C" void func_0202e3e4(unsigned char* obj, unsigned short val);
struct AngleTrig0202e9a4;
extern "C" void func_0202e514(struct AngleTrig0202e9a4* obj, int angle);
extern "C" void func_0202e4b8(unsigned char* obj);
struct HalfwordTriple0202e98c;
extern "C" void func_0202e4fc(struct HalfwordTriple0202e98c* p);
extern "C" void* func_0202e9f4(char* obj);
extern "C" void* func_0202ea04(void* obj);
extern "C" void* func_0202ea14(void* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Vec3_0216ea9c { int x, y, z; };

// JPN: func_ov000_0216ea9c  (semantic: ResetCombatFields_0216ea9c)
extern "C" ARM void func_ov000_0216ea9c(char* obj, int flagA, int flagB, int flagC) {
    *(unsigned char*)(obj + 0x220) = 0;
    if (*(int*)(obj + 0x224) >= 0) {
        struct Vec3_0216ea9c tmp1 = *(struct Vec3_0216ea9c*)(obj + 0x12c);
        struct Vec3_0216ea9c tmp2 = *(struct Vec3_0216ea9c*)(obj + 0x120);
        _ZN8Vector3iaSERKS_((int*)(obj + 0x10), (int*)&tmp1);
        _ZN8Vector3iaSERKS_((int*)(obj + 0x4), (int*)&tmp2);
    }

    *(int*)(obj + 0x224) = -1;
    *(int*)(obj + 0x238) = 0;
    *(int*)(obj + 0x23c) = 0;
    func_0202e86c((struct Flags0202ecfc*)obj);
    *(unsigned char*)(obj + 0x260) = 0;

    if (flagA) {
        func_0202e3e4((unsigned char*)obj, 0);
    }

    if (flagB) {
        func_0202e514((struct AngleTrig0202e9a4*)obj, 0xf000);
    }

    if (flagC) {
        func_0202e4b8((unsigned char*)obj);
        func_0202e4fc((struct HalfwordTriple0202e98c*)obj);
    }

    memset(obj + 0x264, 0, 0x14);
    func_0202e9f4(obj);
    func_0202ea04(obj);
    func_0202ea14(obj);
}

#endif
