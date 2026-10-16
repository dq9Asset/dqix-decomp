#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

#if defined(jpn)
struct List02072a28;
struct ScriptStringState0207267c {
    unsigned char skipCount;
    unsigned char padding;
    unsigned short filterCount;
    char* destination;
    short* filterIds;
    SafeAllocator* allocator;
    List02072a28* list;
};
extern ScriptStringState0207267c data_02108db0;
extern int data_020f0cc8;

// JPN: func_02073864
extern "C" ARM void func_02073864(void* list, void* allocator, const char* path,
    int filterIds, unsigned short filterCount, unsigned char skipCount) {
    unsigned int size;
    BackgroundLoader::AddLockGlobal();
    void* file = LoadFileIntoMemory(path, data_0211e33c, &size);
    if (file != 0) {
        data_02108db0.list = (List02072a28*)list;
        data_02108db0.allocator = (SafeAllocator*)allocator;
        data_02108db0.filterIds = (short*)filterIds;
        data_02108db0.filterCount = filterCount;
        data_02108db0.destination = 0;
        data_02108db0.skipCount = skipCount;
        Script runner;
        runner.Initialize();
        runner.SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0cc8);
        runner.Load(file, size);
        runner.Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
#endif
