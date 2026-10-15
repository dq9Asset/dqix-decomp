#include <globaldefs.h>
#include "Resource/MessageSystem.h"

void WriteReg04000488020419f4(int s, int t);

extern int data_021077fc;

static inline void Translate(int x, int y, int z) {
    *(volatile unsigned int*)0x04000470 = x;
    *(volatile unsigned int*)0x04000470 = y;
    *(volatile unsigned int*)0x04000470 = z;
}

static inline void Scale(int x, int y, int z) {
    *(volatile unsigned int*)0x0400046c = x;
    *(volatile unsigned int*)0x0400046c = y;
    *(volatile unsigned int*)0x0400046c = z;
}

static inline void Vertex(unsigned short x, unsigned short y, unsigned short z) {
    *(volatile unsigned int*)0x0400048c = (unsigned short)x | ((unsigned short)y << 16);
    *(volatile unsigned int*)0x0400048c = (unsigned short)z;
}

// USA: func_020417b0
extern "C" ARM void func_020417b0(MessageGlyphSlot* glyph, int color, Rect02042c54* clip, int alpha) {
    if (glyph->bitmapIndex < 0) return;
    if (glyph->pendingUpload) return;
    if (alpha == 0) return;

    *(volatile unsigned int*)0x04000444 = 0;
    Translate(glyph->x << 12, glyph->y << 12, ((short)glyph->depth + 0x400) << 12);
    Scale(0x1000, 0x1000, 0x1000);

    *(volatile unsigned int*)0x04000444 = 0;
    Translate(0, 0x10000, 0);
    Scale(0x1000, -0x1000, 0x1000);

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x040004c0 = 0x7fffffff;
    *(volatile unsigned int*)0x040004c4 = 0x4210;
    *(volatile unsigned int*)0x040004a8 = 0x6c900000u | (glyph->textureOffset >> 3);
    *(volatile unsigned int*)0x040004ac = (unsigned int)data_021077fc >> 4;
    *(volatile unsigned int*)0x040004a4 = 0x3e0000c0 | (alpha << 16);
    Scale(0x10000, 0x10000, 0x1000);

    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = color;

    int size = 16;
    float t = 0.0f;
    int skip = (int)(size * t);
    float height = 1.0f - t;
    if (clip != NULL) {
        if (glyph->y < clip->top) {
            skip += clip->top - glyph->y;
        }
        if (skip > 16) {
            skip = 16;
        }
        height = (16.0f - skip) / 16.0f;
    }
    int texT = skip << 12;
    WriteReg04000488020419f4(0, texT);
    Vertex(0, (int)(4096.0f * height), 0);
    WriteReg04000488020419f4(0x10000, texT);
    Vertex(0x1000, (int)(4096.0f * height), 0);
    WriteReg04000488020419f4(0x10000, 0x10000);
    Vertex(0x1000, 0, 0);
    WriteReg04000488020419f4(0, 0x10000);
    Vertex(0, 0, 0);

    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
}
