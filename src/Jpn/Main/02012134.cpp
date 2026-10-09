#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012134
// Tests the Up button in the current, active-high input snapshot.
// This is a held-state test; the neighbouring generic helpers compare the previous snapshot for press and release edges.
extern "C" ARM int IsUpButtonHeld(const unsigned short* heldButtons)
{
    return (*heldButtons & 0x40) != 0;
}

#endif

