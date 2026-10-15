#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"



// USA: func_0205a3d0
ARM struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key) {
    struct Elem0205a3d0* result;
    unsigned short i;
    if (c->entries == NULL) {
        return NULL;
    }
    if (c->count == 0) {
        return NULL;
    }
    result = NULL;
    for (i = 0; i < c->count; i++) {
        if (key == c->entries[i].key) {
            result = &c->entries[i];
            break;
        }
    }
    return result;
}
