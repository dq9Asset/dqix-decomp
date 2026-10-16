#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/TryApplyElemFields.h"
#include "Resource/CharacterCreationUI.h"

struct ProfileResetState {
    unsigned char unknown0[0x78];
    CreationWindow window;
    unsigned char unknownAfterWindow[0x5d8 - 0x78 - sizeof(CreationWindow)];
    void* text;
};

extern "C" void func_ov023_021e868c(void*);

// USA: func_ov023_021e7fe4
// JPN: func_ov023_021e81bc
ARM void ResetAndApply_021e7fe4(void* obj) {
    ProfileResetState* state = static_cast<ProfileResetState*>(obj);
#if defined(jpn)
    const int textCapacity = 0x800;
#else
    const int textCapacity = 0x960;
#endif
    memset(state->text, 0, textCapacity);
    func_ov023_021e868c(obj);
    TryApplyElemFields0205d5d0(reinterpret_cast<StructA0205d5d0*>(&state->window), 0xb, reinterpret_cast<int>(state->text), 1
#if !defined(jpn)
                              , 0
#endif
    );
}
