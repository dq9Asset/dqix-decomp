#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"
#if defined(jpn)
#define func_0205b008 func_0205c3a4
#endif

extern "C" int func_0205b008(LoadTable* a, Struct0205a198* b, unsigned int c, int d, unsigned short e, int f);

// USA: func_0205af38
ARM void SetBitfieldStoreBytes0205af38(LoadTable* a, Struct0205a198* obj, int c, int d) {
    if (obj != 0) {
        if (func_0205b008(a, obj, 0, 0x300, 8, c | (((unsigned int)d << 17) >> 16)) == 0) {
            obj->transformed = (char)c;
            obj->doubleSize = (char)d;
        }
    }
}
