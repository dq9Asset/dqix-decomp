#include <globaldefs.h>

int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char* obj);
extern "C" int func_0204fd00(void* ctx, int mask);
extern "C" void func_0204bc74(void* target, int type, short a, short b, short c, short d, int flags);

struct Entry_0205da88 {
    char pad0[0x1c];
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    char pad1[0x20 - 0x1d];
};

struct Elem_0205da88 {
    char pad0[0x4];
    struct Entry_0205da88* matched;
    char pad1[0xa8 - 0x8];
    short fa8;
    short faa;
    short fac;
    short fae;
    char pad2[0xc0 - 0xb0];
    short fc0;
    char pad3[0xc5 - 0xc2];
    unsigned char fc5;
    char pad4[0xe0 - 0xc6];
};

struct Obj_0205da88 {
    char pad0[0x98];
    struct Entry_0205da88* entries;
    struct Elem_0205da88* elems;
    char pad1[0xb2 - 0xa0];
    unsigned char entryCount;
    unsigned char elemCount;
};

// USA: func_0205da88
extern "C" ARM void func_0205da88(struct Obj_0205da88* obj, int keyA, int keyB, unsigned short tile) {
    struct Entry_0205da88* target;
    struct Entry_0205da88* source;
    struct Entry_0205da88* e;
    struct Elem_0205da88* el;
    unsigned char i;

    if (obj->entries != 0 && obj->elems != 0) {
        keyA &= 3;
        keyB &= 3;
        if (keyA == keyB) return;

        target = 0;
        source = 0;
        for (i = 0; i < obj->entryCount; i++) {
            e = &obj->entries[i];
            if (keyA == e->highNibble) target = e;
            if (keyB == e->highNibble) source = e;
        }
        if ((target == 0) | (source == 0)) return;

        tile &= 0x3ff;
        for (i = 0; i < obj->elemCount; i++) {
            el = &obj->elems[i];
            if (!CheckField0x9cSetWhenField0xd4Present_0204c7e0((unsigned char*)el)) continue;
            if (el->fc5 & 0x20) continue;
            if (el->fc5 & 0x80) continue;
            if (source != el->matched) continue;
            short x = el->fac;
            short y = el->fae;
            short w = el->fa8;
            short h = el->fc0;
            func_0204bc74(target, tile, x, y, w, h, 0);
            if (h == 0 || tile == 0) continue;
            if (!func_0204fd00(el, 1))
                func_0204bc74(target, 2, x, y, 1, 1, 0);
            if (!func_0204fd00(el, 2))
                func_0204bc74(target, 0x402, (short)(x + w - 1), y, 1, 1, 0);
            if (!func_0204fd00(el, 4))
                func_0204bc74(target, 0x802, x, (short)(y + h - 1), 1, 1, 0);
            if (!func_0204fd00(el, 8))
                func_0204bc74(target, 0xc02, (short)(x + w - 1), (short)(y + h - 1), 1, 1, 0);
        }
    }
}
