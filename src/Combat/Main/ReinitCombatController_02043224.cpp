#include <globaldefs.h>
#include "Resource/MessageSystem.h"

#if defined(jpn)
enum { kFirstEntry = 14 };
#else
enum { kFirstEntry = 0 };
#endif
#if defined(jpn)
#define Forward020416c0 func_02041bbc
extern "C" void func_02041bbc(struct State0204166c* s);
#endif

#if defined(jpn)
#define func_02043224 func_02043998
#endif

struct State0204166c;
void Forward020416c0(struct State0204166c* s);

void ClearField8ViaPointer0x440(MessageSlotController* s);

// USA: func_02043224  (semantic: ReinitCombatController_02043224)
extern "C" ARM void func_02043224(MessageSystem* obj) {
    obj->b19cc = 0;
    obj->allocatedGlyphCount = kFirstEntry;

    for (int i = kFirstEntry; i < 0x80; i++) {
        Forward020416c0(&obj->glyphs[i]);
        obj->glyphReferences[i] = 0;
    }

    func_02043124(obj);
    ClearField8ViaPointer0x440(&obj->controller);
    obj->controller.currentBounds = &obj->foo930;
    ClearField8ViaPointer0x440(&obj->controller);
    obj->controller.currentBounds = &obj->primaryBounds;
    obj->b19b1 = 0;
    obj->selectedEntry = -1;
    obj->selectedValue = 0;
}
