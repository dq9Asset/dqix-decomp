#if defined(jpn)
#include <globaldefs.h>

struct Overlay16StreamCounters {
    unsigned int reserved[39];
    unsigned int count;
    unsigned int limit;
    unsigned int wrapLimit;
    unsigned int reservedA8[6];
    unsigned int ringIndex;
};

// JPN: func_ov016_0218f510
extern "C" ARM int func_ov016_0218f510(Overlay16StreamCounters* stream) {
    unsigned int count = stream->count;
    unsigned int limit = stream->limit;
    if (count >= limit) return 0;
    stream->count = count + 1;
    unsigned int ringIndex = stream->ringIndex + 1;
    stream->ringIndex = ringIndex;
    if (ringIndex == stream->wrapLimit) {
        stream->ringIndex = 0;
    }
    return 1;
}

#endif

