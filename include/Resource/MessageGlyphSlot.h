#pragma once

#include <globaldefs.h>

unsigned char* GetTableEntry020421b0(int index);

struct FontCharacter {
    const char* text;
    signed char width;
    signed char byteLength : 6;
    signed char reserved : 1;
    signed char uppercase : 1;
    short bitOffset;
};

FontCharacter* FindEntryByKey0204254c(const char* key, int fontIndex);
int FindEntryIndexByKey020424e4(const char* key, int fontIndex);
FontCharacter* GetBoundedEntry020425b4(int index, int fontIndex);

struct State0204166c {
    unsigned char* pixels;
    unsigned int textureOffset;
    int bitmapIndex;
    int x;
    int y;
#if defined(jpn)
    int depth;
    union {
        unsigned char encodedCharacter[2];
        unsigned short encodedCode;
    };
    unsigned char fontPixelSize;
    unsigned char pendingUpload : 1;
    unsigned char renderFlag1 : 1;
    unsigned char renderFlag2 : 1;
    unsigned char unknownFlags : 5;
#else
    unsigned short depth;
    unsigned char pendingUpload : 1;
    unsigned char renderFlag1 : 1;
    unsigned char renderFlag2 : 1;
    unsigned char fontIndex : 1;
    unsigned char unknownFlags : 4;
    unsigned char characterIndex;
    FontCharacter* character;
#endif
};

typedef State0204166c MessageGlyphSlot;
typedef char MessageGlyphSlotSizeCheck[sizeof(MessageGlyphSlot) == 0x1c ? 1 : -1];

void ResetState0204166c(MessageGlyphSlot* slot);
#if !defined(jpn)
struct Rect02042c54;
const char* GetField0OfSubstructAt0x18(MessageGlyphSlot* slot);
void SetIntIntShortAt0xc_02066ce0(MessageGlyphSlot* slot, int x, int y, short depth);
extern "C" void func_020417b0(MessageGlyphSlot* slot, int color, Rect02042c54* clip, int alpha);
extern "C" void func_02045864(int fontIndex, int value, FontCharacter* glyph, unsigned char* pixels, int x, int y, unsigned char color, unsigned char flags);
#endif
