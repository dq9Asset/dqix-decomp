#include <globaldefs.h>
#include "Resource/MessageSystem.h"

#if !defined(jpn)

extern "C" void func_0204f41c(void* obj, int x, int y, const char* str, int d, int e, short* outA, short* outB, int zero);

extern const short data_020e7e44[];
extern const short data_020e7e4c[];

// USA: func_020654b8
extern "C" ARM void func_020654b8(MessageSystem* self, void* obj, MessageGlyphSlot* glyph, int x, short a4, unsigned char a5) {
    short v0;
    short v1;
    FontCharacter* character;
    const char* str;
    int y;
    unsigned char g;
    character = glyph->character;
    if (character == 0) return;
    str = character->text;
    y = (short)(a4 - (short)(self->textContext->y * 8));
    g = GetGlobalField0x1c020421a0()->b195b;
    if (g & 0x80) {
        for (unsigned char i = 0; i < 4; i++) {
            func_0204f41c(obj, (short)(x + data_020e7e4c[i]), (short)(y + data_020e7e44[i]), str, 10, 1, &v0, &v1,
                          self->b19dc);
        }
        func_0204f41c(obj, (short)(x + 1), (short)(y + 1), str, 10, a5, &v0, &v1, self->b19dc);
    } else if (g & 2) {
        func_0204f41c(obj, (short)(x + 1), (short)(y + 1), str, 10, 1, &v0, &v1, self->b19dc);
        func_0204f41c(obj, (short)x, (short)y, str, 10, a5, &v0, &v1, self->b19dc);
    } else {
        func_0204f41c(obj, x, y, str, 10, a5, &v0, &v1, self->b19dc);
    }
}

#endif
