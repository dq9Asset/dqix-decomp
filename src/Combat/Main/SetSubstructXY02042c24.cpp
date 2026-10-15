#include <globaldefs.h>

#include "Resource/MessageSystem.h"

// USA: func_02042c24
ARM void SetSubstructXY02042c24(MessageSlotController* holder, int x, int y) {
    if (holder->currentBounds != 0) {
        holder->currentBounds->x = x;
        holder->currentBounds->y = y;
    }
}
