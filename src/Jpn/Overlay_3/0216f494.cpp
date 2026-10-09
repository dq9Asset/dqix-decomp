#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov017_0218c1d0(void);
extern "C" void func_0203af40(unsigned int* obj, unsigned int mask);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

struct S0216f494 {
    char pad0[1];
    unsigned char field1;
    unsigned char field2;
    char pad2[0x3b - 3];
    unsigned char field3b;
    char pad3[0x48 - 0x3c];
};

// JPN: func_ov003_0216f494  (semantic: DecrementCounterAndConfigureBg_0216f494)
extern "C" ARM void func_ov003_0216f494(S0216f494* obj) {
    func_0203af40((unsigned int*)func_ov017_0218c1d0(), 0xc8e);

    volatile unsigned short* bgcnt = (volatile unsigned short*)0x4000008;
    unsigned int* packOut = (unsigned int*)((char*)bgcnt + 0x48);
    bgcnt[0] = (bgcnt[0] & ~3) | 3;
    bgcnt[1] = (bgcnt[1] & ~3);
    bgcnt[2] = (bgcnt[2] & ~3) | 1;
    bgcnt[3] = (bgcnt[3] & ~3) | 2;

    unsigned char c = obj->field3b;
    ColorEffect_ConfigureAlphaBlend(packOut, 0x18, 1, c, 0x10 - c);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | 0xf00;

    obj->field3b -= 4;
    if (obj->field3b == 0) {
        obj->field1 = 7;
        obj->field2 = 0;
    }
}

#endif
