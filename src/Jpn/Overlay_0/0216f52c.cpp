#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

extern "C" void func_ov000_0216ea9c(void* obj, int flagA, int flagB, int flagC);

struct Block0202ecc8 { unsigned int v[12]; };
struct Dst0202ecc8;
extern "C" void func_0202e838(struct Dst0202ecc8* dst, struct Block0202ecc8* src);
extern "C" void func_0202e204(void* obj, int* vec);

extern "C" void func_ov000_0216e960(void* forward, void* position, void* dest);

extern Vector3i data_ov000_02184338;

struct Obj0216f52c {
    char pad0[0x10];
    Vector3i field10;
};

// JPN: func_ov000_0216f52c
extern "C" ARM void func_ov000_0216f52c(struct Obj0216f52c* obj, int idxA, int idxB) {
    GameState* gs = GameState::GetInstance();
    GameObject* a = gs->GetGameObjectByIndex(idxA);
    GameObject* b = gs->GetGameObjectByIndex(idxB);
    if (a == NULL || b == NULL) {
        return;
    }
    func_ov000_0216ea9c(obj, 1, 1, 1);
    Vector3fix posA = a->obj3D_.position_;
    Vector3fix posB = b->obj3D_.position_;
    Vector3fix dir;
    Vector3fix_Subtract(&posA, &posB, &dir);
    Vector3fix_Normalize(&dir, &dir);
    struct Block0202ecc8 block;
    func_ov000_0216e960(&dir, &posB, &block);
    func_0202e838((struct Dst0202ecc8*)obj, &block);
    Vector3i v = data_ov000_02184338;
    int tail[3];
    tail[0] = 0x3244;
    tail[1] = 0;
    tail[2] = 0x1000;
    obj->field10 = v;
    func_0202e204(obj, tail);
}

#endif
