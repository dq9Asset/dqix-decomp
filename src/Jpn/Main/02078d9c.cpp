#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202a9d0(void);
extern "C" int func_0202c094(void*);
extern "C" int func_0202b388(int* obj);

struct SearchStruct0202c1a4;
extern "C" signed char func_0202bd54(struct SearchStruct0202c1a4* obj);

struct Vec3 {
    int x;
    int y;
    int z;
};
extern "C" struct Vec3 func_02033c3c(GameObject* combatant);

struct Obj02033834;
extern "C" void func_0203336c(struct Obj02033834* obj, int arg);

struct Vec3Fixed02030e2c {
    int x;
    int y;
    int z;
};
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

struct Obj02033b68;
extern "C" void func_020336a0(struct Obj02033b68* obj, int newVal);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);
extern "C" int _s32_div_f(int a, int b);

extern "C" void func_ov017_021c972c(int a, int b, int c, struct Vec3 v, int d, int e, int f);

struct Entity02078d9c {
    char pad0[0x2];
    short f2;
    short f4;
    char pad6[0x44 - 0x6];
    struct Vec3 f44;
    char pad50[0xb2 - 0x50];
    short fb2;
    short fb4;
    char padb6[0x158 - 0xb6];
    struct Vec3 f158;
    char pad164[0x166 - 0x164];
    unsigned short f166;
    char pad168[0x17a - 0x168];
    unsigned char f17a;
    char pad17b[0x17d - 0x17b];
    unsigned char f17d;
};

// JPN: func_02078d9c
extern "C" ARM int func_02078d9c(struct Entity02078d9c* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->f166);
    if (combatant == NULL) {
        return 0;
    }

    self->f17d |= 0x40;
    int angle = 0;
    void* g = func_0202a9d0();
    if (func_0202c094(g)) {
        struct Vec3 posCopy = func_02033c3c(combatant);
        struct Vec3 delta;
        Vector3fix_Subtract((const Vector3fix*)&posCopy, (const Vector3fix*)&self->f44, (Vector3fix*)&delta);
        Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
        delta.x = -delta.x;
        delta.y = -delta.y;
        delta.z = -delta.z;
        angle = ((int (*)(int))fix32_Atan2)(delta.x);
        func_0203336c((struct Obj02033834*)self, angle);
        delta.y = 0;
        _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_((struct Vec3Fixed02030e2c*)&delta, 0xa000, (struct Vec3Fixed02030e2c*)&delta);
        Vector3fix_Add((const Vector3fix*)&self->f44, (const Vector3fix*)&delta, (Vector3fix*)&self->f158);
    }

    self->fb4 = 0x1c2;
    self->fb2 = 0x1c2;
    func_020336a0((struct Obj02033b68*)self, 1);

    GameObject* protagonist = battleStruct->GetProtagonist();
    unsigned short a = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)protagonist);
    unsigned short b = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)self);
    if (a == b) {
        _ZN8Object3D11DisableFlagEi((unsigned char*)self, 0x80);
    }
    self->f17a = 0;

    if (func_0202b388((int*)g)) {
        if (func_0202bd54((struct SearchStruct0202c1a4*)g) == 0) {
            int cid = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)self);
            int f2val = self->f2;
            struct Vec3* vp = &self->f158;
            int rem = (self->f4 - 0x70) % 0xc;
            if (rem >= 0 && rem < 0xc) {
                struct Vec3 v = *vp;
                func_ov017_021c972c(cid, rem, f2val, v, angle, 6, self->f166);
            }
        }
    }
    return 1;
}

#endif
