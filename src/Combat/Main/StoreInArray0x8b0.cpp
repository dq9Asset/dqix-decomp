#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_020465c0
ARM void StoreInArray0x8b0_020465c0(MessageSystem* messages, int index, int value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        messages->indexedValues[index] = value;
    }
}
