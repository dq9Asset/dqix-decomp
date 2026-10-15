#include <globaldefs.h>

void WriteReg0400048802047888(int s, int t);

struct Sprite02047718 {
    int polygonId;
    unsigned short texFormat;
    char pad6[0x10 - 0x6];
    unsigned int plttAddr;
    char pad14[0x80 - 0x14];
    unsigned short color;
    short alpha;
};

struct Cell02047718 {
    unsigned int texAddr;
    unsigned short texSize;
    unsigned short position;
};

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

// USA: func_02047718
extern "C" ARM void func_02047718(Sprite02047718* obj, Cell02047718* cell, int pltt0) {
    *(volatile unsigned int*)0x04000444 = 0;
    int s = cell->texSize & 0xf;
    int t = (cell->texSize & 0xf0) >> 4;
    int w = 8 << (s + 12);
    int h = 8 << (t + 12);
    int x = (cell->position & 0xff) << 12;
    int y = ((cell->position & 0xff00) >> 8) << 12;
    int fmt = obj->texFormat;
    fmt <<= 26;
    *(volatile unsigned int*)0x040004a8 = (cell->texAddr >> 3) | fmt | (s << 20) | (t << 23) | (pltt0 << 29);
    *(volatile unsigned int*)0x040004ac = obj->plttAddr >> (4 - (obj->texFormat == 2));
    int alpha = obj->alpha & 0x1f;
    alpha <<= 16;
    *(volatile unsigned int*)0x040004a4 = 0x80c0 | (obj->polygonId << 24) | alpha;
    Translate(x, y, 0);
    Scale(w, h, 0x1000);

    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = obj->color;
    *(volatile unsigned int*)0x04000488 = 0;
    Vertex(0, 0x1000, 0);
    WriteReg0400048802047888(w, 0);
    Vertex(0x1000, 0x1000, 0);
    WriteReg0400048802047888(w, h);
    Vertex(0x1000, 0, 0);
    WriteReg0400048802047888(0, h);
    Vertex(0, 0, 0);
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
}
