#include <globaldefs.h>
#if defined(jpn)
#include "Resource/MessageGlyphSlot.h"

// JPN: func_02041c10
extern "C" ARM void func_02041c10(State0204166c* slot, const char* character, unsigned char* pixels, int bitmapIndex, unsigned int textureOffset, unsigned char fontSize) {
    if (!pixels) return;
    ResetState0204166c(slot);
    slot->encodedCharacter[0] = character[0];
    slot->encodedCharacter[1] = character[1];
    slot->bitmapIndex = bitmapIndex;
    slot->pixels = pixels;
    slot->textureOffset = textureOffset;
    slot->fontPixelSize = fontSize;
    slot->pendingUpload = 1;
    slot->renderFlag1 = 0;
    slot->renderFlag2 = 0;
}
#else

struct State0204166c {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    unsigned short f14;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char pad16 : 4;
    unsigned char f17;
    int f18;
};

void ResetState0204166c(struct State0204166c* s);

// USA: func_020416e0
ARM void InitState0204166c020416e0(struct State0204166c* s, unsigned char arg1, int arg2, int arg3, int arg5, int arg6, unsigned char arg7) {
    if (arg3 == 0) return;
    ResetState0204166c(s);
    s->f17 = arg1;
    s->f18 = arg2;
    s->f8 = arg5;
    s->f0 = arg3;
    s->f4 = arg6;
    s->flag0 = 1;
    s->flag1 = 0;
    s->flag2 = 0;
    s->flag3 = arg7;
}

#endif
