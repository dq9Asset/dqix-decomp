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

struct Ctx02175730 {
    struct Outer020e28dc* ptr0;   // 0x0
    char pad0[0x818 - 0x4];
    struct Obj2081* field89c;     // 0x818
    char pad1[0xf7a - 0x81c];
    short keyffe;                 // 0xf7a
};

// JPN: func_ov003_02175730  (semantic: CheckStateAtCoords_02175730)
extern "C" ARM int func_ov003_02175730(struct Ctx02175730* self) {
    int flag = 0;
    if (func_020121c0(&data_02114ad0, 2)) flag = 1;

    if (self->ptr0 != NULL && func_020e447c(self->ptr0)) {
        (void)*(struct Outer020e28dc* volatile*)&self->ptr0;
        if (func_020e4524()) {
            flag = 1;
        }
    } else if (*((unsigned char*)&data_02114af4 + 0x55) != 0) {
        int a, b;
        func_0201284c(&data_02114af4, &a, &b);
        if (!func_02081854(self->field89c, self->keyffe, (short)a, (short)b)) {
            flag = 1;
        }
    }
    return flag;
}

#endif
