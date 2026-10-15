#include <globaldefs.h>
#include "Resource/MessageFrame.h"

// USA: func_020e25e8
ARM void ResetSelectionState020e25e8(EntryManager020e2490* manager) {
    ClearFlag0x1SetFlag0x2_020e1cb8(manager->frame);
    ResetBytes020e25cc(manager);
}
