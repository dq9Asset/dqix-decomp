#if defined(jpn)
#include <globaldefs.h>

struct MoviePlaybackState {
    unsigned int unknown0[15];
    unsigned long long audioBlocksConsumed;
};

extern MoviePlaybackState data_ov016_0219cfa0;

// JPN: func_ov016_0218c7a4
// Advances the movie player's audio-consumption clock.
// The callback is registered with the sound setup; one tick is an audio block, not a decoded video frame.
extern "C" ARM void AdvanceMovieAudioClock() {
    ++data_ov016_0219cfa0.audioBlocksConsumed;
}

#endif

