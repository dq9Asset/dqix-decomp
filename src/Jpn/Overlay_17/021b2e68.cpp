#if defined(jpn)
#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
extern "C" GameResources* func_ov017_0218c1d0(void);

extern "C" void func_0200ff20(GameState* battleStruct, int value);
extern "C" void* func_0200fb68(GameState* battleStruct);
extern "C" int func_0200ff54(char* obj);
extern "C" void func_020a4628(unsigned char* obj, int mask);
extern "C" void func_020a4618(unsigned char* obj, unsigned char mask);
extern "C" void func_020a4524(void* obj);
extern "C" void func_0203af08(unsigned int* obj, unsigned int mask);
extern "C" void func_0203af40(unsigned int* obj, unsigned int mask);
extern "C" void func_0203af30(unsigned int* obj, unsigned int mask);
extern "C" void func_020c7054(int color, int alpha, int depth, int polygonId, int fogEnable);
extern "C" void func_ov017_0219033c(void* self);

struct Obj_021849bc;
extern "C" int func_ov011_02185abc(struct Obj_021849bc* obj, int mask);

struct Obj021b2200;
extern "C" void func_ov017_021b2918(struct Obj021b2200* self);

extern "C" void* func_02012dac(void);
extern "C" void func_020a2984(void);
extern "C" void func_ov017_0219c80c(int, int, int, int);

struct GlobalSlot_021b2758 { unsigned int field0; int slot; };
extern GlobalSlot_021b2758 data_ov017_021d8cb0;

struct Data02107930_021b2758 { unsigned char pad[0x90]; int f90; unsigned char pad2[4]; int f98; };

union Flags38_021b2758 {
    unsigned int raw;
    struct {
        unsigned int bit0 : 1;
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int : 2;
        unsigned int bit5 : 1;
        unsigned int : 26;
    } b;
};

struct SelfState_021b2758 {
    unsigned char pad0[0x38];
    Flags38_021b2758 field0x38;
    unsigned char pad1[2];
    unsigned char field0x3e;
    unsigned char pad2[1];
    int field0x40;
    int field0x44;
    unsigned char field0x48;
};

// JPN: func_ov017_021b2e68
extern "C" ARM int func_ov017_021b2e68(SelfState_021b2758* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameResources* ov = func_ov017_0218c1d0();
    func_0200ff20(battleStruct, self->field0x44);

    if (data_ov017_021d8cb0.slot != 0) {
        if (func_ov011_02185abc((struct Obj_021849bc*)data_ov017_021d8cb0.slot, 1)) self->field0x38.b.bit0 = 1;
        if (func_ov011_02185abc((struct Obj_021849bc*)data_ov017_021d8cb0.slot, 2)) self->field0x38.raw |= 2;
        if (func_ov011_02185abc((struct Obj_021849bc*)data_ov017_021d8cb0.slot, 4)) self->field0x38.raw |= 4;
        func_ov017_021b2918((struct Obj021b2200*)self);
        func_020a2984();
    }

    func_0203af08((unsigned int*)ov, 0x10);
    if (self->field0x38.b.bit0) {
        func_02012dac();
        func_0203af08((unsigned int*)ov, 4);
        func_ov017_0219c80c(1, 0, 0, 0);
        self->field0x38.raw &= ~2;
        void* p = func_0200fb68(battleStruct);
        if (self->field0x48 != 0) ((char*)p)[0x67] = 1;
        return 5;
    }
    if (self->field0x38.b.bit1) return 6;
    if (self->field0x38.b.bit2) return 7;

    battleStruct->GetUnknownGameObject();
    int flagVal = func_0200ff54((char*)battleStruct);
    unsigned char* ctx = (unsigned char*)func_02012dac();
    if (flagVal != 0) {
        func_020a4628((unsigned char*)flagVal, 2);
        if (self->field0x3e != 0) {
            func_020a4618((unsigned char*)flagVal, 2);
        }
        func_020a4524((void*)flagVal);
    }
    if (ctx != 0) {
        ctx[0x125] &= ~1;
    }

    if (!self->field0x38.b.bit5) {
        func_0203af40((unsigned int*)ov, 0x609fe);
        func_0203af30((unsigned int*)ov, self->field0x40);
    }

    Data02107930_021b2758* d = (Data02107930_021b2758*)LightingManager::GetInstance();
    int f90 = d->f90;
    int idx = d->f98;
    unsigned char* base = ctx + 0x12c;
    if (f90 != 0) idx = f90;
    unsigned short color;
    if (*(int*)(base + 0x304) == 1) {
        color = *(unsigned short*)(base + idx * 2 + 0x8c);
    } else {
        color = *(unsigned short*)(base + idx * 2 + 0x126);
    }
    func_020c7054(color, 0x10, 0x7fff, 0, 0);
    func_ov017_0219033c(ov);
    return 4;
}

#endif
