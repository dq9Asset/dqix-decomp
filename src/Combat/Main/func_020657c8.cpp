#include <globaldefs.h>
#include <Resource/MessageSystem.h>
#include <Resource/MessageUpdate.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

// USA: func_020657c8
extern "C" ARM int func_020657c8(MessageSystem* obj, int step) {
    unsigned char flags = obj->b195b;
    int ret = 0;
    if (flags & 4) {
        if (obj->mode == 0) {
            if (flags & 8) {
                obj->w9b0 = obj->w9b0 + (IS_JPN ? 1 : step) * 0x8444;
                if (obj->w9b0 >= 0x1f0000) {
                    obj->w9b0 = 0x1f0000;
                    obj->fadeHoldElapsed = 0;
                    obj->b195b &= ~8;
                    obj->b195b |= 0x10;
                }
            } else if (flags & 0x10) {
                obj->fadeHoldElapsed = obj->fadeHoldElapsed + step;
                if (obj->fadeHoldDuration <= obj->fadeHoldElapsed) {
                    obj->fadeHoldElapsed = obj->fadeHoldDuration;
                    obj->b195b &= ~0x10;
                    obj->b195b |= 0x20;
                }
            } else if (flags & 0x20) {
                #if defined(jpn)
                step = obj->w9b0 - 0x44;
                step -= 0x8400;
                obj->w9b0 = step;
#else
                obj->w9b0 = obj->w9b0 - step * 0x8444;
#endif
                if (obj->w9b0 <= 0) {
                    obj->w9b0 = 0;
                    obj->b195b = obj->b195b & ~0x20;
                }
            }
            ret = 1;
        }
    }
    return ret;
}
