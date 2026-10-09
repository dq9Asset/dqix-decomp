#if defined(jpn)
#include <globaldefs.h>

struct ModsMovie {
    unsigned int unknown0[34];
    void* audioBlockCounts[2];
    unsigned int selectedFrameSlot;
};

// JPN: func_ov016_0218f550
// Returns the number of audio blocks attached to the selected movie frame.
// The existing pointer return type is preserved for matching; the stored value is a packed-header count, not a buffer address.
extern "C" ARM void* GetMovieAudioBlockCount(ModsMovie* movie) {
    return movie->audioBlockCounts[movie->selectedFrameSlot];
}

#endif

