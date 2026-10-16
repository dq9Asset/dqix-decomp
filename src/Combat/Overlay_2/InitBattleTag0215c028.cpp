#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { WindowOffset = 0xe20, TextOffset = 0x1a98, TextCapacity = 0x800, LayoutPreset = 43 };
#else
enum { WindowOffset = 0xec8, TextOffset = 0x1bd0, TextCapacity = 0x960, LayoutPreset = 40 };
#endif

namespace {
struct BattleTagLineState {
    unsigned char unknown0[WindowOffset];
    CreationWindow window;
    unsigned char unknownAfterWindow[TextOffset - WindowOffset - sizeof(CreationWindow)];
    char* text;
};
}

extern "C" void func_ov002_0215be00(void*, int, short, short);
int GetGlobalField0x1c020421a0();
extern "C" void func_0205d0e0(void*, int);
struct Struct_0205def8;
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
#if defined(jpn)
extern const char data_ov002_0216d91f[];
extern "C" void func_020474a8(void*, unsigned char, const char*, char*);
extern "C" int func_0204234c(char*, int);
#else
extern const char data_ov002_0216d26c[];
extern "C" void func_02046608(void*, int, int, int, int, int, int);
int AppendLineTag02041cc0(char*, int);
#endif
extern "C" void func_0205d304(void*, const char*, int, unsigned char, unsigned char, unsigned char, void*
#if !defined(jpn)
                            , unsigned char
#endif
);

// USA: func_ov002_0215c028
// JPN: func_ov002_0215d12c
ARM void InitBattleTag0215c028(char* base) {
    BattleTagLineState* state = reinterpret_cast<BattleTagLineState*>(base);
    func_ov002_0215be00(state, LayoutPreset, 0x15, 0x13);
    void* messages = reinterpret_cast<void*>(GetGlobalField0x1c020421a0());
    memset(state->text, 0, TextCapacity);
#if defined(jpn)
    func_020474a8(messages, 8, data_ov002_0216d91f, state->text);
    func_0204234c(state->text, 0x11);
#else
    func_02046608(messages, 8, reinterpret_cast<int>(data_ov002_0216d26c), reinterpret_cast<int>(state->text), 0x100, 0, 0);
    AppendLineTag02041cc0(state->text, 0x11);
#endif
    func_0205d304(&state->window, state->text, 0, 0, 0, 1, 0
#if !defined(jpn)
                 , 0
#endif
    );
    func_0205d0e0(&state->window, 4);
    SetElementFlag0x20ByKey0205def8(reinterpret_cast<Struct_0205def8*>(&state->window), 0, LayoutPreset);
}
