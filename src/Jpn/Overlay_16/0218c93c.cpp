#if defined(jpn)
#include <globaldefs.h>

struct Overlay16VideoState {
    unsigned int reserved[13];
    unsigned int selectedBank;
};

extern Overlay16VideoState data_ov016_0219cfa0;

// JPN: func_ov016_0218c93c
extern "C" ARM void* func_ov016_0218c93c() {
    if (data_ov016_0219cfa0.selectedBank == 0) {
        return (void*)0x06820000;
    }
    return (void*)0x06800000;
}

#endif

