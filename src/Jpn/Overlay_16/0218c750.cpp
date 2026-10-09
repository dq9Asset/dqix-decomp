#if defined(jpn)
#include <globaldefs.h>

// JPN: func_ov016_0218c750
// Sets the LCD display-selection bit used by the movie viewer.
// The argument is passed directly into bit 15 and is expected to be zero or one.
extern "C" ARM void SetMovieDisplaySelect(unsigned int displaySelect) {
    volatile unsigned short* powerControl = (volatile unsigned short*)0x04000304;
    *powerControl = (*powerControl & ~0x8000) | (displaySelect << 15);
}

#endif

