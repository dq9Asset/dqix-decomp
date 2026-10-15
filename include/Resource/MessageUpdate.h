#pragma once

#if !defined(jpn)
struct TagEntry02069fec {
    const char* name;
    int (*fn)(char**, const char*);
};
struct NameList02069fec {
    const char* p[6];
};
#endif

#include "Resource/MessageGlyphSlot.h"

struct MessageSystem;
#if !defined(jpn)
void SetRingBufferSlot02045824(MessageSystem* messages, int value, int index);
extern "C" void func_020462d0(MessageSystem* messages, unsigned short* codes, int count);
#endif
struct MessageSlotController;
struct Foo02042fcc;
struct Rect02042c54;
struct MessageTextContext;
extern "C" void func_02066cf0(MessageSystem* window, int flags);
void RunStageSequence02067e98(MessageSystem* window, const char* text);

void InitEightSubStructs_0202f1a4(MessageSlotController* controller);
void ReinitEightSubStructsAndAllocator_0202f1dc(MessageSlotController* controller);
void ClearField8ViaPointer0x440(MessageSlotController* controller);
void SetupField440Type1(MessageSlotController* controller);
int IsField440Empty_0205ce28(MessageSlotController* controller);
void UpdateTimedState0202f380(MessageSlotController* controller, int step);
void EmitScaledField0x440_0202f404(MessageSlotController* controller, int x, int y);
#if defined(jpn)
extern "C" void func_0206cf44(MessageSystem* window);
#else
void MeasureTextWidth0206b6b8(MessageSystem* window);
#endif
#if !defined(jpn)
void GetField440XY_02066cc0(MessageSlotController* controller, short* x, short* y);
#endif
void ResetFoo02042fcc(Foo02042fcc* bounds);
void SetSubstructXY02042c24(MessageSlotController* controller, int x, int y);
void SetSubstructSize02042c3c(MessageSlotController* controller, int width, int height);
void SetRect02042c54(Rect02042c54* bounds, int left, int top, int right, int bottom);
void LoadStateBytePair0206b804(MessageSystem* window, int* x, int* y);
extern "C" void func_02044c74(MessageSystem* window, MessageTextContext* output);
#if defined(jpn)
extern "C" void func_02043270(MessageSystem* window, int x, int y, int width, int height);
#else
extern "C" void func_02042b98(MessageSystem* window, int x, int y, int width, int height);
#endif

MessageSystem* GetGlobalField0x1c020421a0();
void InitControllerObject_02043000(MessageSystem* window);
void ReinitController02043204(MessageSystem* window);
extern "C" void func_02043124(MessageSystem* window);
extern "C" void func_020439b0(MessageSystem* window, int flag);
extern "C" int func_020457e0(MessageSystem* window);
extern "C" void func_02046380(MessageSystem* window);
void StoreInArray0x8b0_020465c0(MessageSystem* window, int index, int value);
void SetIndexedName02046574(MessageSystem* window, int index, const char* name);
void SetByteAtIndex_020465d8(MessageSystem* window, int index, unsigned char value);
void SetByteInRange_020465f0(MessageSystem* window, int index, unsigned char value);

void Forward020444d4(MessageSystem* window, int ticks);
extern "C" void func_02065990(MessageSystem* window, int ticks);
extern "C" int func_020440cc(MessageSystem* window);
int CheckAndClearFlag020656e4(MessageSystem* window, int unusedDelta);
unsigned short GetIndexedHalfword_020656d0(MessageSystem* window);
void ProcessPendingFlag02045688(MessageSystem* window);
void InitCombatSlots02043040(MessageSystem* window);
void InitCombatSlots02045cac(MessageSystem* window);
void TailForward020440a4(MessageSystem* window);
void Forward0204359c(MessageSystem* window, int count);
extern "C" void func_020432c4(MessageSystem* window);
extern "C" void func_02043368(MessageSystem* window);
extern "C" void func_0202f24c(MessageSlotController* controller);
void LoadEightEntriesFromTable_0202f310(MessageSlotController* controller, void* table, void* context);
void CallFunc0202f310AtField0x19e0_020440b8(MessageSystem* window, void* table, void* context);
#if defined(jpn)
extern "C" void func_0206982c(MessageSystem* window, int count);
#else
void RepeatStepClampedToField0x3c4_02067e58(MessageSystem* window, int count);
#endif
void ResetControllerState020430b0(MessageSystem* window);
extern "C" int func_020657c8(MessageSystem* window, int step);
void HandleRepeatInput02045740(MessageSystem* window);
int UpdateCounterAndFlag02065758(MessageSystem* window, int step);
void StepCounter020456d0(MessageSystem* window);
void ProcessTextTokens0206b61c(MessageSystem* window);
void UpdateStatusTimer_020658ac(MessageSystem* window, unsigned int amount);
void HandleStateChange020455f8(MessageSystem* window);
#if defined(jpn)
extern "C" void func_0206cb14(MessageSystem* window, int fontSize, unsigned short index);
#else
void DecrementSlotRef0206b198(MessageSystem* window, unsigned short index);
#endif

#if defined(jpn)
extern "C" int func_02069430(void* unused, unsigned short token);
extern "C" int func_02069444(void* unused, unsigned short token);
#else
bool IsHighByteFF02044494(void* unused, void* token);
int Dispatch02044420(void* unused, void* token);
#endif

// Message choice state and parser contracts.
#if !defined(jpn)
extern "C" void func_0206b974(MessageSystem* window, bool countLines, char* input, char* output, int boxWidth, int margin, bool includeCaption, unsigned char fontIndex);
void InitContextString0206a974(MessageSystem* window, const char* text, int boxWidth);
extern "C" unsigned short func_02045d14(MessageSystem* window, const char* text, unsigned short* output, unsigned char fontIndex);
extern "C" void func_02045f3c(MessageSystem* window, unsigned short* text, int x, int y, unsigned short color, int unused5, int unused6, unsigned char absolute, unsigned char fontIndex, int lineHeight);
extern "C" void func_02069fec(MessageSystem* window, const char* text, char* output);
void CopyStringToIndexedField0x2ec_020464e8(MessageSystem*, int, char*);
#endif
#if defined(jpn)
extern "C" void func_0206c570(MessageSystem* window, const char* text);
extern "C" void func_020698d8(MessageSystem* window, int fontIndex, const char* text, char* output);
extern "C" void func_02069ecc(MessageSystem* window, const char* text, char* output);
#endif
extern "C" void func_020676e0(MessageSystem* window, int ticks);
extern "C" void func_0206b104(MessageSystem* window);
extern "C" void func_0206aa28(MessageSystem* window);
void ResetOrConsumeCounter02065920(MessageSystem* window, unsigned int amount);
#if defined(jpn)
extern "C" void func_0206cba0(MessageSystem* window);
extern "C" void func_0206cbe8(MessageSystem* window, unsigned short token, unsigned short* cursor);
extern "C" unsigned short* func_0206c730(MessageSystem* window, unsigned short token, unsigned short* cursor);
#else
extern "C" void func_0206831c(MessageSystem* window, const char* input, char* output);
extern "C" void func_02068418(void* unused, const char* input, char* output, int value);
extern "C" int func_02068f40(MessageSystem* window, char* input, char* output, int value);
extern "C" void func_02069234(MessageSystem* window, const char* input, char* output, int unusedFontIndex);
extern "C" void func_020695f4(void* unused, const char* input, char* output, int value);
extern "C" void func_020654b8(MessageSystem* window, void* renderer, MessageGlyphSlot* glyph, int value, short offset, unsigned char flags);
extern "C" void func_0206b224(MessageSystem* window);
void InitOrReinitContext0206b2c8(MessageSystem* window, unsigned short token, char* cursor);
extern "C" char* func_0206ac94(MessageSystem* window, unsigned short token, char* cursor);
#endif

#if !defined(jpn)
extern "C" int func_020696bc(const char*, int*, int);
extern "C" int func_02005a94(const char*);
void PushToRingBuffer020457e8(MessageSystem*, int);
#endif
