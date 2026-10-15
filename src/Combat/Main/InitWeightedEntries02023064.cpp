#include <globaldefs.h>
#include "Resource/MessageFrame.h"

// USA: func_02023064
ARM void InitWeightedEntries02023064(Struct02020520* rectangles, unsigned int count,
    short* x, short* y, short* width, short* height) {
    int offset = 0;
    unsigned int i;
    for (i = 0; i < count; i++) {
        Struct02020520* rectangle = &rectangles[i];
        ClearStruct02020520(rectangle);
        rectangle->offset = offset;
        rectangle->x = x[i];
        rectangle->y = y[i];
        rectangle->width = width[i];
        rectangle->height = height[i];
        offset += (width[i] * height[i]) / 2;
    }
}
