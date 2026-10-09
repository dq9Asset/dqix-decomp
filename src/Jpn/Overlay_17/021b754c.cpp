#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "GameState/GameState.h"
extern "C" GameResources* func_ov017_0218c1d0(void);

extern "C" void func_ov000_02161c6c(void);
extern "C" void func_02012b6c(AllocatorUnion* alloc, void* data);
extern "C" void func_020a3bcc(int flag);
extern "C" void func_020a3cc4(int flag);
extern "C" void func_02039218(void* obj);
struct Obj02053f7c;
extern "C" void func_020552f4(Obj02053f7c* obj, short a, int b);
extern "C" ARM void func_ov017_021c4438(unsigned short tag);
extern "C" void func_0203af08(unsigned int* obj, unsigned int mask);
extern "C" void func_020a2984(void);
struct ListHead02046b60;
extern "C" int func_02047980(ListHead02046b60* list, int id);
extern "C" void* func_02012dac(void);
extern "C" void func_02017b08(void* obj);
extern "C" void* func_020d8608(void);
struct FlagWord020466f4;
extern "C" void func_02047514(FlagWord020466f4* word, unsigned int mask);
struct func_020a52f0Struct;
extern "C" void func_020a52f0(func_020a52f0Struct* s);

extern AllocatorUnion data_02114ac0;

// JPN: func_ov017_021b754c
extern "C" ARM void func_ov017_021b754c(char* self) {
    char* ov = (char*)func_ov017_0218c1d0();
    unsigned short f6b6 = *(unsigned short*)(self + 0x600 + 0xb6);
    int f28 = *(int*)(self + 0x28);
    unsigned int flag2000 = f6b6 & 0x2000;

    unsigned short val44ae = *(unsigned short*)(ov + 0x4100 + 0xfe);
    unsigned short* addr44ae = (unsigned short*)(ov + 0xfe + 0x4100);
    if (val44ae == *(unsigned short*)(self + 0x24)) {
        addr44ae[0] = 0;
        addr44ae[1] = 0;
    }

    if (*(int*)(self + 0x6ac) != 0) {
        func_ov000_02161c6c();
    }

    SafeAllocator* alloc = (SafeAllocator*)(self + 0x8);
    void* p = alloc->GetSignedAllocator();
    if (p) {
        alloc->Destroy();
        func_02012b6c(&data_02114ac0, p);
    }

    if (*(unsigned short*)(self + 0x600 + 0xb6) & 0x800) {
        func_020a3bcc(1);
        func_020a3cc4(1);
    }

    GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
    func_02039218(combatant);
    func_020552f4((Obj02053f7c*)combatant, 0, 0);
    func_ov017_021c4438(0);

    alloc->ResetAllocatorPointer();
    func_020a52f0((func_020a52f0Struct*)(self + 0x1c));

    *(int*)(self + 0x6ac) = 0;
    *(int*)(self + 0x6b0) = 0;
    *(unsigned short*)(self + 0x600 + 0xb4) = 1;
    *(unsigned short*)(self + 0x600 + 0xb6) = 0;
    *(int*)(self + 0x6b8) = 0;

    func_0203af08((unsigned int*)ov, 0x800);
    func_020a2984();

    int* p36fc = *(int**)(ov + 0x3000 + 0x4ec);
    char* p3b5c = *(char**)(ov + 0x3000 + 0x93c);
    int useDefault;
    if (f28 < 0 || func_02047980((ListHead02046b60*)p36fc, 4) == 0) {
        useDefault = 1;
    } else {
        useDefault = 0;
    }

    void* ret = func_02012dac();
    if (useDefault != 0 && flag2000 == 0 && *(unsigned char*)(p3b5c + 8) != 0) {
        func_02017b08(ret);
    }

    func_02047514((FlagWord020466f4*)func_020d8608(), 0x40000);
}

#endif
