#include <globaldefs.h>
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_02069430(void*, unsigned short);
extern "C" void func_02041bbc(State0204166c*);

// JPN: func_0206cb14
extern "C" ARM void func_0206cb14(void* context, int fontSize, unsigned short index) {
    MessageSystem* self = static_cast<MessageSystem*>(context);
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

struct StateEntry0206b198 {
    char pad0[8];
    int field8;
    char pad1[0x1c - 0xc];
};

struct CombatSlots0206b198 {
    char pad0[0x9b4];
    int field9b4;
    StateEntry0206b198 stateArr[0x80];
    unsigned char byteArr[0x80];
};

// USA: func_0206b198
ARM void DecrementSlotRef0206b198(struct CombatSlots0206b198* obj, unsigned short idx) {
    if (idx >= 0x80) return;
    if (IsHighByteFF02044494(obj, &idx)) return;
    struct StateEntry0206b198* e = &obj->stateArr[idx];
    if (e->field8 < 0) return;
    if (obj->byteArr[idx] == 0) return;
    int cnt = obj->byteArr[idx] - 1;
    obj->byteArr[idx] = cnt;
    if ((cnt & 0xff) != 0) return;
    Forward020416c0((struct State0204166c*)e);
    obj->field9b4 = (obj->field9b4 - 1) & 0x7f;
}

#endif
