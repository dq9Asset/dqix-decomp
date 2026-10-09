#if defined(jpn)
#include <globaldefs.h>

struct ModsMovie {
    unsigned int unknown0[39];
    unsigned int consumedFrameCount;
    unsigned int decodedFrameCount;
    unsigned int frameBufferCount;
    unsigned int unknownA8[6];
    unsigned int frameReadIndex;
};

// JPN: func_ov016_0218f510
// Consumes a decoded movie frame without rendering it.
// Returns zero when the decoded-frame queue is empty, otherwise advances the read index with wraparound.
extern "C" ARM int SkipDecodedMovieFrame(ModsMovie* movie) {
    unsigned int consumedFrameCount = movie->consumedFrameCount;
    unsigned int decodedFrameCount = movie->decodedFrameCount;
    if (consumedFrameCount >= decodedFrameCount) return 0;
    movie->consumedFrameCount = consumedFrameCount + 1;
    unsigned int frameReadIndex = movie->frameReadIndex + 1;
    movie->frameReadIndex = frameReadIndex;
    if (frameReadIndex == movie->frameBufferCount) {
        movie->frameReadIndex = 0;
    }
    return 1;
}

#endif

