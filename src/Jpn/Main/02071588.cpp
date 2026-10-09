#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_020717d8(int a1, int a2, int a3, int a4, int a5, int a6);
extern "C" void func_02071804(int a1, int a2, int a3);

struct Block02051c {
    int v[12];
};

extern struct Block02051c data_020e8918;

// JPN: func_02071588
extern "C" ARM void func_02071588(int unused, int a2, int a3) {
    struct Block02051c b = data_020e8918;

    *(volatile int*)0x40004a8 = 0x900000;
    func_020717d8(0, 0, 3, 0x3a, a3, 0x8000);

    *(volatile int*)0x4000444 = 0;
    *(volatile int*)0x400046c = 0x100000;
    *(volatile int*)0x400046c = 0xc0000;
    *(volatile int*)0x400046c = 0;
    *(volatile int*)0x4000500 = 1;
    *(volatile int*)0x4000480 = a2;

    func_02071804((short)b.v[0], (short)b.v[1], (short)b.v[2]);
    func_02071804((short)b.v[3], (short)b.v[4], (short)b.v[5]);
    func_02071804((short)b.v[6], (short)b.v[7], (short)b.v[8]);
    func_02071804((short)b.v[9], (short)b.v[10], (short)b.v[11]);

    *(volatile int*)0x4000504 = 0;
    *(volatile int*)0x4000448 = 1;

    if (a3 != 0x1f) return;

    func_020717d8(0, 0, 3, 0x3a, 0, 0x8000);

    *(volatile int*)0x4000444 = 0;
    *(volatile int*)0x400046c = 0x100000;
    *(volatile int*)0x400046c = 0xc0000;
    *(volatile int*)0x400046c = 0;
    *(volatile int*)0x4000500 = 1;
    *(volatile int*)0x4000480 = a2;

    func_02071804(b.v[0] << 16 >> 16, b.v[1] << 16 >> 16, b.v[2] << 16 >> 16);
    func_02071804(b.v[3] << 16 >> 16, b.v[4] << 16 >> 16, b.v[5] << 16 >> 16);
    func_02071804(b.v[6] << 16 >> 16, b.v[7] << 16 >> 16, b.v[8] << 16 >> 16);
    func_02071804(b.v[9] << 16 >> 16, b.v[10] << 16 >> 16, b.v[11] << 16 >> 16);

    *(volatile int*)0x4000504 = 0;
    *(volatile int*)0x4000448 = 1;
}


#endif
