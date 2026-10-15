#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char unknown0[0xac];
    short x, y;
};
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c* s, int key);
extern "C" void func_0205ac40(LoadTable*, Struct0205a198*);

#if defined(jpn)
enum { SelectionOffset = 0x1340, WindowOffset = 0x90, RendererOffset = 0x1334, SpritesOffset = 0x133c };
#else
enum { SelectionOffset = 0x1370, WindowOffset = 0xac, RendererOffset = 0x135c, SpritesOffset = 0x1364 };
#endif

namespace {
struct CursorCoordinates {
    short x, y;
    unsigned char unknown4[0xe - 4];
    unsigned char spriteIndex;
};
struct CursorSelection {
    CursorCoordinates* coordinates;
};
struct EntryCursorState {
    CursorSelection* selectedEntry;
    unsigned char unknown4[WindowOffset - 4];
    CreationWindow window;
    unsigned char unknownAfterWindow[RendererOffset - WindowOffset - sizeof(CreationWindow)];
    LoadTable* renderer;
    unsigned char unknownAfterRenderer[SpritesOffset - RendererOffset - 4];
    Struct0205a198* sprites;
#if !defined(jpn)
    unsigned char unknownAfterSprites[SelectionOffset - SpritesOffset - 4];
#endif
    unsigned char selection;
    unsigned char key;
#if defined(jpn)
    unsigned char unknownAfterKey[0x13b8 - SelectionOffset - 2];
    int selected;
#endif
};
}

// USA: func_ov023_021e6b04
// JPN: func_ov023_021e7074
ARM void UpdateEntryFromDoublePtr_021e6b04(char* base) {
    EntryCursorState* state = reinterpret_cast<EntryCursorState*>(base);
    if (state->key != 0xe) return;
    if (state->selection >= 0xa) return;

    Elem_0205d81c* elem = FindElementByC40205d81c(reinterpret_cast<Struct_0205d81c*>(&state->window), 0xe);
    if (elem == NULL) return;

#if defined(jpn)
    short elementX = elem->x;
    short elementY = elem->y;
    int selected = state->selected;
    int column = selected / 7;
    int x = column * 16 + 14;
    int y = selected % 7 * 16 + 28;
    if (column >= 5) x += 8;
    if (column >= 10) x += 16;
    Struct0205a198* entry;
    if (column >= 10) entry = state->sprites + 16;
    else entry = state->sprites + 15;
    short offsetX = elementX << 3;
    int cursorX = x + offsetX;
    short offsetY = elementY << 3;
    int cursorY = y + offsetY;
    entry->position[0] = cursorX << 12;
    entry->position[1] = cursorY << 12;
    entry->priority = 2;
#else
    CursorSelection* p1 = state->selectedEntry;
    CursorCoordinates* p2 = p1->coordinates;
    if (p2 == NULL) return;

    unsigned char fieldE = p2->spriteIndex;
    Struct0205a198* sprites = state->sprites;
    Struct0205a198* entry = sprites + (fieldE + 15);
    short v0 = p2->x;
    short v2 = p2->y;
    entry->position[0] = v0 << 12;
    entry->position[1] = v2 << 12;
    entry->priority = 0;
#endif
    func_0205ac40(state->renderer, entry);
}
