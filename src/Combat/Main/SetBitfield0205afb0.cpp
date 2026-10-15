#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"

#if defined(jpn)
#define func_0205b008 func_0205c3a4
#endif

extern "C" int func_0205b008(LoadTable* a, Struct0205a198* b, unsigned int c, int d, unsigned short e, int f);

// USA: func_0205afb0
ARM void SetBitfield0205afb0(LoadTable* a, Struct0205a198* b, int c) {
    func_0205b008(a, b, 2, 0xf000, 0xc, (unsigned short)(c & 0xf));
}
