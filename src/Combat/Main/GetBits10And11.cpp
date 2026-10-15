#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"

// USA: func_0205b174
ARM int GetBits10And11_0205b174(int unused, struct Struct0205a198* obj) {
    if (obj == 0) {
        return 0;
    }
    return ((unsigned int)obj->cells->y >> 10) & 3;
}
