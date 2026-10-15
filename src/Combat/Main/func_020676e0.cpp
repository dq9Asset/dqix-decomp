#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#include "GameState/GameState.h"

struct IntField0x23c_020a27c4 {
    char pad0[0x23c];
    int value;
    char pad240[4];
    unsigned char flags;
};
struct GameModeView { char pad0[(IS_JPN ? 0x5a68 : 0x5cc8)]; unsigned char mode; };
typedef void (MessageSystem::*ControlHandler)(int);
#if defined(jpn)
extern ControlHandler data_020f079c[3];
#define data_020f08b8 data_020f079c
#else
extern ControlHandler data_020f08b8[2];
#endif
extern unsigned short data_02114e30[];
void SetupAndDispatch0205c904(unsigned char*, int);
int CheckGlobalObjState2AndInit0205cde8(unsigned char*);
void InitGlobalObjAndSelfPointer0205cd94(unsigned char*);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short*, int);
int GetFieldIfFlag4_020100f8(char*);
int GetWord0x0_0200fb8c(int*);
int GetIntAt0x23c(IntField0x23c_020a27c4*);
int IsFieldNotPositive_021a4e70(unsigned char*);
int GetScaledSumIfActive0205cecc(void*);
int CallFunc0205c570AtField0x1c_0205cb64(void*);

// USA: func_020676e0
extern "C" ARM void func_020676e0(MessageSystem* state, int elapsed) {
    if (state->mode != 6) return;
    if (!state->choiceEnabled) return;
#if defined(jpn)
    unsigned char* controls = state->pad50;
#else
    unsigned char* controls = state->pad90;
#endif
    SetupAndDispatch0205c904(controls, elapsed);
    if (!CheckGlobalObjState2AndInit0205cde8(controls)) {
        InitGlobalObjAndSelfPointer0205cd94(controls);
        return;
    }
    int enabled = 1;
    bool pressed = TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x401) != 0;
    bool cancelled = TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 2) != 0;
    GameState* game;
    unsigned char* resource;
    int mode = state->choiceMode;
    game = GameState::GetInstance();
    IntField0x23c_020a27c4* field = (IntField0x23c_020a27c4*)GetFieldIfFlag4_020100f8((char*)game);
    resource = (unsigned char*)GetWord0x0_0200fb8c((int*)game);
#if defined(jpn)
    if (mode != 1 && state->flags17ff.flag4) {
#else
    if (mode != 1 && state->b19d2) {
#endif
        if (field) {
            if ((field->flags & 2) || !GetIntAt0x23c(field))
                pressed |= TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x200);
        } else {
            pressed |= TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x200);
        }
    }
    int specialMode = 0;
    if (((GameModeView*)game)->mode == 2) specialMode = 1;
    if (!specialMode && resource && !IsFieldNotPositive_021a4e70(resource)) {
        pressed = 0;
        cancelled = 0;
        enabled = 0;
    }
    if (!specialMode && state->child && (state->child->flags & 0x20)) {
        pressed = 0;
        cancelled = 0;
        enabled = 0;
    }
    int value = -1;
    if (enabled) value = GetScaledSumIfActive0205cecc(controls);
    if (pressed) value = CallFunc0205c570AtField0x1c_0205cb64(controls);
    else if (cancelled) value = -2;
    state->w94c[2] = value;
    (state->*data_020f08b8[mode])(value);
}
