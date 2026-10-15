#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/ItemNameText.h"



// USA: func_020e46d8
ARM char* AddResultIfField0Set020e46d8(char* a, ItemNameText* b) {
    if (b->first != 0) {
        return a + sprintf(a, b->first);
    }
    return a;
}
