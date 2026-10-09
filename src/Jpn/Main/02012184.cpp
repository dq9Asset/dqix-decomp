#if defined(jpn)
#include <globaldefs.h>

// JPN: func_02012184
// Tests the X button in the current, active-high input snapshot.
// This is a held-state test; the neighbouring generic helpers compare the previous snapshot for press and release edges.
extern "C" ARM int IsXButtonHeld(const unsigned short* heldButtons)
{
    return (*heldButtons & 0x400) != 0;
}

#endif

