#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/ItemNameText.h"
// USA: func_020e4f18
extern "C" ARM void func_020e4f18(ItemNameText* src, ItemNameText* dest, int flags) {
    if (!src || !dest) return;
    if (flags & 1) {
        char* text = dest->second;
        sprintf(dest->first, src->first);
        sprintf(text, src->second);
    }
    if (flags & 2) {
        dest->bits.field0 = src->bits.field0;
        dest->bits.field6 = src->bits.field6;
        dest->bits.field12 = src->bits.field12;
        dest->bits.field18 = src->bits.field18;
    }
    dest->bits.field24 = src->bits.field24;
    dest->bits.field26 = src->bits.field26;
    dest->bits.field27 = src->bits.field27;
    dest->bits.field28 = src->bits.field28;
    dest->bits.field31 = src->bits.field31;
}
