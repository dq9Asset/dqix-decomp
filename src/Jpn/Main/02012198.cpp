#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012198
// Tests the Y button in the current, active-high input snapshot.
// This is a held-state test; the neighbouring generic helpers compare the previous snapshot for press and release edges.
extern "C" ARM int IsYButtonHeld(const unsigned short* heldButtons)
{
    return (*heldButtons & 0x800) != 0;
}

#endif

