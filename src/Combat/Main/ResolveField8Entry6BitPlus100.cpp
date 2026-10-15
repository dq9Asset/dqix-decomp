#include <globaldefs.h>
#include "Resource/ItemNameText.h"

const char* CallFunc020e0434With021536ac_020e51e4(int value);


// USA: func_020e46fc
ARM char* ResolveField8Entry6BitPlus100(char* arg0, ItemNameText* p) {
    char* result = arg0;
    if (p->first != 0) {
        const char* entry = CallFunc020e0434With021536ac_020e51e4((short)(p->bits.field0 + 0x64));
        result = func_020e462c(arg0, entry, p->first, 0);
    }
    return result;
}
