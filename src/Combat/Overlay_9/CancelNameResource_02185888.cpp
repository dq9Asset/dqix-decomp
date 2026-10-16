#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct NameResourceHeader {
    unsigned int count : 12;
    unsigned int textBytes : 19;
    unsigned int relocated : 1;
};

struct NameResource {
    NameResourceHeader header;
    unsigned short* offsets;
    char* text;
    void* supplemental;
    unsigned short supplementalLength;
    short state;
    int tasks[2];
    SafeAllocator* allocator;
};

// JPN: func_ov009_02185888
extern "C" ARM int func_ov009_02185888(void* resource)
{
    NameResource* self = (NameResource*)resource;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* task = self->tasks;
    for (int index = 0; index < 2; index++, task++) {
        if (*task >= 0) {
            loader->RemoveTask(*task);
            *task = -1;
        }
    }
    self->state = 0;
    self->allocator = NULL;
    return 1;
}
#endif
