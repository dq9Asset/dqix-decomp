#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"

#if defined(jpn)
#define func_0205b008 func_0205c3a4
#endif



// USA: func_0205b008
extern "C" ARM int func_0205b008(LoadTable* a, Struct0205a198* b, unsigned int c, int d,
                                 unsigned short e, int f) {
    unsigned short i;
    unsigned short shift;
    Cell0205a658* p;
    unsigned int v;

    if (b == 0) {
        return 1;
    }
    if (c >= 3) {
        return 1;
    }
    if (b == 0) {
        return 1;
    }
    shift = e;
    for (i = 0; i < b->count; i++) {
        p = b->cells + i;
        switch (c) {
        case 0:
            v = p->y;
            break;
        case 1:
            v = p->x;
            break;
        case 2:
            v = p->attributes;
            break;
        }
        v = (unsigned short)(v & (unsigned int)~d) | ((((unsigned int)(f << shift)) << 16) >> 16);
        switch (c) {
        case 0:
            p->y = v;
            break;
        case 1:
            p->x = v;
            break;
        case 2:
            p->attributes = v;
            break;
        }
    }
    return 0;
}
