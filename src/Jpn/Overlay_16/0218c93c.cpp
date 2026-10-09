#if defined(jpn)
#include <globaldefs.h>

struct MoviePlaybackState {
    unsigned int unknown0[13];
    unsigned int selectedBank;
};

extern MoviePlaybackState data_ov016_0219cfa0;

// JPN: func_ov016_0218c93c
// Returns the LCDC VRAM bank used for the next movie render.
// The movie display helper toggles the shared bank selection when presenting a frame.
extern "C" ARM void* GetMovieRenderVram() {
    if (data_ov016_0219cfa0.selectedBank == 0) {
        return (void*)0x06820000;
    }
    return (void*)0x06800000;
}

#endif

