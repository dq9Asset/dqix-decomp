#include <globaldefs.h>
#include "Resource/MessageFrame.h"

// USA: func_020e25cc
ARM void ResetBytes020e25cc(EntryManager020e2490* manager) {
    manager->byte14 = manager->byte16;
    manager->byte15 = -1;
    manager->byte17 = 0;
}
