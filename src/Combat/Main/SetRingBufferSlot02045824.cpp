#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

#if !defined(jpn)
// USA: func_02045824
ARM void SetRingBufferSlot02045824(MessageSystem* messages, int value, int index) {
    int i;
    if (index == -1) {
        for (i = 0; i < 4; i++) {
            messages->textDelayCounters[i] = value;
        }
    } else {
        messages->textDelayCounters[index] = value;
    }
}
#endif
