#include <globaldefs.h>
#include "Resource/MessageUpdate.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#define REGION_FLAG(jpnField, usaField) (message->flags17ff.jpnField)
extern "C" void func_020665bc(char*, int, const char*, const char*);
extern const char data_020f07b4[], data_020f07b9[], data_020f07c0[], data_020f07c7[];
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#define REGION_FLAG(jpnField, usaField) (message->usaField)
#endif
#include "GameState/GameState.h"

struct Vec3_020406f8 {
    int v[3];
};

struct SlotA020cf0fc {
    int f0;
    int f4;
    int f8;
    int fc;
};

struct SlotB020cf1a8 {
    int f0;
    int f4;
    int f8;
};

struct Name56_0218d7b0 {
    unsigned char f0;
    unsigned char f1;
    unsigned short f2;
    unsigned char f4;
    unsigned char f5;
};

union Packed0209c830 {
    unsigned int w;
    struct {
        unsigned int a : 7;
        unsigned int b : 4;
        unsigned int c : 5;
        unsigned int d : 5;
        unsigned int e : 6;
    } b;
};

struct Container0205a3d0;
void SetEntryByte14ByKey0205a42c(Container0205a3d0*, int, int);
int IsAnimationActive0209ca2c(void* p);
void SetName56AndFlag_0218d7b0(unsigned char* owner, char* name);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern "C" void func_ov016_0218b5c0(int a, signed char b);
extern "C" void func_ov017_0218b5f8(signed char a);
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
void CallHelperIfFlag_021a5ab0(void* p);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short*, int);
void* GetGlobalPtr021075f4_0203cf4c();
struct EntryList_203dce4;
void* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
struct Node020406f8;
void SelectVec3FromSources020406f8(Vec3_020406f8*, Node020406f8*);
extern "C" int fix32_Atan2(int x, int z);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void func_02065418(int a);
int CallFunc020e0434With02153694_020e51cc(int a);
void InitCombatPairState020652d0(char* obj, int a, int b, int c);
unsigned char* GetWord0x0_0200fb8c(int*);
unsigned char* GetGlobal02109418_02094d6c();
struct GetTableByteOrFFData;
int GetTableByteOrFF_020965ac(GetTableByteOrFFData*, unsigned char);
void RegisterSlotA020cf0fc(int);
void RegisterSlotB020cf1a8(int);
struct Struct0209c830;
void SetValueAndActivate0209c830(Struct0209c830*, int);
extern "C" void func_0205e944(void* p, int v);

extern unsigned char data_02109bf4;
extern unsigned char data_02108760;
extern unsigned char data_02114e30;
extern unsigned char data_02114e54;

// USA: func_02065990
extern "C" ARM void func_02065990(MessageSystem* message, int amount) {
    unsigned char* self = (unsigned char*)message;
    unsigned short tok;
    struct Name56_0218d7b0 nm;
    union Packed0209c830 packed;
    struct Vec3_020406f8 here;
    struct Vec3_020406f8 dst;
    struct SlotA020cf0fc sa;
    struct SlotB020cf1a8 sb;
    struct Vec3_020406f8 src;
    int step = amount;
    if (step == 0) step = 1;

    if (message->messageSpriteEntries != 0 && message->spriteEntriesEnabled != 0 && message->mode == 6) {
        if ((*(unsigned short*)0x4000304 & 0x8000) >> 15 == 1) {
            SetEntryByte14ByKey0205a42c(message->messageSpriteEntries, 0, 0x1e);
        }
        IterateEntries0205a330(message->messageSpriteEntries, step);
    }

    if (message->active == 0) return;

    if (REGION_FLAG(flag3, b19d1) != 0) {
        message->b1958 = message->b1958 - step;
        if (message->b1958 >= 0) return;
        func_0206b104(message);
        ReinitController02043204(message);
        return;
    }

    CheckAndClearFlag020656e4(message, step);
    if (UpdateCounterAndFlag02065758(message, step) != 0) return;

    if (message->b19b1 != 0) {
        UpdateTimedState0202f380(&message->controller, step);
        if (IsField440Empty_0205ce28(&message->controller) != 0) {
            SetupField440Type1(&message->controller);
        }
        Foo02042fcc* w = message->controller.currentBounds;
        int ready;
        if (w != 0) {
            ready = w->state == 2;
        } else {
            ready = 0;
        }
        if (ready == 0) return;
    }

    if (REGION_FLAG(streamMode, b19ce) != 0) message->stream44 = message->tokenIndex;

    if (message->b19b4 != 0) {
        message->w1868 = message->w1868 + step;
        if (message->w1868 < message->w1864) return;
        message->w1868 = 0;
        ProcessTextTokens0206b61c(message);
        message->b19b4 = 0;
        message->mode = 5;
        message->b19b5 = 0;
        return;
    }

    if (func_020657c8(message, step) != 0) return;
    UpdateStatusTimer_020658ac(message, step);

    if ((message->b195b & 1) != 0) {
        if (IsAnimationActive0209ca2c(&data_02109bf4) == 0) {
            message->b195b = message->b195b & ~1;
        }
    } else {
        if (message->child != 0 && message->child->state == 2) return;

        if (message->b19c9 != 0) {
            if (IsAnimationActive0209ca2c(&data_02109bf4) != 0) return;
            message->tokenIndex = message->tokenIndex + 1;
            message->b19c9 = 0;
            return;
        }

        StepCounter020456d0(message);
        if (func_020440cc(message) != 0) {
            REGION_FLAG(flag3, b19d1) = 1;
            message->b1958 = 5;
            return;
        }

        if (message->mode != 5) {
            ResetOrConsumeCounter02065920(message, step);
            if (message->b19bc != 0) {
                HandleRepeatInput02045740(message);
            }
            func_020676e0(message, step);
            ProcessPendingFlag02045688(message);
            return;
        }
    }

    if (REGION_VALUE(message->h1944, message->h1946) < 0 && message->b19c8 == 0) {
        message->b912 = 0;
        ProcessPendingFlag02045688(message);
    }
#if defined(jpn)
    else {
#else
    else if (message->slotReleaseIndex < message->tokenIndex) {
#endif
        if (message->b912 >= 4) {
            message->b912 = message->b912 - 4;
            ProcessPendingFlag02045688(message);
            HandleStateChange020455f8(message);
        }
        message->b912 =
            message->b912 + GameState::GetInstance()->GetTickCount();
    }

    if (message->b19c5 != 0) step = 0x10;
#if defined(jpn)
    int n = step;
    bool skipCount = false;
#else
    if ((message->b195b & 4) != 0 && message->mode != 0) step = 0x18;

    int old = message->textProgressAccumulator >> 4;
    message->textProgressAccumulator += step * 16;
    int n = (message->textProgressAccumulator >> 4) - old;
    if (message->textProgressAccumulator >= 0xffffff) message->textProgressAccumulator = 0;

#endif

    while (n != 0) {
        if (message->tokenCount <= message->tokenIndex) return;
        tok = message->firstLineBuffer[message->tokenIndex];
#if defined(jpn)
        if (func_02069430(self, tok) != 0) {
            int adv = func_02069444(self, tok);
#else
        if (IsHighByteFF02044494(self, &tok) != 0) {
            int adv = Dispatch02044420(self, &tok);
#endif
            if (adv != 0) {
                message->tokenIndex = message->tokenIndex + adv + 1;
                continue;
            }
            if (tok == 0xff01) {
                if ((message->b195b & 4) != 0) {
                    message->b195b = message->b195b | 8;
                }
                message->mode = 0;
                ProcessPendingFlag02045688(message);
                return;
            } else if (tok == 0xff02) {
                message->mode = 0;
                ProcessPendingFlag02045688(message);
                return;
            } else if (tok == 0xff03) {
                message->mode = 0;
                ProcessPendingFlag02045688(message);
                ReinitController02043204(message);
                func_02043124(message);
                return;
            } else if (tok == 0xff0b) {
                message->mode = 4;
                ProcessPendingFlag02045688(message);
                message->advanceCountdown = REGION_VALUE(message->field178c, message->field195e);
                message->b912 = 0;
                if (message->delayOverride >= 0) {
                    message->advanceCountdown = (unsigned char)message->delayOverride;
                    message->delayOverride = -1;
                }
                return;
            } else if (tok == 0xff0c) {
                message->inputDelay = message->b1960;
                message->mode = 1;
                ProcessPendingFlag02045688(message);
                return;
            } else if (tok == 0xff0d) {
                message->mode = 1;
                ProcessPendingFlag02045688(message);
                return;
            } else if (tok == 0xff0a) {
                message->mode = 3;
                ProcessPendingFlag02045688(message);
                return;
            } else if (tok == REGION_VALUE(0xff1d, 0xff1b)) {
                nm.f0 = 0;
                nm.f1 = 0;
                nm.f2 = 0;
                nm.f4 = 0;
                nm.f5 = 0;
                nm.f0 = message->b19c6 == 0;
                nm.f1 = message->b19c7 == 0;
                nm.f2 = message->h187e;
                nm.f4 = 1;
                SetName56AndFlag_0218d7b0(((unsigned char*)func_ov017_0218b5b0()), (char*)&nm);
                message->tokenIndex = message->tokenIndex + 1;
                return;
            } else if (tok == REGION_VALUE(0xff1e, 0xff1c)) {
                int slot = message->b1957;
                if (slot >= 0 && slot < message->b1956) {
                    int val;
                    int kind = message->b1952[slot];
                    val = message->b194e[slot];
                    if (kind > 0) {
                        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 0x65, 0);
                        if (kind == 2) {
                            val = -1;
                            func_ov016_0218b5c0(1, val);
                            func_ov017_0218b5f8(val);
                        }
                    }
                    if (val >= 0xa && val <= 0x32) {
                        int tens = val / 0xa - 1;
                        int okt = tens >= 0 && tens <= 3;
                        if (okt) {
                            func_ov016_0218b5c0(1, tens);
                            func_ov017_0218b5f8(tens);
                        }
                        val = val - (tens + 1) * 0xa;
                    }
                    int okv = val >= 0 && val <= 3;
                    if (okv) {
                        func_ov016_0218b5c0(1, val);
                        func_ov017_0218b5f8(val);
                        unsigned char* who = ((unsigned char*)func_ov017_0218b5b0());
                        if (ListContainsId((ListHead02046b60*)(*(void**)(who + REGION_VALUE(0x34ec, 0x36fc))), 0xc) != 0) {
                            CallHelperIfFlag_021a5ab0(*(void**)(who + REGION_VALUE(0x350c, 0x371c)));
                        }
                    }
                }
                message->b1957 = message->b1957 + 1;
                message->tokenIndex = message->tokenIndex + 1;
                return;
            } else if (tok == REGION_VALUE(0xff1c, 0xff1a)) {
                if (REGION_FLAG(flag2, b19d0) != 0) return;
                ProcessPendingFlag02045688(message);
                message->textDelayCounters[message->b19ac] =
                    message->textDelayCounters[message->b19ac] - 1;
                if (message->textDelayCounters[message->b19ac] > 0) return;
                message->textDelayCounters[message->b19ac] = 0;
                message->tokenIndex = message->tokenIndex + 1;
                message->b19ac = message->b19ac + 1;
                message->b19ac = message->b19ac & 3;
                message->b912 = 0;
                return;
            } else if (tok == REGION_VALUE(0xff1f, 0xff1d)) {
                message->mode = 2;
                ProcessPendingFlag02045688(message);
                return;
            } else if (tok == REGION_VALUE(0xff20, 0xff1e)) {
                ProcessPendingFlag02045688(message);
                message->textDelayCounters[message->b19ac] =
                    message->textDelayCounters[message->b19ac] - 1;
                if (message->textDelayCounters[message->b19ac] > 0) {
                    if (TestFlag0SetAndFlag1Clear_02012444((unsigned short*)&data_02114e30, 0xfe3) == 0 &&
                        (&data_02114e54)[0x55] == 0) {
                        return;
                    }
                }
                message->textDelayCounters[message->b19ac] = 0;
                message->tokenIndex = message->tokenIndex + 1;
                message->b19ac = message->b19ac + 1;
                message->b19ac = message->b19ac & 3;
                message->b912 = 0;
                return;
            } else if (tok == REGION_VALUE(0xff21, 0xff1f)) {
                message->b19ca = 0;
                message->mode = 2;
                ProcessPendingFlag02045688(message);
                return;
            } else if (tok == REGION_VALUE(0xff28, 0xff26)) {
                message->b19b1 = 1;
                message->b19cd = 1;
            } else if (tok == REGION_VALUE(0xff29, 0xff27)) {
                message->b19b1 = 0;
                message->b19cd = 1;
            } else if (tok == REGION_VALUE(0xff2a, 0xff28)) {
                message->b19b8 = 1;
            } else if (tok == REGION_VALUE(0xff2b, 0xff29)) {
                message->b19b8 = 0;
            } else if (tok == REGION_VALUE(0xff2c, 0xff2a)) {
                message->pendingValue = REGION_VALUE(message->unknown1710, message->unknown1840);
                message->pendingValueActive = 1;
                message->tokenIndex = message->tokenIndex + 1;
                ProcessPendingFlag02045688(message);
                return;
            } else if (tok == REGION_VALUE(0xff2e, 0xff2c)) {
                message->pendingValue = message->selectedValue;
                message->pendingValueActive = 1;
                message->tokenIndex = message->tokenIndex + 1;
                ProcessPendingFlag02045688(message);
                return;
            } else if (tok == REGION_VALUE(0xff2f, 0xff2d)) {
                unsigned char* who = (unsigned char*)GameState::GetInstance()->GetUnknownGameObject();
                void* node = GetEntryUnlessFlag0x8000_0203dce4((EntryList_203dce4*)GetGlobalPtr021075f4_0203cf4c(), message->selectedEntry);
                if (who != 0 && node != 0) {
                    here = *(struct Vec3_020406f8*)(who + 0x44);
                    SelectVec3FromSources020406f8(&src, (Node020406f8*)node);
                    dst = src;
                    message->pendingValue = fix32ReduceAngle0To2Pi(fix32_Atan2(here.v[0] - dst.v[0], here.v[2] - dst.v[2]));
                    message->pendingValueActive = 1;
                    ProcessPendingFlag02045688(message);
                }
                message->tokenIndex = message->tokenIndex + 1;
                return;
            } else if (tok == REGION_VALUE(0xff30, 0xff2e)) {
                ProcessPendingFlag02045688(message);
                message->textWaitTicks = 0x3c;
                message->textAnimationActive = 1;
                message->textVariant = 0;
                message->tokenIndex = message->tokenIndex + 1;
                message->b912 = 0;
                DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 6, 0);
                return;
            } else if (tok == REGION_VALUE(0xff31, 0xff2f)) {
                ProcessPendingFlag02045688(message);
                message->textWaitTicks = 0x3c;
                message->textAnimationActive = 1;
                message->textVariant = 1;
                message->tokenIndex = message->tokenIndex + 1;
                message->b912 = 0;
                DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 0x1c, 0);
                return;
            } else if (tok == 0xff04 || tok == 0xff05 || tok == 0xff06 || tok == 0xff07) {
                func_02065418(message->b19cc);
                int first = 0;
                if (message->choicePending == 1 || tok == 0xff05) first = 1;
                message->choicePending = 0;
#if defined(jpn)
                func_020665bc((char*)(self + REGION_VALUE(0x50, 0x90)), first, data_020f07b4, data_020f07b9);
#else
                int a = CallFunc020e0434With02153694_020e51cc(0x1b);
                int b = CallFunc020e0434With02153694_020e51cc(0x1c);
                InitCombatPairState020652d0((char*)(self + REGION_VALUE(0x50, 0x90)), first, a, b);
#endif
                message->w94c[2] = first;
                message->choiceEnabled = 1;
                message->choiceMode = 0;
                message->mode = 6;
                ProcessPendingFlag02045688(message);
                DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 5, 0);
                int alive = 1;
                unsigned char* bs = (unsigned char*)GameState::GetInstance();
                unsigned char* w = GetWord0x0_0200fb8c((int*)bs);
                if ((bs + 0x5000)[REGION_VALUE(0xa68, 0xcc8)] == 2) alive = 0;
                if (w != 0 && alive != 0) (w + 0x4000)[REGION_VALUE(0x134, 0x354)] = 0xa;
                return;
            } else if (tok == 0xff08) {
                volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
                unsigned int bits = (*reg & 0x1f00) >> 8;
                unsigned int keep = *reg & ~0x1f00;
                *reg = keep | ((bits | 0x10) << 8);
                func_02065418(message->b19cc);
#if defined(jpn)
                func_020665bc((char*)(self + REGION_VALUE(0x50, 0x90)), 0, data_020f07c0, data_020f07c7);
#else
                int a = CallFunc020e0434With02153694_020e51cc(0x1d);
                int b = CallFunc020e0434With02153694_020e51cc(0x1e);
                InitCombatPairState020652d0((char*)(self + REGION_VALUE(0x50, 0x90)), 0, a, b);
#endif
                message->w94c[2] = 0;
                message->choiceEnabled = 1;
                message->choiceMode = 1;
                message->mode = 6;
                ProcessPendingFlag02045688(message);
                DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 5, 0);
                unsigned char* w = GetWord0x0_0200fb8c((int*)GameState::GetInstance());
                if (w != 0) (w + 0x4000)[REGION_VALUE(0x134, 0x354)] = 0xa;
                return;
            } else if (tok == 0xff0f) {
                MessageControlOwner* ent = message->child;
#if defined(jpn)
                {
#else
                if (ent != 0) {
#endif
                    ent->flags = ent->flags | 0x40;
                    SetFieldD20208bf28(message->child, message->pendingActorId, 0);
                    message->b195b |= 1;
                    unsigned char* g = GetGlobal02109418_02094d6c();
                    int idx = GetTableByteOrFF_020965ac((GetTableByteOrFFData*)g, (unsigned char)message->pendingActorId);
                    RegisterSlotA020cf0fc((int)&sa);
                    RegisterSlotB020cf1a8((int)&sb);
                    packed.b.a = sa.f0;
                    packed.b.b = sa.f4;
                    packed.b.c = sa.f8;
                    packed.b.d = sb.f0;
                    packed.b.e = sb.f4;
                    *(unsigned int*)(g + idx * 4 + 0x178) = packed.w;
                    SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x32);
                }
            } else if (tok > REGION_VALUE(0xff39, 0xff34) && tok < REGION_VALUE(0xff4e, 0xff49)) {
                ProcessPendingFlag02045688(message);
                SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, tok - REGION_VALUE(0xff08, 0xff03));
                message->b19c9 = 1;
                return;
            } else if (tok >= REGION_VALUE(0xff4f, 0xff4a) && tok <= REGION_VALUE(0xff51, 0xff4c)) {
                int arg = -1;
                if (tok == REGION_VALUE(0xff50, 0xff4b)) arg = 0xe;
                if (arg >= 0) {
                    DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 0xe, 0);
                }
            } else if (tok == 0xff10) {
                MessageControlOwner* ent = message->child;
                if (ent != 0) ent->value = message->pendingActorId;
            } else if (tok == 0xff11) {
                MessageControlOwner* ent = message->child;
                if (ent != 0) {
                    ent->flags = ent->flags | 0x200;
                    ClearField0xd0AndSetFlag0x1IfByte0xd4Not2_0208be94(message->child);
                    message->b195b |= 1;
                    SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x33);
                }
            } else if (tok == 0xff13) {
                MessageControlOwner* ent = message->child;
                if (ent != 0) {
                    ent->flags = ent->flags | 0x300;
                    ClearField0xd0AndSetFlag0x1IfByte0xd4Not2_0208be94(message->child);
                    message->b195b |= 1;
                    SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x44);
                }
            } else if (tok == 0xff12) {
                if (message->child != 0) {
                    SetFlag0x2IfByte0xd4Not3_0208beb4(message->child);
                }
#if defined(jpn)
            } else if (tok == 0xff37) {
                skipCount = true;
            } else if (tok == 0xff38) {
                skipCount = false;
#endif
            } else if (tok >= REGION_VALUE(0xff52, 0xff4d) && tok <= REGION_VALUE(0xff55, 0xff50)) {
                int v = message->levels[tok - REGION_VALUE(0xff52, 0xff4d)];
                func_0205e944(&data_02108760, ((v * 0x21dd) >> 10) & 0x7f);
            } else if (tok == 0xff0e) {
                message->b19c0 = 1;
                message->b195d = 0x1e;
#if defined(jpn)
            } else if ((unsigned short)(tok + 0xe6) <= 1) {
                n++;
#endif
            }
        }
        message->mode = 5;
        message->tokenIndex = message->tokenIndex + 1;
#if defined(jpn)
        if (!skipCount) n--;
#else
        n--;
#endif
    }
}
