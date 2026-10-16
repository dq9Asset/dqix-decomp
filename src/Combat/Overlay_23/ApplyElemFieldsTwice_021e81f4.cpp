#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/TryApplyElemFields.h"
#include "Resource/CharacterCreationUI.h"

struct ProfileApplyState {
    unsigned char unknown0[0x78];
    CreationWindow window;
    unsigned char unknownAfterWindow[0x5d8 - 0x78 - sizeof(CreationWindow)];
    void* text;
};

struct Container021e8cc0;
void CallAppendStringIfSet_021e8cc0(struct Container021e8cc0* obj);
extern "C" void func_ov023_021e8cdc(void* obj);

// USA: func_ov023_021e81f4
// JPN: func_ov023_021e83a0
ARM void ApplyElemFieldsTwice_021e81f4(void* obj) {
    ProfileApplyState* state = static_cast<ProfileApplyState*>(obj);
#if defined(jpn)
    const int textCapacity = 0x800;
#else
    const int textCapacity = 0x960;
#endif
    memset(state->text, 0, textCapacity);
    CallAppendStringIfSet_021e8cc0(static_cast<Container021e8cc0*>(obj));
    TryApplyElemFields0205d5d0(reinterpret_cast<StructA0205d5d0*>(&state->window), 0xc, reinterpret_cast<int>(state->text),
#if defined(jpn)
                              1
#else
                              0, 1
#endif
    );

    memset(state->text, 0, textCapacity);
    func_ov023_021e8cdc(obj);
    TryApplyElemFields0205d5d0(reinterpret_cast<StructA0205d5d0*>(&state->window), 0xd, reinterpret_cast<int>(state->text),
#if defined(jpn)
                              1
#else
                              0, 1
#endif
    );
}
