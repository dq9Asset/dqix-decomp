#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct NotifyEntriesStruct0207f8bc;
extern "C" void func_02080628(struct NotifyEntriesStruct0207f8bc* p);
struct Struct02074bf4;
extern "C" void func_02075d80(struct Struct02074bf4* obj);
extern "C" int DisableSubBGVRAMBanks(void);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToSubObj(int value);
struct List0204afb4;
extern "C" void func_0204bdd4(struct List0204afb4* obj);
struct Obj0204c754;
extern "C" void func_0204d570(struct Obj0204c754* obj);

// JPN: func_ov003_02167250  (semantic: ResetListsAndDestroyAllocators_02167250)
extern "C" ARM void func_ov003_02167250(char* obj) {
    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(obj + 0x34) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(obj + 0x34)));
        *(int*)(obj + 0x34) = -1;
    }

    volatile unsigned int* p1 = (volatile unsigned int*)0x4001010;
    p1[0] = 0;
    p1[1] = 0;

    if (*(void**)(obj + 0x10) != 0) {
        func_02080628(*(struct NotifyEntriesStruct0207f8bc**)(obj + 0x10));
    }
    func_02075d80((struct Struct02074bf4*)(obj + 0x1c));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0x1f00) | (*(int*)(obj + 0x30) << 8);

    DisableSubBGVRAMBanks();
    MapVRAMBanksToSubBG(*(int*)(obj + 0x14));
    MapVRAMBanksToSubObj(*(int*)(obj + 0x18));

    if (*(void**)(obj + 8) != 0) {
        func_0204bdd4(*(struct List0204afb4**)(obj + 8));
        *(int*)(obj + 8) = 0;
    }
    if (*(void**)(obj + 0xc) != 0) {
        func_0204d570(*(struct Obj0204c754**)(obj + 0xc));
        *(int*)(obj + 0xc) = 0;
    }
    if (*(void**)(obj + 0x10) != 0) {
        func_02080628(*(struct NotifyEntriesStruct0207f8bc**)(obj + 0x10));
        *(int*)(obj + 0x10) = 0;
    }
    if (*(int*)obj != 0) {
        *(int*)obj = 0;
    }
    if (*(int*)(obj + 4) == 0) return;

    for (int i = 0; i < 3; i++) {
        if (((SafeAllocator*)(*(char**)(obj + 4) + i * 0x14))->GetSignedAllocator() != 0) {
            ((SafeAllocator*)(*(char**)(obj + 4) + i * 0x14))->Destroy();
        }
    }
}

#endif
