#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" int func_ov017_0218c1d0(void);
extern "C" int func_02042940();
struct StructAllocGroup0208ba54;
extern "C" void func_0208c348(struct StructAllocGroup0208ba54* self);
extern "C" void func_02012b6c(AllocatorUnion* alloc, void* data);
extern "C" void func_ov008_021856a8(void* p);
extern "C" void func_020ddcd8(int mode);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(int base, int a, int b);
struct Obj_021b994c;
extern "C" void func_ov017_021b9e48(struct Obj_021b994c* obj);
extern "C" void func_020a2984(void);

extern int data_02114ac0;

// JPN: func_ov017_021b9278
extern "C" ARM void func_ov017_021b9278(unsigned char* self) {
    int handle = func_ov017_0218c1d0();
    if (*(int*)(self + 0x120) > -1) {
        int field4 = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(field4))->RemoveTask((int)(*(int*)(self + 0x120)));
    }

    if (self[0x137] == 0) {
        *(int*)((char*)func_02042940() + 0x4c) = 0;
        func_0208c348((struct StructAllocGroup0208ba54*)(self + 0x30));
        SafeAllocator* allocA = (SafeAllocator*)(self + 0x8);
        void* pA = allocA->GetSignedAllocator();
        if (pA) {
            allocA->Destroy();
            func_02012b6c((AllocatorUnion*)&data_02114ac0, pA);
        }
    }

    if (self[0x128] != 0) {
        func_ov008_021856a8(*(void**)(self + 0x118));
        SafeAllocator* allocB = (SafeAllocator*)(self + 0x1c);
        void* pB = allocB->GetSignedAllocator();
        if (pB) {
            allocB->Destroy();
            func_02012b6c((AllocatorUnion*)&data_02114ac0, pB);
        }
        *(int*)(self + 0x118) = 0;

        volatile unsigned short* reg = (volatile unsigned short*)0x4001008;
        reg[0] = (reg[0] & ~3) | 1;
        reg[1] = (reg[1] & ~3) | 2;
        reg[2] = reg[2] & ~3;

        func_020ddcd8(0);
        _Z16SetSubBrightnessP13GameResourcesii(handle, 0, 0xf);
    }

    func_ov017_021b9e48((struct Obj_021b994c*)self);
    func_020a2984();
}

#endif
