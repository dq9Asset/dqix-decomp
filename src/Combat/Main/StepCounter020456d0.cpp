#include <globaldefs.h>
#include <Resource/MessageSystem.h>
#include <Resource/MessageUpdate.h>

// USA: func_020456d0
ARM void StepCounter020456d0(MessageSystem* b) {
    if (b->mode == 1 || b->mode == 3 || b->mode == 2) {
        if (b->b19ca == 0) return;
        b->b19ae = b->b19ae + 1;
        b->b19ae = b->b19ae & 0x1f;
        b->b19af = (b->b19ae > 0xf) ? 1 : 0;
    } else {
        b->b19ae = 0;
        b->b19af = 0;
    }
}
