#if defined(jpn)
#include <globaldefs.h>

struct QueueStruct0215a668 { unsigned char pad[0x589]; unsigned char count; unsigned char list[6]; };

// JPN: func_ov003_0215a668
extern "C" ARM void func_ov003_0215a668(struct QueueStruct0215a668* obj, int flags) {
    obj->count = 0;
    if (flags & 1) obj->list[obj->count++] = 0;
    if (flags & 2) obj->list[obj->count++] = 1;
    if (flags & 4) obj->list[obj->count++] = 2;
    if (flags & 8) obj->list[obj->count++] = 3;
    if (flags & 0x10) obj->list[obj->count++] = 4;
    if (flags & 0x20) obj->list[obj->count++] = 5;
}

#endif
