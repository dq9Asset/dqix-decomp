#if defined(jpn)
#include <globaldefs.h>

struct Field218Holder {
    unsigned char unknown0[0x218];
    unsigned int unknown218;
};

// JPN: func_ov000_02162660
extern "C" ARM unsigned int func_ov000_02162660(const Field218Holder* self) {
    return self->unknown218;
}

#endif

