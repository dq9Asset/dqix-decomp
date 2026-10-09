#if defined(jpn)
#include <globaldefs.h>

struct Struct_0205ba68;
struct Node0205bacc;
struct Struct_0205bcdc;

extern "C" void func_0205cdc8(struct Struct_0205ba68* s, int a, int b, int mode);
extern "C" void func_0205ce2c(struct Node0205bacc* s, int val);
extern "C" void func_0205d03c(struct Struct_0205bcdc* s, int index);
extern "C" void func_0205ce64(void* s, int n);

struct Grid021693bc {
    int field0;
    int field4;
    char pad8[0x3c - 0x8];
    unsigned char field3c;
    char pad3d[0x50 - 0x3d];
};

struct Ctx021693bc {
    char pad0[0xe4];
    struct Grid021693bc grids[2];
    char pad188[0x190 - 0x184];
    unsigned char layout;
    char pad195[0x4e9 - 0x191];
    signed char indexA;
    signed char indexB;
};

static inline struct Grid021693bc* GetGrid(struct Ctx021693bc* ctx, int i) { return &ctx->grids[i]; }

// JPN: func_ov003_021693bc
extern "C" ARM void func_ov003_021693bc(struct Ctx021693bc* self) {
    int cols;
    int rows;
    int count;
    int field4;
    int index;

    switch (self->layout) {
    case 1:
        cols = 1;
        rows = 3;
        count = 3;
        field4 = 1;
        index = self->indexA;
        break;
    case 2:
        index = self->indexB;
        cols = 4;
        rows = 1;
        count = 4;
        field4 = 1;
        break;
    }

    func_0205cdc8((struct Struct_0205ba68*)GetGrid(self, 0), cols, rows, 0);
    func_0205cdc8((struct Struct_0205ba68*)GetGrid(self, 1), cols, rows, 0);
    func_0205ce2c((struct Node0205bacc*)GetGrid(self, 0), count);
    func_0205ce2c((struct Node0205bacc*)GetGrid(self, 1), count);
    GetGrid(self, 0)->field4 = field4;
    GetGrid(self, 1)->field4 = field4;
    func_0205d03c((struct Struct_0205bcdc*)GetGrid(self, 0), index);
    func_0205ce64(GetGrid(self, 1), index);
    struct Grid021693bc* grid = GetGrid(self, 1);
    grid->field3c = 0;
}

#endif
