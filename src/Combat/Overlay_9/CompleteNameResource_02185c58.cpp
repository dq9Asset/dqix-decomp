#if defined(jpn)
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" unsigned int func_ov009_02185ed8(void* resource);

namespace {
struct NameResourceHeader {
    unsigned int count : 12;
    unsigned int textBytes : 19;
    unsigned int relocated : 1;
};

struct NameOffsetTable {
    NameResourceHeader header;
    unsigned short* offsets;
    char* text;
};

// Load the counted offset table and its text block as one binary-table operation.
#define LOAD_NAME_OFFSET_TABLE(table, alloc, source) do { \
    if ((alloc) != NULL && (source) != NULL) { \
        memcpy(&(table)->header, (source), sizeof(NameResourceHeader)); \
        unsigned int offsetBytes = func_ov009_02185ed8(table); \
        unsigned int textBytes = (table)->header.textBytes; \
        (table)->offsets = offsetBytes ? (unsigned short*)(alloc)->Allocate(offsetBytes) : NULL; \
        (table)->text = textBytes ? (char*)(alloc)->Allocate(textBytes) : NULL; \
        if ((table)->offsets != NULL) memcpy((table)->offsets, (source) + 1, offsetBytes); \
        if ((table)->text != NULL) { \
            unsigned int textOffset = func_ov009_02185ed8(table) + sizeof(NameResourceHeader); \
            memcpy((table)->text, (const char*)(source) + textOffset, textBytes); \
        } \
        (table)->header.relocated = 1; \
    } \
} while (0)

struct NameResource {
    NameOffsetTable table;
    void* supplemental;
    unsigned short supplementalLength;
    short state;
    int tasks[2];
    SafeAllocator* allocator;
};

} // namespace

extern const char* data_020f2a54;
extern const char* data_020f2a50;
extern "C" int func_ov009_02185888(void* resource);

// JPN: func_ov009_02185c58
extern "C" ARM int func_ov009_02185c58(void* resource)
{
    NameResource* self = (NameResource*)resource;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    switch (self->state) {
    case 1:
        self->tasks[0] = loader->QueueLoadFile(data_020f2a54, NULL);
        self->tasks[1] = loader->QueueLoadFile(data_020f2a50, NULL);
        self->state = 2;
        return func_ov009_02185c58(self);
    case 2:
    {
        for (int index = 0; index < 2; index++) {
            if (self->tasks[index] >= 0 && loader->GetTaskStatus(self->tasks[index]) == 0)
                return 0;
        }
        self->state = 3;
        return func_ov009_02185c58(self);
    }
    case 3:
    {
        void* files[2] = { NULL, NULL };
        unsigned int lengths[2] = { 0, 0 };
        int* task = self->tasks;
        void** file = files;
        unsigned int* length = lengths;
        for (int index = 0; index < 2; index++, task++, file++, length++) {
            if (*task >= 0)
                loader->GetLoadedFileByID(*task, file, length);
        }
        SafeAllocator* allocator = self->allocator;
        void* supplemental;
        unsigned int supplementalLength = lengths[1];
        supplemental = files[1];
        if (allocator != NULL && ((files[0] != NULL && lengths[0] != 0) ||
                                  (supplemental != NULL && supplementalLength != 0))) {
            if (files[0] != NULL && lengths[0] != 0) {
                LOAD_NAME_OFFSET_TABLE(&self->table, allocator, (const NameResourceHeader*)files[0]);
            }
            self->supplemental = NULL;
            self->supplementalLength = 0;
            if (supplemental != NULL && supplementalLength != 0) {
                void* copy = allocator->Allocate(supplementalLength);
                if (copy != NULL) {
                    memcpy(copy, supplemental, supplementalLength);
                    self->supplemental = copy;
                    self->supplementalLength = supplementalLength;
                }
            }
        }
        func_ov009_02185888(self);
        return 1;
    }
    }
    return 1;
}
#undef LOAD_NAME_OFFSET_TABLE
#endif
