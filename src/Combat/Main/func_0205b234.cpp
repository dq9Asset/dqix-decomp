#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"
#include "Resource/MessageFrame.h"

#if !defined(jpn)


int GetWordFromTable02042648(int);
int LookupKeyValue020425e4(int, int, int);
extern "C" void func_0205b36c(GlyphDestination0205b234* destination, FontCharacter* glyph, short x, short y, unsigned char color, unsigned char font);

// USA: func_0205b234
extern "C" ARM int func_0205b234(GlyphDestination0205b234* destination, short x, short y, const char* text, unsigned char color, unsigned char font) {
    if (destination->pixels == 0) return 0;
    if (destination->rectangles == 0) return 0;
    if (destination->rectangleCount == 0) return 0;
    if (text == 0) return 0;
    unsigned char fallbackWidth = GetWordFromTable02042648(font);
    int previousCharacter = 0xff;
    short cursorX = x;
    while (*text != 0) {
        int index;
        signed char advance = fallbackWidth + 1;
        index = FindEntryIndexByKey020424e4(text, font) & 0xff;
        cursorX += LookupKeyValue020425e4(previousCharacter, index, font);
        int length = 1;
        if (index != 0xff) {
            FontCharacter* character = GetBoundedEntry020425b4(index, font);
            func_0205b36c(destination, character, cursorX, y, color, font);
            advance = character->width + 1;
            length = character->byteLength;
        }
        previousCharacter = index;
        text += length;
        cursorX += advance;
    }
    return cursorX - x;
}
#endif
