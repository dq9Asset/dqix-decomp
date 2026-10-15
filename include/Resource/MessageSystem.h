#pragma once

#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/MessageGlyphSlot.h"
#include "Resource/FontGlyphTable.h"
#include "Resource/PairTableEncoder.h"
#include "Resource/MessageFrame.h"
#include "Resource/MessageRenderResources.h"
#include "Resource/MessageUpdate.h"
#include "Resource/ItemNameText.h"
#include "World/ZoneLootableRecord.h"

class SafeAllocator;

union MessageScratchBuffer {
    char text[0x960];
    unsigned char pixels[0x960];
};
typedef char MessageScratchBufferSizeCheck[sizeof(MessageScratchBuffer) == 0x960 ? 1 : -1];

struct Foo02042fcc {
    short x;
    short y;
    short width;
    short height;
    int state;
    int field0c;
    int field10;
    int field14;
    short field18;
};

struct InitSubstruct0205c73cData {
    unsigned int f0, f4, f8, fc;
    unsigned short f10;
    unsigned char f12, f13, f14, f15, f16;
};

struct Struct_0205ba2c {
    int count, pages, columns, rows;
    unsigned char orientation;
    int page, column, row;
    int* primaryDimension;
    int* secondaryDimension;
    int* primaryCursor;
    int* secondaryCursor;
};

struct Struct_0205bbcc {
    Struct_0205ba2c base;
    int selectedIndex, rectangleCount;
    short xOffset, yOffset;
    short* lefts;
    short* tops;
    short* widths;
    short* heights;
    unsigned char field4c, field4d, field4e;
};

struct Struct_0205bef8 {
    Struct_0205ba2c base;
    int step;
    unsigned short key;
    unsigned char rowRepeat, columnRepeat, countdown, initialDelay, repeatDelay;
    unsigned char pad3b;
    unsigned char wrapColumns, wrapRows;
};

struct Struct_0205c53c {
    int field0;
    Struct_0205bbcc first;
    Struct_0205bef8 second;
    unsigned char field94, field95;
};

struct InitTarget0205cfd4 {
    Struct_0205c53c channels;
    int f98;
    int f9c;
    unsigned short fa0;
    unsigned short fa2;
    unsigned short fa4;
    unsigned short fa6;
    unsigned short fa8;
    unsigned short faa;
    unsigned short fac;
    unsigned short fae;
    unsigned char fb0;
    unsigned char fb1;
    unsigned char fb2;
    unsigned char fb3;
    unsigned char fb4;
    unsigned char fb5;
    unsigned char fb6;
    unsigned char fb7;
    unsigned char fb8;
};

struct MessageChoicePanel {
    int field0;
    InitSubstruct0205c73cData setup;
    Struct_0205c53c channels;
    Foo02042fcc bounds;
    int state;
    int columnSpacing;
    int rowSpacing;
    int fielddc;
    char bufferE0[16];
    char bufferF0[16];
    char buffer100[16];
    char buffer110[16];
#if defined(jpn)
    unsigned short text[0x48];
#else
    unsigned short text[0x80];
#endif
    unsigned short offsets[8];
    short textLength;
    unsigned char choiceCount;
    unsigned char showBounds;
    unsigned char enabled;
    unsigned char unknownFlags[3];
};

void InitSubstruct0205c73c(InitSubstruct0205c73cData*);
void InitStruct_0205ba2c(Struct_0205ba2c*);
void Init0205bbcc(Struct_0205bbcc*);
void Init0205bef8(Struct_0205bef8*);
void InitChannelPair0205c53c(Struct_0205c53c*);
void ForwardInitChannelPair0205c564(Struct_0205c53c*);
void InitBigStruct0205c790(MessageChoicePanel*);
void InitBigStructVariant0205c840(MessageChoicePanel*);
int GetActiveScaledSum0205c570(Struct_0205c53c*);
int ComputeScaledSum0205bb84(Struct_0205ba2c*);
int GetScaledSumIfActive0205bd04(Struct_0205bbcc*);
int CheckActive0205bd20(Struct_0205bbcc*, int);
extern "C" void func_0205c96c(MessageChoicePanel*, int);

struct MessageSlotController {
    Foo02048004 slots[8];
    Foo02042fcc* currentBounds;
    SafeAllocator* allocator;
};

struct Rect02042c54 {
    int left;
    int top;
    int right;
    int bottom;
};

struct MessageTextContext {
    unsigned char pad00[8];
    unsigned char* stagingBuffer;
    unsigned char pad0c[0xa0 - 0x0c];
    int bufferOffset;
    int bufferBytes;
    short width;
    short count;
    short x;
    short y;
    short fieldb0;
    short fieldb2;
    short fieldb4;
    short fieldb6;
    short fieldb8;
    short fieldba;
    unsigned char padbc[6];
    short frame;
    unsigned char padc4[0xe0 - 0xc4];
};

union MessagePosition {
    struct { int x, y; };
    long long packed;
};

struct DstStruct0208baec {
    unsigned char field_0[0xc];
    int x, y, width, height;
    unsigned short value, field_1e, style;
    unsigned char flags;
    unsigned char field_23[5];
};
struct TransitionOwner0208cfcc;
struct TransitionList0208cfcc {
    char padding[0x40];
    DstStruct0208baec* entries;
    char padding_44[8];
    unsigned short type;
    char padding_4e[2];
    unsigned char active;
    char padding_51[3];
};
// Existing child storage shared by message and transition controllers.
struct MessageControlOwner {
    TransitionOwner0208cfcc* owner;
    char padding_4[0x5c];
    TransitionList0208cfcc list;
    DstStruct0208baec* entries;
    char padding_b8[4];
    int handle;
    int task;
    int field_c4;
    int counter;
    float blend;
    unsigned short timer;
    short value;
    unsigned char state;
    unsigned char transitionStage;
    unsigned char field_d6;
    unsigned char field_d7;
    unsigned char field_d8;
    signed char delay;
    unsigned short flags;
    unsigned char field_dc;
    unsigned char field_dd;
    unsigned char padding_de[6];
};
void SetFieldD20208bf28(MessageControlOwner*, int, unsigned char);
void ClearField0xd0AndSetFlag0x1IfByte0xd4Not2_0208be94(MessageControlOwner*);
void SetFlag0x2IfByte0xd4Not3_0208beb4(MessageControlOwner*);

#if defined(jpn)

struct Entry020e2cc4 {
    unsigned char state;
    unsigned char type;
    unsigned char subtype;
};
struct BattleEntry0204500c {
    Entry020e2cc4 prefix;
    unsigned char reserved[0x21];
};
struct BattleFlags0204500c {
    unsigned char streamMode : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 1;
    unsigned char flag5 : 1;
    unsigned char remaining : 2;
};
struct Struct0204394c;
struct MessageSystem0219050c;

struct MessageSystem {
    int CheckAndClearFlag020656e4(int unusedDelta);
    unsigned short GetIndexedHalfword_020656d0();
    void Forward020444d4(int ticks);
    int FindAndSetFirstFreeBit_02042a90(unsigned char* p, unsigned int count);
    void HandleRepeatInput02045740();
    void HandleStateChange020455f8();
    void ProcessPendingFlag02045688();
    int func_020440cc();
    void DispatchStateChange(int state);
    void HandleActorStateTransition(int state);
    void HandleMultipleChoiceResult(int result);
    MessageTextContext* textContext;
    MessageFrame* frame;
    unsigned char pad8[4];
    int stream40;
    int stream44;
    void* textBuffer;
    unsigned short* firstLineBuffer;
    unsigned short* secondLineBuffer;
    unsigned short* tokenStart;
    unsigned short* tokenCursor;
    char* savedTextBuffer;
    MessageScratchBuffer* formatBuffer;
    char* expandedBuffer;
    unsigned int tokenLength;
    unsigned int tokenCount;
    int producedLength;
    int lineStart;
    unsigned int tokenIndex;
    unsigned char pad48[4];
    MessageControlOwner* child;
    MessageChoicePanel choicePanel;
    int choicePending;
    unsigned char bitmapAllocationBits[4];
    int messageLoadTask;
    SafeAllocator* messageAllocator;
    LoadTable* messageRenderer;
    Struct0205a198* messageSprites;
    Container0205a3d0* messageSpriteEntries;
    unsigned short field234;
    unsigned char spriteEntriesEnabled;
    unsigned char messageLoadState;
    int field238;
    char fixedTextBuffers[5][0x40];
    char indexedNames[16][0x40];
    int field77c;
    int indexedValues[16];
    unsigned char field7c0;
    unsigned char indexedNumberPaddingModes[16];
    unsigned char field7d1;
    unsigned char indexedNumberWidths[16];
    signed char b912;
    unsigned char pad7e3;
    Foo02042fcc primaryBounds;
    Foo02042fcc foo930;
    int w94c[4];
    unsigned char block95c[0x20];
    unsigned char block97c[0x10];
    int choiceMode;
    int w990;
    int w994;
    int active;
    int state;
    int mode;
    int w9a4;
    int fadeHoldDuration;
    int fadeHoldElapsed;
    int w9b0;
    int allocatedGlyphCount;
    State0204166c glyphs[0x80];
    unsigned char glyphReferences[0x80];
    int selectedEntry;
    int selectedValue;
    int unknown1710;
    int pendingValue;
    Rect02042c54 textRectangle;
    MessagePosition popupPosition;
    int w1860;
    int w1864;
    int w1868;
    int textDelayCounters[4];
    unsigned short textColor;
    unsigned short h187e;
    signed char formatterCombatantId;
    unsigned char pad1751;
    unsigned short lineGlyphSlots[0x10];
    unsigned short lineGlyphCount;
    short h1944;
    short pendingActorId;
    signed char levels[4];
    signed char b194e[4];
    signed char b1952[4];
    signed char b1956;
    signed char b1957;
    signed char b1958;
    unsigned char textWaitTicks;
    unsigned char b195a;
    unsigned char b195b;
    unsigned char textVariant;
    unsigned char b195d;
    unsigned char field178c;
    unsigned char advanceCountdown;
    unsigned char b1960;
    unsigned char inputDelay;
    unsigned char showEntries;
    unsigned char pad1791[3];
    BattleEntry0204500c entries[2];
    signed char b19ac;
    unsigned char b19ad;
    signed char b19ae;
    unsigned char b19af;
    unsigned char drawEnabled;
    unsigned char b19b1;
    unsigned char b19b2;
    unsigned char b19b3;
    unsigned char b19b4;
    unsigned char b19b5;
    unsigned char pendingValueActive;
    unsigned char textAnimationActive;
    unsigned char b19b8;
    unsigned char clipEnabled;
    unsigned char choiceEnabled;
    unsigned char b19bb;
    unsigned char b19bc;
    unsigned char b19bd;
    unsigned char b19be;
    unsigned char b19bf;
    unsigned char b19c0;
    unsigned char b19c1;
    unsigned char field17f2;
    unsigned char b19c2;
    unsigned char b19c3;
    unsigned char b19c4;
    unsigned char b19c5;
    unsigned char b19c6;
    unsigned char b19c7;
    unsigned char b19c8;
    unsigned char b19c9;
    unsigned char b19ca;
    unsigned char compositeBoundsEnabled;
    unsigned char b19cc;
    unsigned char b19cd;
    BattleFlags0204500c flags17ff;
    short delayOverride;
    unsigned char pad1802[2];
    MessageSlotController controller;
    Foo0207df50* encoder;
};

typedef char VerifyStateSize0204500c[sizeof(State0204166c) == 0x1c ? 1 : -1];
typedef char VerifyRecordSize0204500c[sizeof(BattleEntry0204500c) == 0x24 ? 1 : -1];
typedef char VerifyStatesOffset0204500c[offsetof(MessageSystem, glyphs) == 0x888 ? 1 : -1];
typedef char VerifySlotOffset0204500c[offsetof(MessageSystem, lineGlyphSlots) == 0x1752 ? 1 : -1];
typedef char VerifyEntryOffset0204500c[offsetof(MessageSystem, entries) == 0x1794 ? 1 : -1];
typedef char VerifyFlagsOffset0204500c[offsetof(MessageSystem, flags17ff) == 0x17ff ? 1 : -1];
typedef char VerifyEncoderOffset0204500c[offsetof(MessageSystem, encoder) == 0x1c4c ? 1 : -1];

#else

struct Entry020e2cc4 {
    unsigned char data[0x24];
};

struct Struct0204394c;
struct Ctx0206a974;
struct CombatSlots0206b198;
struct RingBuffer02045824;

struct MessageSystem {
    int CheckAndClearFlag020656e4(int unusedDelta);
    unsigned short GetIndexedHalfword_020656d0();
    void Forward020444d4(int ticks);
    int FindAndSetFirstFreeBit_02042a90(unsigned char* p, unsigned int count);
    void HandleRepeatInput02045740();
    void HandleStateChange020455f8();
    void ProcessPendingFlag02045688();
    int func_020440cc();
    void DispatchStateChange(int state);
    void HandleActorStateTransition(int state);
    void* actorNames[2];
    void* actionNames[2];
    void* targetNames[2];
    ItemNameText* itemNames[2];
    void* monsterNames[2];
    ItemNameText* nameDescriptor28;
    void* field2c;
    signed char cursor30;
    signed char cursor31;
    unsigned char pad32[2];
    MessageTextContext* textContext;
    MessageFrame* frame;
    unsigned char pad3c[0x4];
    int stream40;
    int stream44;
    void* textBuffer;
    unsigned short* firstLineBuffer;
    char* secondLineBuffer;
    char* tokenStart;
    char* tokenCursor;
    char* savedTextBuffer;
    MessageScratchBuffer* formatBuffer;
    char* expandedBuffer;
    unsigned int tokenLength;
    unsigned int tokenCount;
    int producedLength;
    int lineStart;
    unsigned int tokenIndex;
    int field7c;
    int textProgressAccumulator;
    int captionStart;
    int slotReleaseIndex;
    MessageControlOwner* child;
    MessageChoicePanel choicePanel;
    int choicePending;
    unsigned char bitmapAllocationBits[4];
    int messageLoadTask;
    SafeAllocator* messageAllocator;
    LoadTable* messageRenderer;
    Struct0205a198* messageSprites;
    Container0205a3d0* messageSpriteEntries;
    unsigned short field234;
    unsigned char spriteEntriesEnabled;
    unsigned char messageLoadState;
    int field238;
    char fixedTextBuffers[7][0x40];
    char indexedNames[16][0x40];
    int field77c;
    int indexedValues[16];
    unsigned char field7c0;
    unsigned char indexedNumberPaddingModes[16];
    unsigned char field7d1;
    unsigned char indexedNumberWidths[16];
    signed char b912;
    unsigned char pad913;
    Foo02042fcc primaryBounds;
    Foo02042fcc foo930;
    int w94c[4];
    unsigned char block95c[0x20];
    unsigned char block97c[0x10];
    int choiceMode;
    int w990;
    int w994;
    int active;
    int state;
    int mode;
    int w9a4;
    int fadeHoldDuration;
    int fadeHoldElapsed;
    int w9b0;
    int allocatedGlyphCount;
    State0204166c glyphs[0x80];
    unsigned char glyphReferences[0x80];
    int selectedEntry;
    int selectedValue;
    int unknown1840;
    int pendingValue;
    Rect02042c54 textRectangle;
    MessagePosition popupPosition;
    int w1860;
    int w1864;
    int w1868;
    int textDelayCounters[4];
    unsigned short textColor;
    unsigned short h187e;
    signed char formatterCombatantId;
    unsigned char pad1881;
    unsigned short lineGlyphSlots[0x40];
    char captionText[0x40];
    unsigned short lineGlyphCount;
    short captionWidth;
    short h1946;
    short pendingActorId;
    signed char levels[4];
    signed char b194e[4];
    signed char b1952[4];
    signed char b1956;
    signed char b1957;
    signed char b1958;
    unsigned char textWaitTicks;
    unsigned char b195a;
    unsigned char b195b;
    unsigned char textVariant;
    unsigned char b195d;
    unsigned char field195e;
    unsigned char advanceCountdown;
    unsigned char b1960;
    unsigned char inputDelay;
    unsigned char showEntries;
    unsigned char pad1963;
    Entry020e2cc4 entries[2];
    signed char b19ac;
    signed char b19ad;
    signed char b19ae;
    unsigned char b19af;
    unsigned char drawEnabled;
    unsigned char b19b1;
    unsigned char b19b2;
    unsigned char b19b3;
    unsigned char b19b4;
    unsigned char b19b5;
    unsigned char pendingValueActive;
    unsigned char textAnimationActive;
    unsigned char b19b8;
    unsigned char clipEnabled;
    unsigned char choiceEnabled;
    unsigned char b19bb;
    unsigned char b19bc;
    unsigned char b19bd;
    unsigned char b19be;
    unsigned char b19bf;
    unsigned char b19c0;
    unsigned char b19c1;
    unsigned char b19c2;
    unsigned char b19c3;
    unsigned char b19c4;
    unsigned char b19c5;
    unsigned char b19c6;
    unsigned char b19c7;
    unsigned char b19c8;
    unsigned char b19c9;
    unsigned char b19ca;
    unsigned char compositeBoundsEnabled;
    unsigned char b19cc;
    unsigned char b19cd;
    unsigned char b19ce;
    unsigned char b19cf;
    unsigned char b19d0;
    unsigned char b19d1;
    unsigned char b19d2;
    unsigned char b19d3;
    unsigned char flag19d4;
    unsigned char flag19d5;
    unsigned char flag19d6;
    unsigned char flag19d7;
    unsigned char flag19d8;
    unsigned char pad19d9;
    short delayOverride;
    unsigned char b19dc;
    unsigned char pad19dd[3];
    MessageSlotController controller;
    Foo0207df50* encoder;
};

#endif

#if defined(jpn)
extern "C" void func_0204500c(MessageSystem* window, const char* text, int mode);
#else
extern "C" void func_0204500c(MessageSystem* window, const char* text, int mode, int boxWidth);
#endif

struct MessageSystemGlobals {
#if defined(jpn)
    int* scriptState;
    unsigned char* glyphAssets;
    char* expandedBuffer;
    unsigned char pad0c[4];
    unsigned short* firstLineBuffer;
    FontGlyphTable* font6;
    void* textBuffer;
    char* savedTextBuffer;
    FontGlyphTable* font8;
    FontGlyphTable* font10;
    FontGlyphTable* font12;
    int* scriptBuffer;
    unsigned char* glyphPixels;
    unsigned short* secondLineBuffer;
    MessageSystem* messageSystem;
    MessageScratchBuffer* formatBuffer;
#else
    unsigned char* glyphPixels;
    unsigned char* glyphAssets;
    unsigned short* firstLineBuffer;
    char* expandedBuffer;
    FontGlyphTable* font8;
    void* textBuffer;
    MessageScratchBuffer* formatBuffer;
    MessageSystem* messageSystem;
    unsigned char pad20[4];
    char* savedTextBuffer;
    char* secondLineBuffer;
#endif
};

extern MessageSystemGlobals data_02107800;

void SetField0x1e20_02042b10(MessageSystem*, Foo02042fcc*);
void InitSelfPointer_02042b1c(MessageSystem*);
int CheckField0x440State2_0205cd6c(MessageSlotController*);
void SetupField440Type3(MessageSlotController*);
