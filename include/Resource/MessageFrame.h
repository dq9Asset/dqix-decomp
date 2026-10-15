#pragma once

#include <globaldefs.h>

struct FourShorts020e12a8 {
    short a, b, c, d;
};

struct Struct_020e2bd8 {
    unsigned char field0, field1, field2, pad3;
    int field4, field8, fieldc, field10;
    unsigned char field14[0x10];
};

struct Struct02020520 {
    int offset;
    short x, y, width, height;
};

struct ZeroStruct {
    unsigned int attributes, offset;
    unsigned char x, y, width, height;
};

struct PairAndByte020e1368 {
    unsigned int a, b;
    unsigned char c;
};

struct GlyphDestination0205b234 {
    unsigned char* pixels;
    Struct02020520* rectangles;
    unsigned char rectangleCount;
};
struct MessageFramePanel {
    Struct02020520* layouts;
    GlyphDestination0205b234* object;
    ZeroStruct* clips;
    PairAndByte020e1368 headers[2];
    ZeroStruct clipping;
    int offset;
    int stride;
    unsigned char x, y, width, height;
    unsigned char count;
    unsigned char flag3d;
    unsigned char display;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char remainingFlags : 6;
};

struct MessageFrame {
    unsigned char* stagingBuffer;
    MessageFramePanel* panel;
    unsigned char count;
    unsigned char padding09;
    FourShorts020e12a8 rectangles[3];
    short paletteColors[2];
    unsigned short padding26;
    Struct_020e2bd8 metadata;
};

struct Container0205a3d0;
class SafeAllocator;
struct EntryManager020e2490 {
    Struct02020520* layouts;
    GlyphDestination0205b234* destination;
    ZeroStruct* clips;
    MessageFramePanel* panel;
    MessageFrame* frame;
    signed char byte14, byte15, byte16, byte17;
    short short18, short1a, short1c;
    signed char byte1e, pad1f;
    Container0205a3d0* entries;
};

void ResetBytes020e25cc(EntryManager020e2490* manager);
void ResetSelectionState020e25e8(EntryManager020e2490* manager);
int GetInnerFlagBit0020e28dc(EntryManager020e2490* manager);
int GetField0x15UnlessInactive_020e2918(EntryManager020e2490* manager);
int IsFlag0x2Active020e2984(EntryManager020e2490* manager);
void ClampFieldTo2At0x16(EntryManager020e2490* manager, int value);
void InitEntryManager020e2490(EntryManager020e2490*, int, int, Container0205a3d0*, SafeAllocator*, int, unsigned char);
typedef char EntryManagerSizeCheck[sizeof(EntryManager020e2490) == 0x24 ? 1 : -1];

typedef char MessageFrameSizeCheck[sizeof(MessageFrame) == 0x4c ? 1 : -1];
typedef char MessageFramePanelSizeCheck[sizeof(MessageFramePanel) == 0x40 ? 1 : -1];

void StoreFourShorts(FourShorts020e12a8* rectangle, short a, short b, short c, short d);
void Init020e2bd8(Struct_020e2bd8* metadata, int arg1, int arg2);
void ClearStruct02020520(Struct02020520* layout);
void ClearZeroStruct_020e1568(ZeroStruct* clip);
void ClearHeaderFields020e1354(PairAndByte020e1368* header);
void SetPairAndByte020e1368(PairAndByte020e1368* header, unsigned int a, unsigned int b, unsigned char c);
void SetFields020e1374(PairAndByte020e1368* headers, unsigned int a, unsigned int b, int c);
void InitStruct020e1588(MessageFramePanel* panel);
void InitObj020e15f8(MessageFrame* frame, int arg1, int arg2);
void ClearFlag0x1SetFlag0x2_020e1cb8(MessageFrame* frame);
MessageFramePanel* GetField4Ptr020e1b24(MessageFrame* frame);
void InvokeSubHandlerIfPresent_020e2478(MessageFrame* frame);
void ClearTwoWordsAndByte_0205b20c(GlyphDestination0205b234* destination);
void SetField0_0205b220(GlyphDestination0205b234* destination, unsigned char* pixels);
#if defined(jpn)
extern "C" void func_0205c9ac(GlyphDestination0205b234*, short, short, int, int, int, unsigned char, unsigned char);
#else
void PositionAndFormatValueLabel0205b674(GlyphDestination0205b234*, short, short, int, unsigned char, unsigned char, unsigned char, unsigned char);
#endif
void SetFieldsAt0x4And0x8_0205b228(GlyphDestination0205b234* destination, Struct02020520* rectangles, unsigned char count);
Struct02020520* FindRectContainingPoint0205b1ac(Struct02020520* rectangles, unsigned int count, int x, int y);
extern "C" void func_0205b530(GlyphDestination0205b234*, unsigned char*, short, short, int, int);
extern "C" void func_0205b734(GlyphDestination0205b234*, short, short, short, short, unsigned char);
int GetHalfProductField8(MessageFramePanel* panel);
extern "C" unsigned char* func_020e1f1c(MessageFrame* frame);
extern "C" void func_020e2018(MessageFrame* frame);
extern "C" int func_020e1b2c(MessageFrame* frame, int capacity);
extern "C" void func_020e2110(MessageFrame* frame);
extern "C" void func_020e23f4(MessageFrame* frame);
void TransferBattleObjPaletteEntries020e16f4(MessageFrame* frame);
void TransferObjPaletteEntry020e1674(MessageFrame* frame, int index, int selection);
void Forward020e23c0(MessageFrame* frame, unsigned char color, short x, short y, short endX, short endY);
void RunCacheHookForField0x14(PairAndByte020e1368* headers);
extern "C" void* func_020e12c0(PairAndByte020e1368* header);
void Dispatch020e13dc(PairAndByte020e1368* headers);
void UpdateObj020e15f8Entry_020e2310(MessageFrame*, int, int, int, const char*, unsigned char, unsigned char);
extern "C" unsigned int func_020e1438(ZeroStruct* output, unsigned int maxCount, unsigned int x, unsigned int yBase, unsigned int width, unsigned int height);
