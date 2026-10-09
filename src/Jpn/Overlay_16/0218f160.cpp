#if defined(jpn)
#include <globaldefs.h>

struct Overlay16StreamFormat {
    unsigned int reserved[8];
    unsigned int active;
    unsigned int reserved24;
    unsigned int halfSize;
};

// JPN: func_ov016_0218f160
extern "C" ARM unsigned int func_ov016_0218f160(const Overlay16StreamFormat* stream) {
    if (stream->active == 0) return 0;
    return stream->halfSize ? 0x80 : 0x100;
}

#endif

