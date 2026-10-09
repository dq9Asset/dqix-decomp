#if defined(jpn)
#include <globaldefs.h>

struct Field218Holder {
    unsigned char unknown[0x218];
    unsigned int field;
};

// JPN: func_ov000_02162660
extern "C" ARM unsigned int func_ov000_02162660(const Field218Holder* self) {
    return self->field;
}

#endif

