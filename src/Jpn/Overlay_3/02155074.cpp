#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// JPN: func_ov003_02155074
// Cancels pending loads before changing the service selection.
// The category's game meaning is not established; only values 1 through 12 are accepted.
extern "C" ARM void func_ov003_02155074(void* selection, int category) {
    unsigned char* selectionBytes = (unsigned char*)selection;
    if (*(unsigned char*)(selectionBytes + 0x5a) == 0) return;
    signed char selectedSlot = *(signed char*)(selectionBytes + 0x59);
    int validSlot = 0;
    if (selectedSlot < 0) goto check;
    if (selectedSlot <= 3) validSlot = 1;
check:
    if (!validSlot) return;
    if (category <= 0) return;
    if (category >= 0xd) return;
    if (*(int*)(selectionBytes + 0x14) == category) return;

    int backgroundLoader = (int)BackgroundLoader::GetInstance();
    int firstLoadTask = *(int*)(selectionBytes + 0x50);
    if (firstLoadTask >= 0) ((BackgroundLoader*)(backgroundLoader))->RemoveTask((int)(firstLoadTask));
    int secondLoadTask = *(int*)(selectionBytes + 0x54);
    if (secondLoadTask >= 0) ((BackgroundLoader*)(backgroundLoader))->RemoveTask((int)(secondLoadTask));
    *(int*)(selectionBytes + 0x50) = -1;
    *(int*)(selectionBytes + 0x54) = -1;
    *(int*)(selectionBytes + 0x14) = category;
    *(unsigned char*)(selectionBytes + 0x5b) = 0;
    *(unsigned char*)(selectionBytes + 0x5c) = 0;
    *(unsigned char*)(selectionBytes + 0x5d) |= 1;
}

#endif
