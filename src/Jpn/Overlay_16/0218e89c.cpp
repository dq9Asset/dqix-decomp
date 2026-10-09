#if defined(jpn)
#include <globaldefs.h>

extern "C" unsigned int func_ov016_0218f148(const void* movie);

// JPN: func_ov016_0218e89c
// Returns the MODS movie's audio sample rate.
// A null movie handle reports zero.
extern "C" ARM unsigned int GetMovieAudioSampleRate(const void* movie) {
    if (movie == 0) {
        return 0;
    }
    return func_ov016_0218f148(movie);
}

#endif

