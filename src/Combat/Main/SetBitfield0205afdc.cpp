#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"

#if defined(jpn)
#define func_0205b008 func_0205c3a4
#endif

extern "C" int func_0205b008(LoadTable* a, Struct0205a198* b, unsigned int c, int d, unsigned short e, int f);

// USA: func_0205afdc
ARM void SetBitfield0205afdc(LoadTable* a, Struct0205a198* b, int c) {
    func_0205b008(a, b, 0, 0xc00, 0xa, (unsigned short)(c & 0x3));
}
