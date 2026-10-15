#include <globaldefs.h>
#include "Resource/MessageSystem.h"


// USA: func_020457e8
ARM void PushToRingBuffer020457e8(MessageSystem* rb, int value) {
    rb->textDelayCounters[rb->b19ad] = value;
    rb->b19ad = rb->b19ad + 1;
    rb->b19ad = rb->b19ad % 4;
}
