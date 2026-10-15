#include <globaldefs.h>
#include <Resource/MessageSystem.h>
#include <Resource/MessageUpdate.h>

// USA: func_020658ac
ARM void UpdateStatusTimer_020658ac(MessageSystem* base, unsigned int amount) {
    unsigned char c;
    if (base->b19c1 != 0) {
        if (base->b19c0 == 0) {
            base->b19c0 = 1;
            base->b195d = 0x1e;
        }
    }
    if (base->b19c0 == 0) return;
    c = base->b195d;
    if (c <= amount) {
        if (base->b19c1 != 0) {
            base->b195d = c + (0x1e - amount);
        } else {
            base->b195d = 0;
            base->b19c0 = 0;
        }
    } else {
        base->b195d = c - amount;
    }
}
