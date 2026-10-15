#include <globaldefs.h>
#include <Resource/MessageSystem.h>
#include <Resource/MessageUpdate.h>
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_02069430(void*, unsigned short);
extern "C" void func_02041bbc(State0204166c*);

// JPN: func_0206cb14
extern "C" ARM void func_0206cb14(MessageSystem* self, int fontSize, unsigned short index) {
    if (index >= 0x80) return;
    if (func_02069430(self, index)) return;
    State0204166c* slot = &self->glyphs[index];
    if (slot->bitmapIndex < 0) return;
    if (self->glyphReferences[index] == 0) return;
    if (fontSize != slot->fontPixelSize) return;
    int count = self->glyphReferences[index] - 1;
    self->glyphReferences[index] = count;
    if ((count & 0xff) != 0) return;
    func_02041bbc(slot);
    self->allocatedGlyphCount = (self->allocatedGlyphCount - 1) & 0x7f;
}
#else

struct State0204166c;
void Forward020416c0(struct State0204166c* s);

ARM bool IsHighByteFF02044494(void* obj, void* src);



// USA: func_0206b198
ARM void DecrementSlotRef0206b198(MessageSystem* obj, unsigned short idx) {
    if (idx >= 0x80) return;
    if (IsHighByteFF02044494(obj, &idx)) return;
    MessageGlyphSlot* e = &obj->glyphs[idx];
    if (e->bitmapIndex < 0) return;
    if (obj->glyphReferences[idx] == 0) return;
    int cnt = obj->glyphReferences[idx] - 1;
    obj->glyphReferences[idx] = cnt;
    if ((cnt & 0xff) != 0) return;
    Forward020416c0(e);
    obj->allocatedGlyphCount = (obj->allocatedGlyphCount - 1) & 0x7f;
}

#endif
