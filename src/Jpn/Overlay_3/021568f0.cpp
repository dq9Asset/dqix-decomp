#if defined(jpn)
#include <globaldefs.h>

struct Outer020e28dc;
struct Obj2081;

extern unsigned short data_02114ad0;
extern unsigned char data_02114af4;

extern "C" int func_020121c0(unsigned short* obj, int mask);
extern "C" int func_020e447c(struct Outer020e28dc* o);
extern "C" int func_020e4524(void);
extern "C" void func_0201284c(unsigned char* obj, int* out1, int* out2);
extern "C" int func_02081854(struct Obj2081* obj, int key, int px, int py);

struct Ctx021568f0 {
    char pad0[0x18];
    struct Obj2081* field18;      // 0x18
    struct Outer020e28dc* ptr1c;  // 0x1c
    char pad1[0x1e2 - 0x20];
    short key1e6;                 // 0x1e2
};

// JPN: func_ov003_021568f0  (semantic: CheckStateAtCoords_021568f0)
extern "C" ARM int func_ov003_021568f0(struct Ctx021568f0* self) {
    int flag = 0;
    if (func_020121c0(&data_02114ad0, 2)) flag = 1;

    if (self->ptr1c != NULL && func_020e447c(self->ptr1c)) {
        (void)*(struct Outer020e28dc* volatile*)&self->ptr1c;
        if (func_020e4524()) {
            flag = 1;
        }
    } else if (*((unsigned char*)&data_02114af4 + 0x55) != 0) {
        int a, b;
        func_0201284c(&data_02114af4, &a, &b);
        if (!func_02081854(self->field18, self->key1e6, (short)a, (short)b)) {
            flag = 1;
        }
    }
    return flag;
}

#endif
