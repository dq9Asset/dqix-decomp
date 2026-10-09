#if defined(jpn)
#include <globaldefs.h>

struct FieldE20Holder {
    unsigned char unknown[0xe20];
    unsigned int field;
};

// JPN: func_ov000_02164c88
extern "C" ARM unsigned int func_ov000_02164c88(const FieldE20Holder* self) {
    return self->field;
}

#endif

