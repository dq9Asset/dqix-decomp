#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"

struct Container0205a3d0;
struct Elem0205a3d0;
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);

// USA: func_020e27ec
ARM void SetEntryPosition_020e27ec(struct Container0205a3d0* c, int key, short a, short b) {
    struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(c, key);
    if (e != NULL) {
        e->x = a;
        e->y = b;
    }
}
