#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/TryApplyElemFields.h"
#include "Resource/CharacterCreationUI.h"

namespace {
struct ProfileResetLoopState {
    unsigned char unknown0[0x78];
    CreationWindow window;
    unsigned char unknownAfterWindow[0x5d8 - 0x78 - sizeof(CreationWindow)];
    char* text;
};
}

class PMFObj021e7eb0 { public: virtual void Dummy021e7eb0(); };
typedef void (PMFObj021e7eb0::*MemFn021e7eb0)();
struct DispatchTable021e7eb0 { MemFn021e7eb0 fns[3]; };
#if defined(jpn)
#define data_ov023_021fd7e4 data_ov023_021fca68
#endif
extern const DispatchTable021e7eb0 data_ov023_021fd7e4;

extern "C" void func_02046380(void*);
int GetGlobalField0x1c020421a0(void);

// USA: func_ov023_021e7eb0
// JPN: func_ov023_021e8094
ARM void ResetAndApplyLoop_021e7eb0(PMFObj021e7eb0 *obj) {
	ProfileResetLoopState* state = reinterpret_cast<ProfileResetLoopState*>(obj);
	DispatchTable021e7eb0 table = data_ov023_021fd7e4;
	int g = GetGlobalField0x1c020421a0();
	for (unsigned char i = 0; i < 3; i++) {
		func_02046380((void*)g);
#if defined(jpn)
		memset(state->text, 0, 0x800);
#else
		memset(state->text, 0, 0x960);
#endif
		(obj->*table.fns[i])();
		TryApplyElemFields0205d5d0(reinterpret_cast<StructA0205d5d0*>(&state->window), i, reinterpret_cast<int>(state->text), 1
#if !defined(jpn)
			, 0
#endif
		);
	}
}

#if defined(jpn)
#undef data_ov023_021fd7e4
#endif
