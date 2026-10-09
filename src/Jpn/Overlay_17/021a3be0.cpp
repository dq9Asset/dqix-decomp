#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

extern "C" void func_020dbc4c(void* p);
extern "C" void* func_02012dac(void);
extern int data_ov017_021d8bbc;

extern "C" void func_ov017_021a3278(void* unused);
extern "C" void _ZN8Object3D7DestroyEv(unsigned char* obj);

extern "C" void* func_0203d484(void);
struct Struct_0203cfb4;
extern "C" void func_0203d4ec(struct Struct_0203cfb4* obj);

struct func_02090100Struct;
extern "C" void func_02090100(struct func_02090100Struct* s);

struct PointerField32c_ffc0;
extern "C" void* func_0200fe1c(struct PointerField32c_ffc0* obj);
struct PointerField330_ffd0;
extern "C" void* func_0200fe2c(struct PointerField330_ffd0* obj);

extern "C" void func_0200fba4(GameState* battleStruct, int id);

struct Foo0207df50;
extern "C" void func_0207ecd0(struct Foo0207df50* p);

// JPN: func_ov017_021a3be0
extern "C" ARM void func_ov017_021a3be0(unsigned char* obj) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* globalPtr = (unsigned char*)func_02012dac();
    int i;
    int j;
    int k;

    if (((SafeAllocator*)(obj + 0xfb0))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + 0xfb0))->Destroy();
        ((SafeAllocator*)(obj + 0xfb0))->ResetAllocatorPointer();
    }

    if (((SafeAllocator*)(obj + 0xf2c))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + 0xf2c))->Destroy();
        ((SafeAllocator*)(obj + 0xf2c))->ResetAllocatorPointer();
    }

    if (((SafeAllocator*)(obj + 0xf2c))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + 0xf2c))->Destroy();
        ((SafeAllocator*)(obj + 0xf2c))->ResetAllocatorPointer();
    }

    if (((SafeAllocator*)(obj + 0x1034))->GetSignedAllocator()) {
        ((SafeAllocator*)(obj + 0x1034))->Destroy();
        ((SafeAllocator*)(obj + 0x1034))->ResetAllocatorPointer();
    }

    func_020dbc4c(&data_ov017_021d8bbc);
    func_ov017_021a3278(obj);

    for (i = 0; i < 0x30; i++) {
        GameObject* c = battleStruct->GetMaybeFieldMonsterByIndex(i + 0x70);
        if (c) {
            _ZN8Object3D7DestroyEv((unsigned char*)c);
        }
    }

    ((SafeAllocator*)(obj + 0xc4))->Reset();
    func_0207ecd0((struct Foo0207df50*)(obj + 0x58c));

    for (j = 0; j < 0x30; j++) {
        GameObject* c = battleStruct->GetMaybeFieldMonsterByIndex(j + 0x70);
        if (c) {
            _ZN8Object3D7DestroyEv((unsigned char*)c);
        }
    }

    func_0203d4ec((struct Struct_0203cfb4*)func_0203d484());
    func_02090100((struct func_02090100Struct*)(globalPtr + 0x26a4));

    if (func_0200fe1c((struct PointerField32c_ffc0*)battleStruct)) {
        func_0200fba4(battleStruct, 0xc9);
    }
    if (func_0200fe2c((struct PointerField330_ffd0*)battleStruct)) {
        func_0200fba4(battleStruct, 0xca);
    }

    for (k = 1; k < 4; k++) {
        if (battleStruct->GetGameObjectByIndex(k + 0xca)) {
            func_0200fba4(battleStruct, k + 0xca);
        }
    }
    func_0200fba4(battleStruct, 0xce);
}

#endif
