#include <globaldefs.h>

void Init021b2f64(unsigned char* self);

// USA: func_ov017_021a4658
// JPN: func_ov017_021a50cc
extern "C" ARM unsigned char* func_ov017_021a4658(unsigned char* base, int val) {
    int i;
    for (i = 0; i < 0xc; i++) {
        unsigned char* elem = base + i * 0x48;
#if defined(jpn)
        if (elem[0x352e] != 0) {
            if (elem[0x352f] == 0 && val == *(short*)(elem + 0x3534)) {
                return base + 0x352c + i * 0x48;
#else
        if (elem[0x373e] != 0) {
            if (elem[0x373f] == 0 && val == *(short*)(elem + 0x3744)) {
                return base + 0x373c + i * 0x48;
#endif
            }
        }
    }

    int j;
    for (j = 0; j < 0xc; j++) {
        unsigned char* elem = base + j * 0x48;
#if defined(jpn)
        if (elem[0x352e] == 0) {
            unsigned char* target = base + 0x352c + j * 0x48;
#else
        if (elem[0x373e] == 0) {
            unsigned char* target = base + 0x373c + j * 0x48;
#endif
            Init021b2f64(target);
#if defined(jpn)
            return base + 0x352c + j * 0x48;
#else
            return base + 0x373c + j * 0x48;
#endif
        }
    }

    for (;;) {}
}
