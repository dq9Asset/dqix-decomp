#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

#if !defined(jpn)

// USA: func_02066ce0
ARM void SetIntIntShortAt0xc_02066ce0(MessageGlyphSlot* slot, int x, int y, short depth) {
    slot->x = x;
    slot->y = y;
    slot->depth = depth;
}

#endif
