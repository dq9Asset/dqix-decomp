#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov017_021b3674(unsigned char* self);

// JPN: func_ov017_021a50cc
extern "C" ARM unsigned char* func_ov017_021a50cc(unsigned char* base, int val) {
    int i;
    for (i = 0; i < 0xc; i++) {
        unsigned char* elem = base + i * 0x48;
        if (elem[0x352e] != 0) {
            if (elem[0x352f] == 0 && val == *(short*)(elem + 0x3534)) {
                return base + 0x352c + i * 0x48;
            }
        }
    }

    int j;
    for (j = 0; j < 0xc; j++) {
        unsigned char* elem = base + j * 0x48;
        if (elem[0x352e] == 0) {
            unsigned char* target = base + 0x352c + j * 0x48;
            func_ov017_021b3674(target);
            return base + 0x352c + j * 0x48;
        }
    }

    for (;;) {}
}

#endif
