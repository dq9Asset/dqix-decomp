#include <globaldefs.h>
#include "Resource/MessageFrame.h"
#include "Graphics/VRAMStaging.h"

// USA: func_020e2478
ARM void InvokeSubHandlerIfPresent_020e2478(MessageFrame* frame) {
    unsigned char* buffer = frame->stagingBuffer;
    if (buffer == NULL) return;
    FreeVRAMStagingMemory(buffer);
}
