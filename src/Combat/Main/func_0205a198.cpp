#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0205a198
void Init0205a198(Struct0205a198 *p) {
    memset(p, 0, 8);
    p->copy = 0;
    p->scaleX = p->scaleY = 0x1000;
    p->position[0] = p->position[1] = 0;
    p->angle = 0;
    p->index = 0;
    p->matrixIndex = 0;
    p->firstObject = 0;
    p->transformed = 0;
    p->doubleSize = 0;
    p->palette = -1;
    p->priority = -1;
}
