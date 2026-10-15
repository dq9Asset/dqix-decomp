#include <globaldefs.h>
#include "std_library_functions.h"

struct Window0204f174 {
    char pad0[8];
    unsigned char* pixels;
    char pad0c[0x9c - 0xc];
    int dirty;
    int offset;
    int pixelSize;
    short width;
    short height;
    short x;
    short y;
    char padb0[0xc2 - 0xb0];
    short frame;
    char padc4;
    unsigned char flags;
    char padc6[2];
    short drawWidth;
    short drawHeight;
    char padcc[4];
    int indexSize;
    unsigned short* indices;
};

extern "C" void func_0204f914(Window0204f174* window, int color, short x0, short y0, short x1, short y1);
extern "C" void func_0204ea5c(Window0204f174* window);
extern "C" void func_0204ecb4(Window0204f174* window, int x, int y, short w, short h, signed char* margins);

// USA: func_0204f174
extern "C" ARM void func_0204f174(Window0204f174* window, short x, short y, short width, short height,
                                  unsigned char frame, unsigned char noFrame, unsigned char noBorder,
                                  signed char* margins) {
    window->x = x;
    window->y = y;
    window->frame = frame;
    if (noFrame) {
        window->flags |= 4;
    } else {
        window->flags &= ~4;
    }
    if (noBorder) {
        window->flags |= 0x10;
    } else {
        window->flags &= ~0x10;
    }
    int indexSize = width * height * 2;
    if (window->flags & 1) {
        if (window->width < width) width = window->width;
        if (window->height < height) height = window->height;
        window->drawWidth = width;
        window->drawHeight = height;
        window->indexSize = indexSize;
        memset(window->pixels, 0, window->pixelSize);
        if (!noFrame) {
            short left = 0;
            short top = 0;
            short right = width << 3;
            short bottom = height << 3;
            if (margins) {
                top += margins[0];
                bottom -= margins[0] + margins[1];
                left += margins[2];
                right -= margins[2] + margins[3];
            }
            func_0204f914(window, 0x11, left, top, right, bottom);
        }
    } else {
        window->flags |= 1;
        window->width = width;
        window->height = height;
        window->pixelSize = width * height * 32;
        memset(window->pixels, 0, window->pixelSize);
        if (!noFrame) {
            short left = 0;
            short top = 0;
            short right = width << 3;
            short bottom = height << 3;
            if (margins) {
                top += margins[0];
                bottom -= margins[0] + margins[1];
                left += margins[2];
                right -= margins[2] + margins[3];
            }
            func_0204f914(window, 0x11, left, top, right, bottom);
        }
        memset(window->indices, 0, indexSize);
        short w = window->width;
        short h = window->height;
        window->drawWidth = w;
        window->drawHeight = h;
        window->indexSize = indexSize;
        window->dirty = 1;
    }
    if (!noBorder) {
        if (!noFrame) func_0204ea5c(window);
        func_0204ecb4(window, 0, 0, width, height, margins);
    } else {
        window->flags |= 0x80;
    }
}
