#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if !defined(jpn)
void Forward020416c0(MessageGlyphSlot*);

// USA: func_020462d0
extern "C" ARM void func_020462d0(MessageSystem* obj, unsigned short* codes, int count) {
    if (codes == 0) {
        return;
    }
    if (count < 0) {
        return;
    }

    enum { kMark = 0xff01 };

    for (int i = 0; i < count; i++) {
        unsigned short v = codes[i];
        codes[i] = kMark;
        if (v == kMark) {
            return;
        }
        if ((v & 0xff00) == 0xff00) {
            continue;
        }
        if (v >= 0x80) {
            continue;
        }
        MessageGlyphSlot* slot = &obj->glyphs[v];
        if (slot->bitmapIndex < 0) {
            continue;
        }
        int cnt = obj->glyphReferences[v] - 1;
        obj->glyphReferences[v] = cnt;
        if ((cnt & 0xff) != 0) {
            continue;
        }
        Forward020416c0(slot);
        int* counter = &obj->allocatedGlyphCount;
        *counter = (*counter - 1) & 0x7f;
    }
}

#endif
