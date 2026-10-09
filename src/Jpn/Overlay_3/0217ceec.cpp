#if defined(jpn)
#include <globaldefs.h>

extern unsigned char data_02114af4[];

extern "C" void func_0201284c(unsigned char* obj, int* out1, int* out2);

struct Elem_0205d81c {
    char pad0[0xa8];
    short width;
    short height;
    short x;
    short y;
};

struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* func_0205eb30(struct Struct_0205d81c* s, int key);

struct Struct_0205c4a8;
extern "C" void func_0205d808(struct Struct_0205c4a8* s, int delta);
struct Struct_0205bb84;
extern "C" int func_0205cee4(struct Struct_0205bb84* s);
struct Struct_0205bcdc;
extern "C" void func_0205d03c(struct Struct_0205bcdc* s, int index);
extern "C" void func_0205ce64(void* s, int value);

struct ScrollList {
    char pad0[0x4];
    char indexState[0x50];
    char scrollState[0x40];
};

struct Obj0217ceec {
    char pad0[0x8c];
    struct ScrollList* list;
};

// JPN: func_ov003_0217ceec
extern "C" ARM int func_ov003_0217ceec(struct Obj0217ceec* self) {
    int x;
    int y;
    if (data_02114af4[0x55] == 0) {
        goto fail;
    }
    func_0201284c(data_02114af4, &x, &y);
    struct Elem_0205d81c* e = func_0205eb30((struct Struct_0205d81c*)self->list, 0);
    if (e == NULL) {
        goto fail;
    }
    short right = e->x;
    short bottom = e->y;
    short height = e->height;
    right += e->width;
    bottom += height;
    bottom <<= 3;
    if (bottom - 16 <= y && y < bottom) {
        struct ScrollList* list = self->list;
        short left = e->x << 3;
        if (x >= left && x < left + 16) {
            func_0205d808((struct Struct_0205c4a8*)list->scrollState, -1);
        }
        right <<= 3;
        if (right - 16 <= x && x < right) {
            func_0205d808((struct Struct_0205c4a8*)list->scrollState, 1);
        }
        int index = func_0205cee4((struct Struct_0205bb84*)list->scrollState);
        func_0205d03c((struct Struct_0205bcdc*)list->indexState, index);
        func_0205ce64(list->scrollState, index);
    }
    return 1;
fail:
    return 0;
}

#endif
