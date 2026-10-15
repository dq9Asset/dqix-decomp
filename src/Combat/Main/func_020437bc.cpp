#include <globaldefs.h>

struct Rectangle020437bc {
    short x, y, width, height;
};

extern const unsigned char data_020e7ade[][8];

// USA: func_020437bc
extern "C" ARM void func_020437bc(unsigned short* map, const Rectangle020437bc* rectangle, int style) {
    if (map == NULL || rectangle == NULL) return;
    if (rectangle->width == 0 || rectangle->height == 0) return;
    short bottom;
    const unsigned char* tiles = data_020e7ade[style];
    short left = rectangle->x;
    short top = rectangle->y;
    short right = left + rectangle->width;
    bottom = top + rectangle->height;
    left >>= 3;
    top >>= 3;
    right >>= 3;
    bottom >>= 3;
    short topRow = top * 32;
    short bottomRow = bottom * 32;
    (map + topRow)[left] = tiles[0] - 0x13;
    (map + topRow)[right] = tiles[1] - 0x13;
    (map + bottomRow)[left] = tiles[2] - 0x13;
    (map + bottomRow)[right] = tiles[3] - 0x13;
    for (short x = left + 1; x < right; x++) {
        (map + topRow)[x] = tiles[4] - 0x13;
        (map + bottomRow)[x] = tiles[5] - 0x13;
    }
    for (short y = top + 1; y < bottom; y++) {
        short row = y * 32;
        (map + row)[left] = tiles[6] - 0x13;
        (map + row)[right] = tiles[7] - 0x13;
    }
    for (short y = top + 1; y < bottom; y++) {
        short row = y * 32;
        for (short x = left + 1; x < right; x++) {
            (map + row)[x] = 1;
        }
    }
}
