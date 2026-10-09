#if defined(jpn)
#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xac];
    short x_;
    short y_;
    unsigned char padb0[0xbc - 0xb0];
    short offsetX_;
    short offsetY_;
    unsigned char padc0[0xc4 - 0xc0];
    unsigned char type_;
};
extern "C" Elem_0205d81c* func_0205ebd8(Struct_0205d81c*);
extern "C" int func_0204d5fc(unsigned char*);

struct Elem0205a3d0 {
    char pad0[4];
    short x_;
    short y_;
    unsigned short key_;
    char padA[0x15 - 0xa];
    unsigned char flags_;
    char pad16[0x18 - 0x16];
};

struct Container0205a3d0;
extern "C" void func_0205b6e8(Container0205a3d0*, int);
extern "C" Elem0205a3d0* func_0205b76c(Container0205a3d0*, int);
extern "C" void func_0205b7c8(Container0205a3d0*, int, int);

struct Container0205a330;
extern "C" void func_0205b6a8(Container0205a330*, int);

extern "C" void func_0205c228(void*);

// JPN: func_ov000_0217690c
extern "C" ARM void func_ov000_0217690c(unsigned char* obj) {
    if (!(*(unsigned short*)(obj + 0x1faa) & 0x100)) return;

    Elem_0205d81c* elem = func_0205ebd8((Struct_0205d81c*)(obj + 0x188));
    if (elem == NULL) return;
    if (elem->type_ >= 0x1a) return;
    if (!func_0204d5fc((unsigned char*)elem)) return;

    short x = elem->x_ * 8;
    short y = elem->y_ * 8;
    x += elem->offsetX_;
    y += elem->offsetY_;

    Container0205a3d0* container = *(Container0205a3d0**)(obj + 0x174);
    func_0205b6e8(container, 0);
    Elem0205a3d0* entry = func_0205b76c(container, 0);
    if (entry != NULL) entry->flags_ |= 8;

    func_0205b6a8((Container0205a330*)container, *(int*)(obj + 0x94c));

    entry = func_0205b76c(container, 0);
    if (entry != NULL) {
        entry->x_ = x - 8;
        entry->y_ = y - 2;
    }

    func_0205b7c8(container, 0, 0x4c);
    func_0205c228(obj + 0x11c);
}

#endif
