#if defined(jpn)
#include <globaldefs.h>

struct SelectionFlags { unsigned char unknown[0x57e4]; unsigned int flags; };

// JPN: func_ov000_02162714
extern "C" ARM void func_ov000_02162714(SelectionFlags* self, unsigned int mask) {
    self->flags |= mask;
}

#endif

