#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov017_0218c1d0(void);
extern "C" void func_0203af30(unsigned int* obj, unsigned int mask);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

struct S0216e7f8 {
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    char pad0[0x20 - 3];
    unsigned short field20;
    char pad1[0x3b - 0x22];
    unsigned char field3b;
};

// JPN: func_ov003_0216e7f8  (semantic: UpdateCounterAndBg_0216e7f8)
extern "C" ARM void func_ov003_0216e7f8(S0216e7f8* self) {
    unsigned int* field4 = (unsigned int*)func_ov017_0218c1d0();
    unsigned char cur = self->field3b;
    if (cur >= 0x10) {
        self->field3b = 0x10;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 4, 8, 0xc, 4);
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x1f00;
        func_0203af30(field4, 0xcce);
        self->field20 |= 0x20;
        self->field1 = 4;
        self->field2 = 0;
    } else {
        self->field3b = cur + 4;
        if (self->field3b > 0x10) {
            self->field3b = 0x10;
            func_0203af30(field4, 0xcce);
        }
        unsigned char c = self->field3b;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 0x18, 1, c, 0x10 - c);
    }
}

#endif
