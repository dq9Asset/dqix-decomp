#include <globaldefs.h>
#include "Resource/ItemNameText.h"

const char* CallFunc020e0434With021536ac_020e51e4(int value);


// USA: func_020e4750
ARM char* UpdateObjectFromStateFlags(char* obj, ItemNameText* state) {
    if (state->first != NULL) {
        const char* v = CallFunc020e0434With021536ac_020e51e4(state->bits.field12);
        obj = func_020e462c(obj, v, state->first, 0);
    }
    return obj;
}
