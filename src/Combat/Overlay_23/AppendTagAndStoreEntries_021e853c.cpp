#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

namespace {
struct ProfileAppendState {
    unsigned char unknown0[0x4c];
    Container020e0310 messages;
    unsigned char unknown54[0x5d8 - 0x54];
    char* text;
};
}

#if defined(jpn)
extern "C" int func_0204234c(char* dst, int a1);
#define AppendLineTag02041cc0 func_0204234c
#else
int AppendLineTag02041cc0(char* dst, int a1);
#endif



#if defined(jpn)
extern "C" void func_020474a8(MessageSystem* messages, unsigned char font, const char* format, char* output);
#else
extern "C" void func_02046608(MessageSystem* messages, int unused, const char* text, char* output, int width, int margin, int font);
#endif

struct Combatant021e853c { char pad[0xf68]; int f68; int f6c; };

// USA: func_ov023_021e853c  (semantic: AppendTagAndStoreEntries_021e853c)
// JPN: func_ov023_021e84c0
extern "C" ARM void func_ov023_021e853c(void* obj) {
    ProfileAppendState* state = static_cast<ProfileAppendState*>(obj);
    Combatant021e853c* combatant = static_cast<Combatant021e853c*>(GetPtrField0x2a04_02010828(GameState::GetInstance()));
    MessageSystem* field = GetGlobalField0x1c020421a0();
    AppendLineTag02041cc0(state->text, 0x18);
    int arr[2] = { combatant->f6c, combatant->f68 };
    for (int i = 0; i < 2; i++) {
        StoreInArray0x8b0_020465c0(field, i, arr[i]);
        SetByteAtIndex_020465d8(field, i, 1);
        SetByteInRange_020465f0(field, i, 0xa);
    }
    const char* text = GetFieldByKey020e0434(&state->messages, 1);
#if defined(jpn)
    func_020474a8(field, 0xa, text, state->text);
#else
    func_02046608(field, 0xa, text, state->text, 0x100, 0, 0);
#endif
}

#if defined(jpn)
#undef AppendLineTag02041cc0
#endif
