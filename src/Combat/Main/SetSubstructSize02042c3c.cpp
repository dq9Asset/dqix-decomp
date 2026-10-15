#include <globaldefs.h>

#include "Resource/MessageSystem.h"

// USA: func_02042c3c
ARM void SetSubstructSize02042c3c(MessageSlotController* holder, int width, int height) {
    if (holder->currentBounds != 0) {
        holder->currentBounds->width = width;
        holder->currentBounds->height = height;
    }
}
