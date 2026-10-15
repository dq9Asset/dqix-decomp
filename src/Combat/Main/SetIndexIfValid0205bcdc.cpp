#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern "C" void func_0205bb04(Struct_0205ba2c*, int);


// USA: func_0205bcdc
ARM void SetIndexIfValid0205bcdc(struct Struct_0205bbcc* s, int index) {
    if (index < 0) return;
    if (s->base.count <= index) return;
    s->selectedIndex = -1;
    func_0205bb04(&s->base, index);
}
