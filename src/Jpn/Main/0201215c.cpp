#if defined(jpn)
#include <globaldefs.h>

// JPN: func_0201215c
// Tests the A button in the current, active-high input snapshot.
// This is a held-state test; the neighbouring generic helpers compare the previous snapshot for press and release edges.
extern "C" ARM int IsAButtonHeld(const unsigned short* heldButtons)
{
    return (*heldButtons & 1) != 0;
}

#endif

