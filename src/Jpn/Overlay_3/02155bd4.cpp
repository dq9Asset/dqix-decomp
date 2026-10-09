#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct Sizes02155bd4 { unsigned int values[8]; };
extern Sizes02155bd4 data_ov003_0217e020;
extern "C" void func_020e4030(void*, int, int, void*, SafeAllocator*, int, int);
extern "C" void func_0204bd84(void*);
extern "C" void func_0204d4a4(void*);
extern "C" void func_020805c4(void*);
extern "C" void func_0205b510(void*);
extern "C" void func_ov003_02154eec(void*);
extern "C" void func_ov003_02154e60(void*, SafeAllocator*);

// JPN: func_ov003_02155bd4
extern "C" ARM void func_ov003_02155bd4(char* self, SafeAllocator* allocator) {
    if (!allocator) return;
    *(void**)(self + 0) = allocator->Allocate(0xa0);
    *(void**)(self + 4) = allocator->Allocate(0x60);
    *(void**)(self + 0xc) = allocator->Allocate(0x4c00);
    *(void**)(self + 0x10) = allocator->Allocate(0x40);
    *(void**)(self + 0x14) = allocator->Allocate(0x2a0);
    *(void**)(self + 0x18) = allocator->Allocate(0x68);
    *(void**)(self + 0x20) = allocator->Allocate(0x30);
    *(void**)(self + 0x24) = allocator->Allocate(0x190);
    *(void**)(self + 0x28) = allocator->Allocate(8);
    *(void**)(self + 0x1c) = allocator->Allocate(0x24);
    func_020e4030(*(void**)(self + 0x1c), 0, 1, *(void**)(self + 0x28), allocator, 3, 0x40);
    Sizes02155bd4 sizes = data_ov003_0217e020;
    for (unsigned char i = 0; i < 8; i++) {
        SafeAllocator* array = *(SafeAllocator**)self;
        unsigned int size = sizes.values[i];
        array[i].ResetAllocatorPointer();
        array[i].CreateTypeA(allocator->Allocate(size), size);
        array[i].Reset();
    }
    for (unsigned char i = 0; i < 2; i++)
        func_0204bd84(*(char**)(self + 0x10) + i * 0x20);
    for (unsigned char i = 0; i < 3; i++)
        func_0204d4a4(*(char**)(self + 0x14) + i * 0xe0);
    func_020805c4(*(void**)(self + 0x18));
    for (unsigned char i = 0; i < 12; i++)
        (*(int**)(self + 0x20))[i] = 0;
    for (unsigned char i = 0; i < 10; i++)
        func_0205b510(*(char**)(self + 0x24) + i * 0x28);
    GameState::GetInstance();
    char* obj = *(char**)(self + 4);
    func_ov003_02154eec(obj);
    func_ov003_02154e60(obj, allocator);
    *(char**)(obj + 8) = self + 0x90;
    *(char**)(obj + 4) = self + 0xfc;
    *(char**)(obj + 0xc) = self + 0x114;
    *(char*)(obj + 0x59) = -1;
}

#endif
