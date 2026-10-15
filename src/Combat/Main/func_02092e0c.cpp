#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/CharacterCreationUI.h"
struct MessageController {
    SafeAllocator allocator;
    Container020e0310 messages;
    char unknown1c[0x10];
    int loadTask;
    short messageKey;
    short messageDelay;
    char unknown34[3];
    unsigned char flags;
    signed char namedPartySlot;
};
struct CombatantInfo02092e0c { int fields[3]; };
int GetField0x3acValue_020100a8(GameState*);
void InitObjFromCombatantId020e4bf4(void*, int);
// USA: func_02092e0c
extern "C" ARM void func_02092e0c(MessageController* messages) {
    if (messages->messageKey >= 0) {
        MessageSystem* display = GetGlobalField0x1c020421a0();
        func_02046380(display);
        GameState* state = GameState::GetInstance();
        GameObject* member = state->GetPartyMemberByIndex(GetField0x3acValue_020100a8(state));
        if (member) SetIndexedName02046574(display, 0, member->baseStats_->unk);
#if defined(jpn)
        member = state->GetPartyMemberByIndex(messages->namedPartySlot);
        if (member) SetIndexedName02046574(display, 1, member->baseStats_->unk);
        func_0204500c(display, GetFieldByKey020e0434(&messages->messages, messages->messageKey), 0);
        display->active = 1;
        if ((messages->flags & 1) && (messages->flags & 2)) {
            display->b19b1 = 0;
            display->w1860 = 12;
            display->w1864 = 16;
            func_02043270(display, display->w1860, 0x90, 0x100, 0x30);
            display->b195b |= 2;
        }
#else
        CombatantInfo02092e0c info;
        InitObjFromCombatantId020e4bf4(&info, messages->namedPartySlot);
        display->actorNames[0] = &info;
        func_0204500c(display, GetFieldByKey020e0434(&messages->messages, messages->messageKey), 0, 0xe3);
        display->active = 1;
        if ((messages->flags & 1) && (messages->flags & 2)) {
            display->b19b1 = 0;
            func_02042b98(display, 2, 0x92, 0xfc, 0x4a);
            display->b195b |= 2;
        }
#endif
        messages->messageKey = -1;
        messages->messageDelay = 0x78;
    }
}
