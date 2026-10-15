#include <globaldefs.h>
#include "std_library_functions.h"

#include "Resource/ItemNameText.h"

// USA: func_020e4b34  (semantic: PackFields_020e4b34)
extern "C" ARM void func_020e4b34(ItemNameText* dst, char* a1, char* a2, unsigned int a3,
        unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3,
        unsigned char b4, unsigned char b5, unsigned char b6, unsigned char b7) {
    memset(dst, 0, 0xc);
    dst->first = a1;
    dst->second = a2;
    dst->bits.field0 = a3;
    dst->bits.field6 = b0;
    dst->bits.field12 = b1;
    dst->bits.field18 = b2;
    dst->bits.field24 = b3;
    dst->bits.field26 = b4;
    dst->bits.field27 = b5;
    dst->bits.field28 = b6;
    dst->bits.field30 = b7;
}
