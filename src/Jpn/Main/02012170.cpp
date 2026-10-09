#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012170
// Tests the B button in the current, active-high input snapshot.
// This is a held-state test; the neighbouring generic helpers compare the previous snapshot for press and release edges.
extern "C" ARM int IsBButtonHeld(const unsigned short* heldButtons)
{
    return (*heldButtons & 2) != 0;
}

#endif

