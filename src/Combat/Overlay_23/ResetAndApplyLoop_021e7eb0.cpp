#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/TryApplyElemFields.h"

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
	DispatchTable021e7eb0 table = data_ov023_021fd7e4;
	int g = GetGlobalField0x1c020421a0();
	for (unsigned char i = 0; i < 3; i++) {
		func_02046380((void*)g);
#if defined(jpn)
		memset(*(void**)((char*)obj + 0x5d8), 0, 0x800);
#else
		memset(*(void**)((char*)obj + 0x5d8), 0, 0x960);
#endif
		(obj->*table.fns[i])();
		TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x78), i, *(int*)((char*)obj + 0x5d8), 1
#if !defined(jpn)
			, 0
#endif
		);
	}
}

#if defined(jpn)
#undef data_ov023_021fd7e4
#endif
