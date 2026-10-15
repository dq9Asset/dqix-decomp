#include <globaldefs.h>
#include "Resource/MessageFrame.h"

// USA: func_0205b228
ARM void SetFieldsAt0x4And0x8_0205b228(GlyphDestination0205b234* destination, Struct02020520* rectangles, unsigned char count) {
    destination->rectangles = rectangles;
    destination->rectangleCount = count;
}
