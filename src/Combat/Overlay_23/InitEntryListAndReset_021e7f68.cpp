#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"

struct ProfileInitState {
    unsigned char unknown0[0x78];
    CreationWindow window;
    unsigned char unknownAfterWindow[0x5d8 - 0x78 - sizeof(CreationWindow)];
    char* text;
    unsigned char unknown5dc[0x5f4 - 0x5dc];
    void* profile;
};

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
extern "C" void func_ov023_021e7cec(void* obj, int a, int b, int c);
extern "C" void func_ov023_021e868c(void* obj);
extern "C" void func_0205d304(void* window, const char* text, int mode, unsigned char border,
                            unsigned char flagBit3, unsigned char fullWidth, void* extraStyle
#if !defined(jpn)
                            , unsigned char font
#endif
);

// USA: func_ov023_021e7f68
// JPN: func_ov023_021e8144
ARM void InitEntryListAndReset_021e7f68(void* obj) {
    ProfileInitState* state = static_cast<ProfileInitState*>(obj);
    ResetEntryList0205d6a0(reinterpret_cast<Entry_0205d6a0*>(&state->window), 1);
    func_ov023_021e7cec(obj, 0xb, 3, 5);
#if defined(jpn)
    memset(state->text, 0, 0x800);
#else
    memset(state->text, 0, 0x960);
#endif
    if (state->profile != NULL) {
        func_ov023_021e868c(obj);
    }
    func_0205d304(&state->window, state->text, 0, 0, 0, 1, 0
#if !defined(jpn)
                   , 0
#endif
    );
}
