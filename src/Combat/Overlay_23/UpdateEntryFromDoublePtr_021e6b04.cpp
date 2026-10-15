#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c* s, int key);
extern "C" void func_0205ac40(SpriteContext0205ac40*, B174Outer*);

// USA: func_ov023_021e6b04
// JPN: func_ov023_021e7074
ARM void UpdateEntryFromDoublePtr_021e6b04(char* base) {
#if defined(jpn)
    const int selectionOffset = 0x1340;
    const int windowOffset = 0x90;
    const int rendererOffset = 0x1334;
#else
    const int selectionOffset = 0x1370;
    const int windowOffset = 0xac;
    const int rendererOffset = 0x135c;
#endif
    if (*(unsigned char*)(base + selectionOffset + 1) != 0xe) return;
    if (*(unsigned char*)(base + selectionOffset) >= 0xa) return;

    Elem_0205d81c* elem = FindElementByC40205d81c((Struct_0205d81c*)(base + windowOffset), 0xe);
    if (elem == NULL) return;

#if defined(jpn)
    short elementX = *(short*)((char*)elem + 0xac);
    short elementY = *(short*)((char*)elem + 0xae);
    int selected = *(int*)(base + 0x13b8);
    int column = selected / 7;
    int x = column * 16 + 14;
    int y = selected % 7 * 16 + 28;
    if (column >= 5) x += 8;
    if (column >= 10) x += 16;
    B174Outer* entry;
    if (column >= 10) entry = *(B174Outer**)(base + 0x133c) + 16;
    else entry = *(B174Outer**)(base + 0x133c) + 15;
    short offsetX = elementX << 3;
    int cursorX = x + offsetX;
    short offsetY = elementY << 3;
    int cursorY = y + offsetY;
    entry->position[0] = cursorX << 12;
    entry->position[1] = cursorY << 12;
    entry->priority = 2;
#else
    void* p1 = *(void**)base;
    void* p2 = *(void**)p1;
    if (p2 == NULL) return;

    unsigned char fieldE = *((unsigned char*)p2 + 0xe);
    B174Outer* sprites = *(B174Outer**)(base + 0x1364);
    B174Outer* entry = sprites + (fieldE + 15);
    short v0 = *(short*)p2;
    short v2 = *(short*)((char*)p2 + 2);
    entry->position[0] = v0 << 12;
    entry->position[1] = v2 << 12;
    entry->priority = 0;
#endif
    func_0205ac40(*(SpriteContext0205ac40**)(base + rendererOffset), entry);
}
