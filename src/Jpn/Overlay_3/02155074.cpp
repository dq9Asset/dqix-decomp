#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// JPN: func_ov003_02155074
extern "C" ARM void func_ov003_02155074(void* obj, int cat) {
    unsigned char* o = (unsigned char*)obj;
    if (*(unsigned char*)(o + 0x5a) == 0) return;
    signed char b = *(signed char*)(o + 0x59);
    int ok = 0;
    if (b < 0) goto check;
    if (b <= 3) ok = 1;
check:
    if (!ok) return;
    if (cat <= 0) return;
    if (cat >= 0xd) return;
    if (*(int*)(o + 0x14) == cat) return;

    int listPtr = (int)BackgroundLoader::GetInstance();
    int f50 = *(int*)(o + 0x50);
    if (f50 >= 0) ((BackgroundLoader*)(listPtr))->RemoveTask((int)(f50));
    int f54 = *(int*)(o + 0x54);
    if (f54 >= 0) ((BackgroundLoader*)(listPtr))->RemoveTask((int)(f54));
    *(int*)(o + 0x50) = -1;
    *(int*)(o + 0x54) = -1;
    *(int*)(o + 0x14) = cat;
    *(unsigned char*)(o + 0x5b) = 0;
    *(unsigned char*)(o + 0x5c) = 0;
    *(unsigned char*)(o + 0x5d) |= 1;
}

#endif
