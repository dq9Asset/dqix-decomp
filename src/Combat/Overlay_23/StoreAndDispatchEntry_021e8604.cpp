#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

namespace {
struct ProfileValueState {
    unsigned char unknown0[0x4c];
    Container020e0310 messages;
    unsigned char unknown54[0x5d8 - 0x54];
    char* text;
};
}

void* GetPtrField0x2a04_02010828(GameState* battleStruct);



#if defined(jpn)
extern "C" void func_020474a8(MessageSystem* messages, unsigned char font, const char* format, char* output);
#else
extern "C" void func_02046608(MessageSystem* messages, int unused, const char* text, char* output, int width, int margin, int font);
#endif

struct Combatant021e8604 { char pad[0xf74]; int val; };

// USA: func_ov023_021e8604  (semantic: StoreAndDispatchEntry_021e8604)
// JPN: func_ov023_021e8574
extern "C" ARM void func_ov023_021e8604(void* obj) {
    ProfileValueState* state = static_cast<ProfileValueState*>(obj);
    GameState* battleStruct = GameState::GetInstance();
    Combatant021e8604* combatant = static_cast<Combatant021e8604*>(GetPtrField0x2a04_02010828(battleStruct));
    MessageSystem* field = GetGlobalField0x1c020421a0();
    StoreInArray0x8b0_020465c0(field, 0, combatant->val);
    SetByteAtIndex_020465d8(field, 0, 1);
    SetByteInRange_020465f0(field, 0, 0xa);
    const char* text = GetFieldByKey020e0434(&state->messages, 2);
#if defined(jpn)
    func_020474a8(field, 0xa, text, state->text);
#else
    func_02046608(field, 0xa, text, state->text, 0x100, 0, 0);
#endif
}
