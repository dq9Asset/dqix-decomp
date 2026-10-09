#if defined(jpn)
#include <globaldefs.h>

struct Struct_0205bef8;
extern "C" void func_0205d258(struct Struct_0205bef8* s);

struct Struct_0205ba68;
extern "C" void func_0205cdc8(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
extern "C" void func_0205ce2c(struct Node0205bacc* s, int val);

extern "C" void func_0205ce64(void* s, int n);

struct PointerTable0216951c {
    int field0;
    int field4;
};

struct Ctx0216951c {
    char pad0[0x4eb];
    signed char values[4];
    signed char limits[4];
    char pad4f7[0x4f8 - 0x4f3];
    struct PointerTable0216951c table;
};

// JPN: func_ov003_0216951c
extern "C" ARM void func_ov003_0216951c(struct Ctx0216951c* self, int index) {
    int base = self->values[index];
    int isLast = 0;
    for (int i = 0; i < index; i++) {
        if (self->values[i] < self->limits[i]) break;
        if (i == index - 1) isLast = 1;
    }
    if (index == 0) isLast = 1;

    int first = 3;
    for (int i = 0; i < 4; i++) {
        if (self->limits[i] > 0) {
            first = i;
            break;
        }
    }
    if (index <= first) isLast = 0;

    func_0205d258((struct Struct_0205bef8*)&self->table);
    if (isLast) {
        int limit = self->limits[index];
        func_0205cdc8((struct Struct_0205ba68*)&self->table, 1, limit + 1, 0);
        self->table.field4 = 1;
        func_0205ce2c((struct Node0205bacc*)&self->table, limit + 1);
        func_0205ce64(&self->table, limit - base);
    } else {
        func_0205cdc8((struct Struct_0205ba68*)&self->table, 1, 10, 0);
        self->table.field4 = 1;
        func_0205ce2c((struct Node0205bacc*)&self->table, 10);
        func_0205ce64(&self->table, 9 - base);
    }
}

#endif
