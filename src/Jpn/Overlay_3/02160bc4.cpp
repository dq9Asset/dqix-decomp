#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_0200f9e8(int* obj);
extern "C" int func_020121c0(unsigned short* obj, int mask);
extern "C" int func_ov017_021a58e4(unsigned char* base);

struct Outer020e28dc;
extern "C" int func_020e447c(struct Outer020e28dc* o);
extern "C" int func_020e4524(void);
extern "C" void func_0201284c(unsigned char* obj, int* out1, int* out2);

struct Obj2081;
extern "C" int func_02081854(struct Obj2081* obj, int key, int px, int py);

extern unsigned short data_02114ad0;
extern unsigned char data_02114af4;

struct Ctx02160bc4 {
    char pad0[0x20c];
    struct Obj2081* field324;      // 0x20c
    char pad1[0x278 - 0x210];
    struct Outer020e28dc* ptr390;  // 0x278
    char pad2[0x2b0 - 0x27c];
    short key488;                  // 0x2b0
};

// JPN: func_ov003_02160bc4  (semantic: CheckStateAtCoords_02160bc4)
extern "C" ARM int func_ov003_02160bc4(struct Ctx02160bc4* self) {
    int flag = 0;
    unsigned char* battleWord = (unsigned char*)func_0200f9e8((int*)GameState::GetInstance());
    if (func_020121c0(&data_02114ad0, 2)) {
        if (func_ov017_021a58e4(battleWord)) {
            flag = 1;
        }
    }

    if (func_020e447c(self->ptr390)) {
        (void)*(struct Outer020e28dc* volatile*)&self->ptr390;
        if (func_020e4524()) {
            flag = 1;
        }
    } else if (*((unsigned char*)&data_02114af4 + 0x55) != 0) {
        int a, b;
        func_0201284c(&data_02114af4, &a, &b);
        if (!func_02081854(self->field324, self->key488, (short)a, (short)b)) {
            flag = 1;
        }
    }
    return flag;
}

#endif
