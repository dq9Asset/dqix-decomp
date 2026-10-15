#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char unknown0[0xac];
    short x, y;
};
struct ShortArrays0204c654;

struct Offsets_0216c98a {
    short v[4];
};

struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
void SetEntryFields02154bcc(int a, int b, void *obj, int idx, unsigned char arg5, unsigned char arg6);
void SetFourShortsAtIndex(ShortArrays0204c654 *arr, int idx, short a, short b, short c, short d);

#if defined(jpn)
enum { WindowOffset = 0xe20, SpriteOffset = 0x19c0, SelectionOffset = 0x1ace,
       GridKey = 0x1d, LabelKey = 0x1e, FirstTile = 0x18, CursorTile = 0x13, LabelTile = 0x16 };
#define data_ov002_0216c98a data_ov002_0216cfe6
#else
enum { WindowOffset = 0xec8, SpriteOffset = 0x1a68, SelectionOffset = 0x1c06,
       GridKey = 0x1c, LabelKey = 0x1d, FirstTile = 0x16, CursorTile = 0x11, LabelTile = 0x14 };
#endif
extern Offsets_0216c98a data_ov002_0216c98a;

namespace {
struct BattleChoiceGridState {
    unsigned char unknown0[WindowOffset];
    CreationWindow window;
    unsigned char unknownAfterWindow[SpriteOffset - WindowOffset - sizeof(CreationWindow)];
    void* renderer;
    unsigned char unknownAfterRenderer[SelectionOffset - SpriteOffset - 4];
    short selection;
};
}

// USA: func_ov002_0215ad70
// JPN: func_ov002_0215c0d8
extern "C" ARM void func_ov002_0215ad70(unsigned char *obj) {
    BattleChoiceGridState* state = reinterpret_cast<BattleChoiceGridState*>(obj);
    struct Elem_0205d81c *elem =
        FindElementByC40205d81c(reinterpret_cast<Struct_0205d81c*>(&state->window), GridKey);
    if (elem == 0) {
        return;
    }
    int baseX             = static_cast<short>(elem->x * 8);
    int baseY             = static_cast<short>(elem->y * 8);
    Offsets_0216c98a offs = data_ov002_0216c98a;
    unsigned char k       = 0;
    unsigned short tile   = FirstTile;
    for (unsigned char row = 0; row < 4; row++) {
        for (unsigned char col = 0; col < 4; col++) {
            short idx;
            int py;
            short dx;
            dx       = offs.v[col];
            short dy = offs.v[row];
            short px = (short) (dx + baseX);
            py       = (short) (dy + baseY);
            SetEntryFields02154bcc(px, py, state->renderer, tile++, (unsigned char) (k * 4 + 0xc),
                                              0xff);
            idx = (short) (col + row * 4);
            if (state->selection == idx) {
                SetEntryFields02154bcc(px, py, state->renderer, CursorTile, 8, 0xff);
            }
            SetFourShortsAtIndex(reinterpret_cast<ShortArrays0204c654*>(elem), idx, dx, dy, 0x18, 0x18);
            k++;
        }
    }
    elem = FindElementByC40205d81c(reinterpret_cast<Struct_0205d81c*>(&state->window), LabelKey);
    if (elem == 0) {
        return;
    }
    int x2 = elem->x;
    int y2 = elem->y;
    x2     = (short) (x2 * 8) + 0x10;
    y2     = (short) (y2 * 8) + 0x18;
    SetEntryFields02154bcc(x2, y2, state->renderer, LabelTile, 0x54, 8);
}

#if defined(jpn)
#undef data_ov002_0216c98a
#endif
