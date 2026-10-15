#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/TryApplyElemFields.h"

struct Container021e8cc0;
void CallAppendStringIfSet_021e8cc0(struct Container021e8cc0* obj);
extern "C" void func_ov023_021e8cdc(void* obj);

// USA: func_ov023_021e81f4
// JPN: func_ov023_021e83a0
ARM void ApplyElemFieldsTwice_021e81f4(void* obj) {
#if defined(jpn)
    const int textCapacity = 0x800;
#else
    const int textCapacity = 0x960;
#endif
    memset(*(void**)((char*)obj + 0x5d8), 0, textCapacity);
    CallAppendStringIfSet_021e8cc0((struct Container021e8cc0*)obj);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x78), 0xc, *(int*)((char*)obj + 0x5d8),
#if defined(jpn)
                              1
#else
                              0, 1
#endif
    );

    memset(*(void**)((char*)obj + 0x5d8), 0, textCapacity);
    func_ov023_021e8cdc(obj);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x78), 0xd, *(int*)((char*)obj + 0x5d8),
#if defined(jpn)
                              1
#else
                              0, 1
#endif
    );
}
