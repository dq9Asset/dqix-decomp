#include <globaldefs.h>

#if defined(jpn)
namespace {
struct Struct02020520;
struct S_b20c {
    void* pixels;
    Struct02020520* layout;
    unsigned char mode;
};
}
extern "C" void __clear(void*, int);
extern "C" void func_0205b234(S_b20c*, int, int, void*, int, int);

// JPN: func_0205c9ac
extern "C" ARM void func_0205c9ac(S_b20c* destination, short x, short y, int value,
                                  int pixelSize, int color, unsigned char digits, unsigned char align) {
    if (destination->pixels != NULL && destination->layout != NULL) {
        int remaining = value;
        while ((remaining = remaining / 10) != 0) {}
        if (align == 1) {
            x = (short)(x + (short)((digits - 1) * pixelSize));
        }
        char text[2];
        do {
            __clear(text, 2);
            text[0] = '0';
            text[0] += (char)(value % 10);
            func_0205b234(destination, x, y, text, pixelSize, color);
            x = (short)(x - pixelSize);
        } while ((value = value / 10) != 0);
    }
}
#else

struct Obj0205b674 { int field0; int field4; };

int FormatAbsIntToString02042658(void* obj, int value);
extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(void* dst, void* fmt, int val);
extern "C" void func_0205b234(struct Obj0205b674* a, int b, int c, void* buf, int d, int e);
extern char data_020f0518;

// USA: func_0205b674
ARM void PositionAndFormatValueLabel0205b674(struct Obj0205b674* obj, short posX, int param2, int param3,
                                              unsigned char param4, unsigned char param5, unsigned char param6, unsigned char param7) {
    if (obj->field0 != 0 && obj->field4 != 0) {
        int value = param3;
        while ((value = value / 10) != 0) {}
        int r0val = FormatAbsIntToString02042658((void*)param7, param3);
        if (param6 == 1) {
            posX = (short)(posX + (short)((param5 << 3) - r0val));
        }
        char buf[0xa];
        __clear(buf, 0xa);
        sprintf(buf, &data_020f0518, param3);
        func_0205b234(obj, posX, param2, buf, param4, param7);
    }
}

#endif
