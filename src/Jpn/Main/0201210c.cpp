#if defined(jpn)
#include <globaldefs.h>

// JPN: func_0201210c
// Tests the Left button in the current, active-high input snapshot.
// This is a held-state test; the neighbouring generic helpers compare the previous snapshot for press and release edges.
extern "C" ARM int IsLeftButtonHeld(const unsigned short* heldButtons)
{
    return (*heldButtons & 0x20) != 0;
}

#endif

