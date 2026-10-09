#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_02163e0c(void* self, int a, int b);
extern "C" void func_ov000_0216ed2c(void* obj, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" void func_0202e204(void* obj, int* vec);
extern "C" void func_ov000_02170910(void* obj, int* srcVec3, int a, int b);

struct Vec3_021628f8 { int v[3]; };

// JPN: func_ov000_021628f8
extern "C" ARM void func_ov000_021628f8(void* self, int flag) {
    GameState::GetInstance();
    ((int)func_ov017_0218c1d0());
    func_ov000_02163e0c(self, 0x26, 0);
    func_ov000_0216ed2c((char*)self + 0x394 + 0x800, 1, 1, 0, 0, 0, 0, 1);
    if (flag == 0) {
        return;
    }
    int* mirrorPtr = *(int**)((char*)self + 0x218);
    if (*(int*)((char*)mirrorPtr + 0x8000 + 0xe20) != 0) {
        return;
    }
    struct Vec3_021628f8 temp1 = *(struct Vec3_021628f8*)((char*)self + 0x4 + 0xc00);
    struct Vec3_021628f8 temp2 = temp1;
    temp2.v[1] += 0x800;
    temp2.v[2] += 0x3000;
    func_0202e204((char*)self + 0x394 + 0x800, temp2.v);
    func_ov000_02170910((char*)self + 0x394 + 0x800, temp1.v, 0xf33, 0);
}

#endif
