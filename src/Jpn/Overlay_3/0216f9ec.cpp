#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "System/Cache.h"
#include "std_library_functions.h"

extern "C" void func_0205b830(void* obj);

struct Struct02074bd0;
extern "C" void func_02075d5c(struct Struct02074bd0* obj);

struct Entry_0205d6a0;
extern "C" void func_0205e9b4(struct Entry_0205d6a0* a, int flag);

struct Cont0205d1e0;
extern "C" void func_0205e510(struct Cont0205d1e0* obj);

struct Cont0205d274;
extern "C" void func_0205e5a4(struct Cont0205d274* obj);

struct Obj0205d2bc;
extern "C" void func_0205e5ec(struct Obj0205d2bc* obj);

extern "C" void func_0205e378(void* obj);

extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

// JPN: func_ov003_0216f9ec  (semantic: ResetGraphicsAndEntries_0216f9ec)
extern "C" ARM void func_ov003_0216f9ec(void* self) {
    func_0205b830((char*)self + 0x68);
    if (((SafeAllocator*)((char*)self + 0xbc))->GetSignedAllocator() != 0) {
        ((SafeAllocator*)((char*)self + 0xbc))->Destroy();
    }
    func_02075d5c((struct Struct02074bd0*)((char*)self + 0x48));
    unsigned int* reg = (unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | (*(int*)((char*)self + 0x5c) << 8);
    void* entry = *(void**)((char*)self + 0x3c);
    if (entry != 0) {
        func_0205e9b4((struct Entry_0205d6a0*)entry, 1);
        entry = *(void**)((char*)self + 0x3c);
        func_0205e510((struct Cont0205d1e0*)entry);
        entry = *(void**)((char*)self + 0x3c);
        func_0205e5a4((struct Cont0205d274*)entry);
        entry = *(void**)((char*)self + 0x3c);
        func_0205e5ec((struct Obj0205d2bc*)entry);
        entry = *(void**)((char*)self + 0x3c);
        func_0205e378(entry);
    }
    *(void**)((char*)self + 0x3c) = 0;
    void* buf = *(void**)((char*)self + 0x14);
    memset(buf, 0, 0x20);
    buf = *(void**)((char*)self + 0x14);
    CleanInvalidateCacheRange(buf, 0x20);
    buf = *(void**)((char*)self + 0x14);
    LoadToMainBG1CharacterData((int)buf, 0, 0x20);
    *(unsigned short*)0x4000050 = 0;
}

#endif
