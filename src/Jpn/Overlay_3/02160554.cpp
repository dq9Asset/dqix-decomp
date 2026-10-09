#if defined(jpn)
#include <globaldefs.h>

struct Obj2081;
struct Outer020e28dc;
struct Container0205a3d0;
struct Container0205a330;
struct Elem0205a3d0 {
    char pad0[0x15];
    unsigned char flags;
};

extern "C" unsigned char* func_020826e4(Obj2081* obj, int key);
extern "C" int func_020e447c(Outer020e28dc* o);
extern "C" void func_0205b7c8(Container0205a3d0* c, int key, int val);
extern "C" void func_0205c228(void* obj);
extern "C" int func_0204d5fc(unsigned char* obj);
extern "C" void func_020814c4(void* obj, int id, int id2, short* out1, short* out2);
extern "C" void func_0205b6e8(Container0205a3d0* c, int key);
extern "C" Elem0205a3d0* func_0205b76c(Container0205a3d0* c, int key);
extern "C" void func_0205b6a8(Container0205a330* c, int arg);
extern "C" void func_020e438c(Container0205a3d0* c, int key, short a, short b);

struct Scene02160554 {
    char pad0[0x20c];
    Obj2081* p324;
    char pad328[0x21c - 0x210];
    char x334[0x274 - 0x21c];
    Container0205a3d0* p38c;
    Outer020e28dc* p390;
    char pad394[0x288 - 0x27c];
    int field_460;
    char pad464[0x298 - 0x28c];
    short* p470;
    char pad474[0x2b0 - 0x29c];
    short h488;
};

// JPN: func_ov003_02160554
extern "C" ARM void func_ov003_02160554(Scene02160554* self) {
    if (self->p470 == NULL || self->h488 < 0 || self->p324 == NULL) {
        return;
    }
    unsigned char* elem = func_020826e4(self->p324, self->h488);
    if (elem == NULL) {
        return;
    }
    if (self->p390 != NULL && func_020e447c(self->p390) != 0) {
        func_0205b7c8(self->p38c, 0, 0);
        func_0205c228(self->x334);
        return;
    }
    if (func_0204d5fc(elem) == 0) {
        return;
    }
    short x;
    short y;
    func_020814c4(self->p324, self->h488, *self->p470, &x, &y);
    x -= 0x10;
    y -= 3;
    func_0205b6e8(self->p38c, 0);
    Elem0205a3d0* e = func_0205b76c(self->p38c, 0);
    if (e != NULL) {
        e->flags |= 8;
    }
    e = func_0205b76c(self->p38c, 1);
    if (e != NULL) {
        e->flags &= ~8;
    }
    func_0205b6a8((Container0205a330*)self->p38c, self->field_460);
    func_020e438c(self->p38c, 0, x, y);
    func_0205c228(self->x334);
}

#endif
