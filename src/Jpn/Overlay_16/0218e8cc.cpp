#if defined(jpn)
#include <globaldefs.h>

extern "C" unsigned int func_ov016_0218f158(const void* movie);

// JPN: func_ov016_0218e8cc
// Returns the MODS movie's total video frame count.
// A null movie handle reports zero.
extern "C" ARM unsigned int GetMovieFrameCount(const void* movie) {
    if (movie == 0) {
        return 0;
    }
    return func_ov016_0218f158(movie);
}

#endif

