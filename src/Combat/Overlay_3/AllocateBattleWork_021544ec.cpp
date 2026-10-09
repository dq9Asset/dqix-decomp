#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct BattleWorkAllocationSizes { unsigned int values[8]; };
extern BattleWorkAllocationSizes data_ov003_0217f320;
struct EntryManager020e2490;
void InitEntryManager020e2490(EntryManager020e2490*, int, int, void*, SafeAllocator*, int, unsigned char);
struct List0204af64;
void ResetList0204af64(List0204af64*);
extern "C" void func_0204c684(void*);
extern "C" void func_0207f84c(void*);
struct Struct0205a198;
void Init0205a198(Struct0205a198*);
extern "C" void func_ov003_0215376c(void*);
extern "C" void func_ov003_021536e0(void*, SafeAllocator*);

#if defined(jpn)
enum { kNotificationBufferSize = 0x68, kEntryCount = 3 };
#else
enum { kNotificationBufferSize = 0x80, kEntryCount = 4 };
#endif

// USA: func_ov003_021544ec
// JPN: func_ov003_02155bd4
extern "C" ARM void func_ov003_021544ec(char* self, SafeAllocator* allocator) {
    if (!allocator) return;
    *(void**)(self + 0) = allocator->Allocate(0xa0);
    *(void**)(self + 4) = allocator->Allocate(0x60);
    *(void**)(self + 0xc) = allocator->Allocate(0x4c00);
    *(void**)(self + 0x10) = allocator->Allocate(0x40);
    *(void**)(self + 0x14) = allocator->Allocate(0x2a0);
    *(void**)(self + 0x18) = allocator->Allocate(kNotificationBufferSize);
    *(void**)(self + 0x20) = allocator->Allocate(0x30);
    *(void**)(self + 0x24) = allocator->Allocate(0x190);
    *(void**)(self + 0x28) = allocator->Allocate(8);
    *(void**)(self + 0x1c) = allocator->Allocate(0x24);
    InitEntryManager020e2490(*(EntryManager020e2490**)(self + 0x1c), 0, 1, *(void**)(self + 0x28), allocator, kEntryCount, 0x40);
    BattleWorkAllocationSizes sizes = data_ov003_0217f320;
    for (unsigned char i = 0; i < 8; i++) {
        SafeAllocator* array = *(SafeAllocator**)self;
        unsigned int size = sizes.values[i];
        array[i].ResetAllocatorPointer();
        array[i].CreateTypeA(allocator->Allocate(size), size);
        array[i].Reset();
    }
    for (unsigned char i = 0; i < 2; i++)
        ResetList0204af64((List0204af64*)(*(char**)(self + 0x10) + i * 0x20));
    for (unsigned char i = 0; i < 3; i++)
        func_0204c684(*(char**)(self + 0x14) + i * 0xe0);
    func_0207f84c(*(void**)(self + 0x18));
    for (unsigned char i = 0; i < 12; i++)
        (*(int**)(self + 0x20))[i] = 0;
    for (unsigned char i = 0; i < 10; i++)
        Init0205a198((Struct0205a198*)(*(char**)(self + 0x24) + i * 0x28));
    GameState::GetInstance();
    char* obj = *(char**)(self + 4);
    func_ov003_0215376c(obj);
    func_ov003_021536e0(obj, allocator);
    *(char**)(obj + 8) = self + 0x90;
    *(char**)(obj + 4) = self + 0xfc;
    *(char**)(obj + 0xc) = self + 0x114;
    *(char*)(obj + 0x59) = -1;
}
