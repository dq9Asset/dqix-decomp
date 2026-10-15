#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/MessageSystem.h"

extern const unsigned char data_020e7a8c[];
extern const short data_020e7aa6[];
extern const short data_020e7ab0[];

void InitState0204166c020416e0(State0204166c*, unsigned char, int, int, int, int, unsigned char);
extern "C" void func_02045864(int x, int y, FontCharacter* glyph, unsigned char* dst, int width, int height,
                              unsigned char color, unsigned char font);

static inline unsigned int GetVramOffset(Foo0207df50* encoder) {
    return (encoder->textureAllocationKey << 16) >> 13;
}

// USA: func_020459b8
extern "C" ARM int func_020459b8(MessageSystem* sys, unsigned char charIndex, FontCharacter* character,
                                 unsigned char font) {
    if (character == NULL) {
        return 0;
    }
    unsigned char* pixels = data_02107800.glyphPixels;
    unsigned char* refs = sys->glyphReferences;
    State0204166c* slots = sys->glyphs;
    int bitmapIndex = sys->FindAndSetFirstFreeBit_02042a90(sys->bitmapAllocationBits, 4);
    if (bitmapIndex < 0) {
        return 0;
    }
    for (int i = 0; i < 0x80; i++) {
        if (refs[i] == 0) {
            if (sys->encoder != NULL) {
                unsigned char* buf = pixels + (bitmapIndex << 7);
                State0204166c* slot = &slots[i];
                bool outline = false;
                bool shadow = false;
                if (sys->b19cc == 0) {
                    memset(buf, 0, 0x80);
                    if (sys->b195b & 0x80) {
                        shadow = true;
                        for (unsigned char j = 0; j < 5; j++) {
                            func_02045864(data_020e7aa6[j], data_020e7ab0[j], character, buf, 16, 16,
                                          data_020e7a8c[j], font);
                        }
                    } else if (sys->b195b & 2) {
                        outline = true;
                        func_02045864(2, 2, character, buf, 16, 16, 1, font);
                        func_02045864(1, 1, character, buf, 16, 16, 0xf, font);
                    } else {
                        func_02045864(1, 1, character, buf, 16, 16, 0xf, font);
                    }
                }
                InitState0204166c020416e0(slot, charIndex, (int)character, (int)buf, bitmapIndex,
                                          (i << 7) + GetVramOffset(sys->encoder), font);
                if (shadow) {
                    slot->renderFlag2 = 1;
                }
                if (outline) {
                    slot->renderFlag1 = 1;
                }
            }
            refs[i] = 1;
            return i;
        }
    }
    return 0;
}
