#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov017_0218c1d0(void);
extern "C" void func_0207ed10(char* obj);
extern "C" void func_0207ed2c(char* obj);
extern "C" int func_020bd298(int a, int b, int c);

struct PairBlock02168a7c { unsigned int v[2]; };
struct Foo02168a7c {
    char pad[0x58];
    struct PairBlock02168a7c p1;
    struct PairBlock02168a7c p2;
};

// JPN: func_ov000_02168a7c  (semantic: SyncPairTablesAndFill_02168a7c)
extern "C" ARM void func_ov000_02168a7c(char* arg0) {
    func_ov017_0218c1d0();
    struct Foo02168a7c* foo = (struct Foo02168a7c*)(arg0 + 0x1a8);
    foo->p2 = foo->p1;
    func_0207ed10(arg0 + 0x1a8);

    unsigned char byteVal = *(unsigned char*)(*(char**)(arg0 + 0x218) + 0x8000 + 0x1b0);
    int val = byteVal;
    int mult;
    if (val > 5) {
        mult = 0x100;
        *(unsigned char*)(arg0 + 0x5000 + 0xff0) = 8;
    } else {
        *(unsigned char*)(arg0 + 0x5000 + 0xff0) = 5;
        mult = 0x190;
    }

    int i;
    for (i = 0; i < *(unsigned char*)(arg0 + 0x5000 + 0xff0); i++) {
        *(int*)(arg0 + i * 4 + 0x5000 + 0xff4) = func_020bd298(mult, 0, 0);
    }

    func_0207ed2c(arg0 + 0x1a8);
    *(unsigned char*)(arg0 + 0x5000 + 0xff1) = 0;
}

#endif
