#include <globaldefs.h>
#include "Resource/MessageFrame.h"

// USA: func_020e29a8
ARM void ClampFieldTo2At0x16(EntryManager020e2490* manager, int v) {
    if (v >= 3) {
        v = 2;
    }
    manager->byte16 = (unsigned char)v;
}
