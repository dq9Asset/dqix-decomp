#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern "C" void func_0204e1c8(int flag, void* entry, void* p2, void* p3, int a, int b, int c, int d);

// USA: func_020435a8
ARM void InvokeTableEntryHandler020435a8(int flag, void* p2, void* p3, int idx) {
    if (flag != 0) {
        unsigned char* base = data_02107800.glyphAssets;
        base = base + (idx << 5);
        func_0204e1c8(flag, base, p2, p3, 8, 8, 0xf0, 0xf);
    }
}
