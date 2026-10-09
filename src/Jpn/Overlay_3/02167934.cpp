#if defined(jpn)
#include <globaldefs.h>

struct Cont0207fe44;
extern "C" void func_02080980(struct Cont0207fe44* obj);

struct Pair02167934 { unsigned int a; unsigned int b; };
extern struct Pair02167934 data_020e7604;
struct Inner02167934 { unsigned int v[2]; };

struct DispatchEntry02167934 { unsigned int fn; unsigned int locator; };
struct Table02167934 { struct DispatchEntry02167934 entries[7]; };
extern struct Table02167934 data_ov003_0217e198;

struct Obj02167934 {
    char pad0[0x10];
    struct Cont0207fe44* f10;
    char pad14[0x40 - 0x14];
    int f70;
    unsigned char f74;
    char pad75;
    signed char f76;
};

// JPN: func_ov003_02167934
extern "C" ARM void func_ov003_02167934(struct Obj02167934* obj, int p1, int p2) {
    if (obj->f74 == 0 || obj->f10 == 0) return;
    if (obj->f70 == p1 && obj->f76 == p2) return;

    if (obj->f70 != p1 || p2 < 0) {
        func_02080980(obj->f10);
    }
    obj->f70 = p1;
    obj->f76 = (signed char)p2;

    struct Table02167934 buf;
    buf = data_ov003_0217e198;
    *(struct Inner02167934*)&buf.entries[0] = *(struct Inner02167934*)&data_020e7604;

    if (buf.entries[p1].fn == 0) return;
    struct DispatchEntry02167934* d = &buf.entries[p1];
    void* base = (char*)obj + ((int)d->locator >> 1);
    void* callback;
    if (d->locator & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    ((void(*)(void*))callback)(base);
}

#endif
