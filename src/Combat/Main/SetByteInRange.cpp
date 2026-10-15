#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_020465f0
ARM void SetByteInRange_020465f0(MessageSystem* messages, int index, unsigned char value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        messages->indexedNumberWidths[index] = value;
    }
}
