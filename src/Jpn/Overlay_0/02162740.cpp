#if defined(jpn)
#include <globaldefs.h>

struct SelectionFlags { unsigned char unknown[0x57e4]; unsigned int flags; };

// JPN: func_ov000_02162740
extern "C" ARM unsigned int func_ov000_02162740(const SelectionFlags* self, unsigned int mask) {
    return self->flags & mask;
}

#endif

