#if defined(jpn)
#include <globaldefs.h>
#include <Graphics/Vector.h>

struct PositionedObject0217093c {
    int field_0x0;
    Vector3fix position;
};

// JPN: func_ov000_0217093c
extern "C" ARM fix32_t func_ov000_0217093c(PositionedObject0217093c* obj, fix32_t* outDistance) {
    Vector3fix pos = obj->position;
    pos.y = 0;
    fix32_t dist = Vector3fix_Length(&pos);
    *outDistance = dist;
    if (dist < 0x8000) {
        return 0;
    }
    if (dist > 0x11000) {
        dist = 0x11000;
    }
    fix32_t t = fix32_Divide(dist - 0x8000, 0x9000);
    fix32_t scale = 0x1000 - fix32cos(FIX32_MULTIPLY(t, 0x1922));
    if (scale < 0) {
        scale = 0;
    }
    return FIX32_MULTIPLY(scale, 0x5000);
}

#endif
