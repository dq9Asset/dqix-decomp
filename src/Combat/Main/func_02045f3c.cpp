#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

#if !defined(jpn)

int LookupKeyValue020425e4(int a, int b, int fontIndex);
extern "C" void func_020654b8(void* obj, void* context, MessageGlyphSlot* glyph, short x, short y, int mode);
extern "C" void func_020417b0(MessageGlyphSlot* glyph, int color, void* palette, int alpha);

extern const int data_020e7a94[];

struct Renderer02045f3c {
    char pad0[0x34];
    void* context;
    char pad38[0x980];
    MessageGlyphSlot glyphs[0x80];
    char pad17b8[0x1f8];
    unsigned char enabled;
};

// USA: func_02045f3c
extern "C" ARM void func_02045f3c(Renderer02045f3c* renderer, unsigned short* text, int x, int y, unsigned short color,
                                  int unused5, int unused6, unsigned char absolute, unsigned char fontIndex, int lineHeight) {
    if (text == NULL || renderer->enabled == 0 || text[0] == 0xffff) {
        return;
    }
    int same = 1;
    unsigned short first = text[0];
    for (int j = 1; j < 10; j++) {
        if (first != text[j]) {
            same = 0;
            break;
        }
    }
    if (same) {
        return;
    }
    MessageGlyphSlot* glyph;
    int i;
    int cx;
    unsigned short ch;
    *(volatile int*)0x04000444 = 0;
    int fallbackGlyphWidth = data_020e7a94[fontIndex] & 0xff;
    i = 0;
    unsigned char previousCharacter = 0xff;
    ch = text[0];
    cx = x;
    while (ch != 0xff01) {
        ch = text[i];
        i++;
        if ((ch & 0xff00) == 0xff00) {
            if (ch == 0xff18) {
                cx = x;
                y += lineHeight;
                previousCharacter = 0xff;
                continue;
            }
            if (ch == 0xff19) {
                cx += fallbackGlyphWidth + 1;
                previousCharacter = 0xff;
                continue;
            }
            break;
        }
        if (ch >= 0x80) {
            break;
        }
        glyph = &renderer->glyphs[ch];
        if (glyph->bitmapIndex < 0) {
            break;
        }
        unsigned char characterIndex = glyph->characterIndex;
        cx += LookupKeyValue020425e4(previousCharacter, characterIndex, fontIndex);
        previousCharacter = characterIndex;
        glyph->x = cx;
        glyph->y = y;
        glyph->depth = 0;
        if (absolute) {
            int mode = 15;
            if (color != 0x7fff) {
                mode = 5;
            }
            func_020654b8(renderer, renderer->context, glyph, cx, y, mode);
        } else {
            func_020417b0(glyph, color, 0, 31);
        }
        if (glyph->character) {
            cx += glyph->character->width + 1;
        }
    }
    *(volatile int*)0x04000448 = 1;
}
#endif
