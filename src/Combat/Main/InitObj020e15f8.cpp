#include <globaldefs.h>
#include "Resource/MessageFrame.h"

// USA: func_020e15f8
ARM void InitObj020e15f8(MessageFrame* frame, int arg1, int arg2) {
    frame->stagingBuffer = NULL;
    frame->panel = NULL;
    frame->count = 0;
    int i;
    for (i = 0; i < 3; i++) {
        StoreFourShorts(&frame->rectangles[i], 0, 0, 0, 0);
    }
    frame->paletteColors[0] = 0x7fff;
    frame->paletteColors[1] = 0xf0a;
    Init020e2bd8(&frame->metadata, arg1, arg2);
}
