#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_020465d8
ARM void SetByteAtIndex_020465d8(MessageSystem* messages, int index, unsigned char value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        messages->indexedNumberPaddingModes[index] = value;
    }
}
