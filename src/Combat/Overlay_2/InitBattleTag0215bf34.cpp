#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { WindowOffset = 0xe20, TextOffset = 0x1a98, TextCapacity = 0x800, LayoutPreset = 44 };
#else
enum { WindowOffset = 0xec8, TextOffset = 0x1bd0, TextCapacity = 0x960, LayoutPreset = 41 };
#endif

namespace {
struct BattleTagInitState {
    unsigned char unknown0[WindowOffset];
    CreationWindow window;
    unsigned char unknownAfterWindow[TextOffset - WindowOffset - sizeof(CreationWindow)];
    char* text;
};

struct PartyResourceCounter {
    unsigned char unknown0[0xf6c];
    int value;
};
}

struct StoreStruct;
int GetGlobalField0x1c020421a0();
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
int CallFunc020e0434With02153694_020e51cc(int);
extern "C" void func_ov002_0215be00(void*, int, short, short);
extern "C" void func_02046380(void*);
extern "C" void func_0205d0e0(void*, int);
#if defined(jpn)
extern const char data_ov002_0216d908[];
extern "C" void func_020474a8(void*, unsigned char, const char*, char*);
#else
extern "C" void func_02046608(void*, int, int, int, int, int, int);
#endif
extern "C" void func_0205d304(void*, const char*, int, unsigned char, unsigned char, unsigned char, void*
#if !defined(jpn)
                            , unsigned char
#endif
);

// USA: func_ov002_0215bf34
// JPN: func_ov002_0215d060
ARM void InitBattleTag0215bf34(char* base) {
    BattleTagInitState* state = reinterpret_cast<BattleTagInitState*>(base);
    func_ov002_0215be00(state, LayoutPreset, 0x15, 0x15);

    PartyResourceCounter* party = static_cast<PartyResourceCounter*>(GetPtrField0x2a04_02010828(GameState::GetInstance()));
    StoreStruct* messages = reinterpret_cast<StoreStruct*>(GetGlobalField0x1c020421a0());
    func_02046380(messages);
    StoreInArray0x8b0_020465c0(messages, 0, party->value);
    unsigned char* messageBytes = reinterpret_cast<unsigned char*>(messages);
    SetByteAtIndex_020465d8(messageBytes, 0, 1);
    SetByteInRange_020465f0(messageBytes, 0, 7);
    memset(state->text, 0, TextCapacity);
#if defined(jpn)
    func_020474a8(messages, 8, data_ov002_0216d908, state->text);
#else
    int format = CallFunc020e0434With02153694_020e51cc(0x3f1);
    func_02046608(messages, 8, format, reinterpret_cast<int>(state->text), 0x100, 0, 0);
#endif
    func_0205d304(&state->window, state->text, 0, 0, 0,
#if defined(jpn)
                 1, 0);
#else
                 0, 0, 0);
#endif
    func_0205d0e0(&state->window, 4);
}
