#include <globaldefs.h>
#include "Resource/MessageSystem.h"

#if defined(jpn)
#else
#endif

// USA: func_02065920
ARM void ResetOrConsumeCounter02065920(MessageSystem* obj, unsigned int amount) {
    if (
#if defined(jpn)
        obj->flags17ff.flag2 != 0
#else
        obj->b19d0 != 0
#endif
        || obj->mode != 4) return;
    obj->b912 = 0;
    if (amount < obj->advanceCountdown) {
        obj->advanceCountdown -= amount;
        return;
    }
    obj->advanceCountdown = 0;
    obj->b19ae = 0;
    obj->b19af = 0;
    obj->b19cd = 1;
    obj->stream40 = 0;
    obj->stream44 = 0;
    func_0206b104(obj);
#if defined(jpn)
    func_0206cba0(obj);
    obj->mode = 5;
#else
    obj->mode = 5;
    func_0206b224(obj);
#endif
}
