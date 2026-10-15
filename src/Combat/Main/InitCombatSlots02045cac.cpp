#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct State0204166c;
#if defined(jpn)
extern "C" void func_02041bbc(struct State0204166c* s);
#define Forward020416c0 func_02041bbc
#else
void Forward020416c0(struct State0204166c* s);
#endif

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);

// USA: func_02045cac
ARM void InitCombatSlots02045cac(MessageSystem* obj) {
    obj->drawEnabled = 1;
#if defined(jpn)
    obj->allocatedGlyphCount = 14;
#else
    obj->allocatedGlyphCount = 0;
#endif
#if defined(jpn)
    for (int i = 14; i < 0x80; i++) {
#else
    for (int i = 0; i < 0x80; i++) {
#endif
        Forward020416c0(&obj->glyphs[i]);
        obj->glyphReferences[i] = 0;
    }
    if (obj->encoder != NULL) {
        CopyInternalFields0207df50(obj->encoder);
    }
}
