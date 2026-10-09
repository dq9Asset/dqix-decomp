#if defined(jpn)
#include <globaldefs.h>

struct Overlay16StreamBuffers {
    unsigned int reserved[34];
    void* buffers[2];
    unsigned int selectedBuffer;
};

// JPN: func_ov016_0218f550
extern "C" ARM void* func_ov016_0218f550(Overlay16StreamBuffers* stream) {
    return stream->buffers[stream->selectedBuffer];
}

#endif

