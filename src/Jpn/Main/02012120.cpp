#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012120
// Tests the Right button in the current, active-high input snapshot.
// This is a held-state test; the neighbouring generic helpers compare the previous snapshot for press and release edges.
extern "C" ARM int IsRightButtonHeld(const unsigned short* heldButtons)
{
    return (*heldButtons & 0x10) != 0;
}

#endif

