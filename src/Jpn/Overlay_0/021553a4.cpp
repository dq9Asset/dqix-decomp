#if defined(jpn)
#include <globaldefs.h>
#include "Util/Random.h"

extern "C" void __clear(void* buf, int size);

struct Entry021553a4 { char pad[0xa]; unsigned char lowNibble:4; unsigned char kind:4; char pad2[0x18 - 0xa - 1]; };
struct RegionAt8000_021553a4 { char pad[0x1b1]; unsigned char lowBits:4; unsigned char limit:2; unsigned char highBits:2; };

// JPN: func_ov000_021553a4
extern "C" ARM void func_ov000_021553a4(void* obj, int* out) {
    struct Entry021553a4* table = (struct Entry021553a4*)((char*)obj + 0x1b4 + 0x8000);
    int idx = *out;
    if (table[idx].kind != 0) return;
    int buf[3];
    __clear(buf, 0xc);
    int count = 0;
    int i;
    int* bufPtr = buf;
    for (i = 0; i < ((struct RegionAt8000_021553a4*)((char*)obj + 0x8000))->limit; i++) {
        if (table[i].kind != 0) {
            bufPtr[count] = i;
            count++;
        }
    }
    int r = NextRandomMax((struct Random*)obj, count);
    *out = bufPtr[r];
}

#endif
