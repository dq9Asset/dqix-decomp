#if defined(jpn)
#include <globaldefs.h>

extern "C" unsigned int func_ov016_0218f150(const void* movie);

// JPN: func_ov016_0218e8b4
// Returns the MODS movie's frame rate with 24 fractional bits.
// A null movie handle reports zero.
extern "C" ARM unsigned int GetMovieFrameRateFixed24(const void* movie) {
    if (movie == 0) {
        return 0;
    }
    return func_ov016_0218f150(movie);
}

#endif

