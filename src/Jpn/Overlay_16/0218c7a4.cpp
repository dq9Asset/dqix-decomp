#if defined(jpn)
#include <globaldefs.h>

struct Overlay16CounterState {
    unsigned int reserved[15];
    unsigned long long frameCount;
};

extern Overlay16CounterState data_ov016_0219cfa0;

// JPN: func_ov016_0218c7a4
extern "C" ARM void func_ov016_0218c7a4() {
    ++data_ov016_0219cfa0.frameCount;
}

#endif

