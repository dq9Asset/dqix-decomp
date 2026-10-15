#include <globaldefs.h>
#include "Resource/ItemNameText.h"

const char* CallFunc020e0434With021536ac_020e51e4(int value);


// USA: func_020e4810
ARM char* ResolveField8Entry6BitPlus200(char* arg0, ItemNameText* p) {
    char* result = arg0;
    if (p->second != 0) {
        const char* entry = CallFunc020e0434With021536ac_020e51e4((short)(p->bits.field18 + 0xc8));
        result = func_020e462c(arg0, entry, p->second, p);
    }
    return result;
}
