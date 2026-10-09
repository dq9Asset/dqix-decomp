#if defined(jpn)
#include <globaldefs.h>

struct ModsMovie {
    unsigned int unknown0[8];
    unsigned int audioSampleRate;
    unsigned int unknown24;
    unsigned int shortAudioBlocks;
};

// JPN: func_ov016_0218f160
// Returns the sample count produced by one movie audio block, or zero without audio.
// The MODS option at +0x28 selects the shorter 128-sample block; its wider format meaning is not established.
extern "C" ARM unsigned int GetMovieAudioBlockSampleCount(const ModsMovie* movie) {
    if (movie->audioSampleRate == 0) return 0;
    return movie->shortAudioBlocks ? 0x80 : 0x100;
}

#endif

