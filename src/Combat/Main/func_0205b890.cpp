#include <globaldefs.h>
#include "Resource/MessageFrame.h"
#include "Resource/MessageRenderResources.h"

#if !defined(jpn)

// USA: func_0205b890
extern "C" ARM void func_0205b890(Struct02020520* rects, int capacity, Struct0205a198* record) {
    unsigned short count;
    int tile;
    Cell0205a658* cell;
    int baseTile;
    int baseX;
    int baseY;
    unsigned short i;
    short x;
    short y;
    short width;
    short height;
    if (!rects || !record) return;
    count = record->count;
    if (capacity < count) return;
    cell = record->copy;
    if (!cell) return;
    for (i = 0; i < count; cell++, i++) {
        x = cell->x & 0x1f;
        y = cell->y & 0xf;
        unsigned short shape = (cell->y & 0xc000) >> 14;
        unsigned short size = (cell->x & 0xc000) >> 14;
        switch (shape) {
        case 0:
            if (size == 0) { width = 8; height = 8; }
            else if (size == 1) { width = 16; height = 16; }
            else if (size == 2) { width = 32; height = 32; }
            else if (size == 3) { width = 64; height = 64; }
            break;
        case 1:
            if (size == 0) { width = 16; height = 8; }
            else if (size == 1) { width = 32; height = 8; }
            else if (size == 2) { width = 32; height = 16; }
            else if (size == 3) { width = 64; height = 32; }
            break;
        case 2:
            if (size == 0) { width = 8; height = 16; }
            else if (size == 1) { width = 8; height = 32; }
            else if (size == 2) { width = 16; height = 32; }
            else if (size == 3) { width = 32; height = 64; }
            break;
        }
        tile = cell->attributes & 0x3ff;
        if (i == 0) {
            baseX = x;
            baseY = y;
            baseTile = tile;
        }
        rects[i].offset = (tile - baseTile) << 5;
        x -= baseX;
        y -= baseY;
        rects[i].x = x;
        rects[i].y = y;
        rects[i].width = width;
        rects[i].height = height;
    }
}
#endif
