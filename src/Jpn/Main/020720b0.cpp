#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct Struct02030b7c {
    int field0;
    void* field4;
};
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

extern "C" int func_020d4a54(const char* s);

struct MsgArgs020720b0 {
    struct Variant02030b0c v0;
    struct Variant02030b0c v1;
    struct Variant02030b0c v2;
    struct Variant02030b0c v3;
    struct Variant02030b0c v4;
    struct Variant02030b0c v5;
    struct Variant02030b0c v6;
    struct Struct02030b7c v7;
};

struct MsgEntry020720b0 {
    int id;
    char text[0x1e];
    char flag1;
    char flag2;
};

struct MsgQueueState020720b0 {
    unsigned char forceFlag;          // 0x0
    char pad1[7];
    struct MsgEntry020720b0* entries; // 0x8
    char pad2[4];
    int limit;                        // 0x10
    char pad3[8];
    int targetValue;                  // 0x1c
    char pad4[4];
    int count;                        // 0x24
};
extern struct MsgQueueState020720b0 data_02108cb4;

// JPN: func_020720b0  (semantic: AddMessageLogEntry020720b0)
extern "C" ARM int func_020720b0(struct MsgArgs020720b0* args) {
    int v0;
    int key;
    int i;
    void* text;
    int len;

    if (data_02108cb4.limit <= data_02108cb4.count) {
        return 0;
    }

    v0 = _ZNK6Script9Parameter5ToIntEv(&args->v0);
    _ZNK6Script9Parameter5ToIntEv(&args->v1);

    if (v0 == data_02108cb4.targetValue || data_02108cb4.forceFlag != 0) {
        _ZNK6Script9Parameter5ToIntEv(&args->v2);
        _ZNK6Script9Parameter5ToIntEv(&args->v3);
        _ZNK6Script9Parameter5ToIntEv(&args->v4);
        key = _ZNK6Script9Parameter5ToIntEv(&args->v5);

        for (i = 0; i < data_02108cb4.count; i++) {
            if (data_02108cb4.entries[i].id == key) {
                if (key < 0x5208 || key >= 0x9c40) {
                    return 0;
                }
            }
        }

        data_02108cb4.entries[data_02108cb4.count].id = key;

        _ZNK6Script9Parameter5ToIntEv(&args->v6);
        text = _ZNK6Script9Parameter8ToStringEv(&args->v7);
        if (!text) {
            return 0;
        }

        memset(data_02108cb4.entries[data_02108cb4.count].text, 0, 0x20);

        len = func_020d4a54((const char*)text);
        if (len < 0x1f) {
            memcpy(data_02108cb4.entries[data_02108cb4.count].text, text, len);
        } else {
            memcpy(data_02108cb4.entries[data_02108cb4.count].text, text, 0x1e);
            data_02108cb4.entries[data_02108cb4.count].flag1 = 0;
        }

        data_02108cb4.entries[data_02108cb4.count].flag2 = 0;
        data_02108cb4.count++;
    }

    return 1;
}

#endif
