#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/ItemNameText.h"



// USA: func_020e4798
ARM char* AddResultIfField4Set020e4798(char* a, ItemNameText* b) {
    if (b->second != 0) {
        return a + sprintf(a, b->second);
    }
    return a;
}
