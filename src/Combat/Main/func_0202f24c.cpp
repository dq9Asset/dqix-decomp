#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/NarcHandle.h"

void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
void LoadEightEntriesFromTable_0202f310(MessageSlotController*, void*, void*);

extern AllocatorUnion data_02114e20;
extern char data_020ef7ac[];
extern char data_0211e33c[];
extern char data_020ef7c0[];

// USA: func_0202f24c  (semantic: InitIconArchiveAndLoadEntries_0202f24c)
extern "C" ARM void func_0202f24c(MessageSlotController* obj) {
    if (obj->allocator == 0) {
        obj->allocator = static_cast<SafeAllocator*>(AllocateAligned4_02012d88(&data_02114e20, 0x14));
        obj->allocator->ResetAllocatorPointer();
        void* buf = AllocateAligned4_02012d88(&data_02114e20, 0xf08);
        obj->allocator->CreateTypeA(buf, 0xf08);
        obj->allocator->Reset();
    } else {
        obj->allocator->Reset();
    }
    BackgroundLoader::AddLockGlobal();

    unsigned int size;
    void* fileData = LoadFileIntoMemory(data_020ef7ac, data_0211e33c, &size);
    if (fileData != 0) {
        NarcHandle handle;
        if (handle.Initialize(data_020ef7c0, (const unsigned char*)fileData)) {
            LoadEightEntriesFromTable_0202f310(obj, obj->allocator, fileData);
            handle.Destroy();
        }
    }
    BackgroundLoader::RemoveLockGlobal();
}
