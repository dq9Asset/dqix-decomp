#if defined(jpn)
#include <globaldefs.h>

struct EntrySelection {
    unsigned char unknown[0x57c8];
    int index;
};

// JPN: func_ov000_02162708
extern "C" ARM int func_ov000_02162708(const EntrySelection* self) {
    return self->index;
}

#endif

