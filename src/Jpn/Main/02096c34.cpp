#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern "C" void* func_0205ff20(void);

struct PackedNibbleArray0206e120 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};
extern "C" int func_0206f274(struct PackedNibbleArray0206e120* obj, int index);

extern "C" void func_0205ff5c(SafeAllocator* alloc, int limit, struct Variant02030b0c* arr, void* dst8, void* dstc);

struct Owner020958fc { unsigned char pad[0xa0]; void* slot; };
struct Node020958fc {
    unsigned short f0;
    unsigned short bits2 : 9;
    unsigned short bit9  : 1;
    unsigned short bit10 : 1;
    unsigned short bit11 : 1;
    unsigned short bit12 : 1;
    unsigned short bit13 : 1;
    unsigned short pad2  : 2;
    unsigned int   bits4a : 8;
    unsigned int   bits4b : 6;
    unsigned int   bits4c : 5;
    unsigned int   pad4   : 13;
    int f8;
    void* link;
};
extern "C" void func_0209754c(struct Owner020958fc* owner, struct Node020958fc* node);

struct Manager02109404 { unsigned char pad[0xc]; SafeAllocator* alloc; };
extern Manager02109404 data_021090bc;
extern Owner020958fc data_021090d0;

// JPN: func_02096c34
extern "C" ARM int func_02096c34(struct Variant02030b0c* arr, int b) {
    int p0 = _ZNK6Script9Parameter5ToIntEv(&arr[0]);
    int p1 = _ZNK6Script9Parameter5ToIntEv(&arr[1]);
    int p2 = _ZNK6Script9Parameter5ToIntEv(&arr[2]);
    int p3 = _ZNK6Script9Parameter5ToIntEv(&arr[3]);
    int p4 = _ZNK6Script9Parameter5ToIntEv(&arr[4]);
    int p5 = _ZNK6Script9Parameter5ToIntEv(&arr[5]);
    void* nibbles = func_0205ff20();
    int p6 = _ZNK6Script9Parameter5ToIntEv(&arr[6]);
    if (p6 >= 0) {
        int ok = (func_0206f274((struct PackedNibbleArray0206e120*)nibbles, p6) == 3);
        if (ok == 0) {
            return 0;
        }
    }

    struct Node020958fc* node = (struct Node020958fc*)data_021090bc.alloc->Allocate(0x10);
    node->f0 = p1;
    node->bits2 = p0;
    node->bits4a = p2;
    node->bits4b = p3;
    node->bits4c = p4;
    node->bit9 = p5;

    int p7 = _ZNK6Script9Parameter5ToIntEv(&arr[7]);
    node->bit11 = p7;
    int p8 = _ZNK6Script9Parameter5ToIntEv(&arr[8]);
    node->bit10 = p8;
    int p9 = _ZNK6Script9Parameter5ToIntEv(&arr[9]);
    node->bit12 = p9;
    int p10 = _ZNK6Script9Parameter5ToIntEv(&arr[10]);
    node->bit13 = p10;

    node->f8 = 0;
    node->link = 0;

    int local8 = 0;
    func_0205ff5c(data_021090bc.alloc, b - 0xb, &arr[11], &node->f8, &local8);

    func_0209754c(&data_021090d0, node);
    return 1;
}


#endif
