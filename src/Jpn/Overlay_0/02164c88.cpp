#if defined(jpn)
#include <globaldefs.h>

struct FieldE20Holder {
    unsigned char unknown0[0xe20];
    unsigned int unknownE20;
};

// JPN: func_ov000_02164c88
extern "C" ARM unsigned int func_ov000_02164c88(const FieldE20Holder* self) {
    return self->unknownE20;
}

#endif

