#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/TryApplyElemFields.h"

extern "C" void func_ov023_021e868c(void*);

// USA: func_ov023_021e7fe4
// JPN: func_ov023_021e81bc
ARM void ResetAndApply_021e7fe4(void* obj) {
#if defined(jpn)
    const int textCapacity = 0x800;
#else
    const int textCapacity = 0x960;
#endif
    memset(*(void**)((char*)obj + 0x5d8), 0, textCapacity);
    func_ov023_021e868c(obj);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x78), 0xb, *(int*)((char*)obj + 0x5d8), 1
#if !defined(jpn)
                              , 0
#endif
    );
}
