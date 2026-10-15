#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

struct Font02045864 {
    char unk0[4];
    unsigned short rowBits;
    char unk6[6];
    unsigned char* data;
};

extern Font02045864* data_02107834[];

// USA: func_02045864
extern "C" ARM void func_02045864(int x, int y, FontCharacter* glyph, unsigned char* dst, int width, int height,
                                  unsigned char color, unsigned char font) {
    if (glyph == NULL || dst == NULL) {
        return;
    }
    int off = glyph->bitOffset;
    Font02045864* f = data_02107834[font];
    unsigned char hi = color << 4;
    unsigned char lo = color & 0x0f;
    int stride = f->rowBits >> 3;
    signed char bitStart = 7 - (off & 7);
    int pitch = width >> 1;
    for (int i = 0; i < 12; i++) {
        signed char bit = bitStart;
        unsigned char* src = f->data + stride * i + (off >> 3);
        int py = y + i;
        int rowOff = pitch * py;
        if (py < 0 || height <= py) {
            continue;
        }
        for (int j = 0; j < glyph->width; j++) {
            int px = x + j;
            if (px < 0 || width <= px) {
                continue;
            }
            if (*src & (1 << bit)) {
                if (px & 1) {
                    (dst + rowOff)[px >> 1] &= 0x0f;
                    (dst + rowOff)[px >> 1] |= hi;
                } else {
                    (dst + rowOff)[px >> 1] &= 0xf0;
                    (dst + rowOff)[px >> 1] |= lo;
                }
            }
            if (--bit < 0) {
                bit = 7;
                src++;
            }
        }
    }
}
