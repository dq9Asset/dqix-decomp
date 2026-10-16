#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char unknown0[0xac];
    short x, y;
};
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c* s, int key);

struct TouchCoordinates {
    unsigned char unknown0[0x38];
    int x, y;
};
extern TouchCoordinates data_02114e54;

#if defined(jpn)
enum { KeyOffset = 0x1341, WindowOffset = 0x90 };
#else
enum { KeyOffset = 0x1371, WindowOffset = 0xac };
#endif
namespace {
struct TouchBandsState {
    unsigned char unknown0[WindowOffset];
    CreationWindow window;
    unsigned char unknownAfterWindow[KeyOffset - WindowOffset - sizeof(CreationWindow)];
    unsigned char key;
};
}

// USA: func_ov023_021e63bc  (semantic: CheckElemNearTouchPoint_021e63bc)
// JPN: func_ov023_021e6630
extern "C" ARM int func_ov023_021e63bc(unsigned char* obj) {
    TouchBandsState* state = reinterpret_cast<TouchBandsState*>(obj);
    int key = state->key;
    Elem_0205d81c* elem = FindElementByC40205d81c(reinterpret_cast<Struct_0205d81c*>(&state->window), key);
    int boundA = data_02114e54.x;
    int x = elem->x;
    int ytop = elem->y;
    x = (short)(x << 3) + 0xa;
    ytop = (short)(ytop << 3) + 0x10;
    int boundB = data_02114e54.y;
    if (x <= boundA && boundA <= x + 0x10 && ytop <= boundB && boundB <= ytop + 8)
        return 1;
    if (x <= boundA && boundA <= x + 0x10 && ytop + 0xc <= boundB && boundB <= ytop + 0x14)
        return -1;
    return 0;
}
