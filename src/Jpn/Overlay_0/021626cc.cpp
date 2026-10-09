#if defined(jpn)
#include <globaldefs.h>

struct Entry40 { unsigned char bytes[0x28]; };
struct EntryOwner { unsigned char unknown0[0x821c]; Entry40 entries[1]; };
struct EntrySelection {
    unsigned char unknown0[0x218];
    EntryOwner* owner;
    unsigned char unknown21c[0x57c8 - 0x21c];
    int index;
};

// JPN: func_ov000_021626cc
extern "C" ARM Entry40* func_ov000_021626cc(EntrySelection* self) {
    int index = self->index;
    if (index == 0) return NULL;
    EntryOwner* owner = self->owner;
    return owner ? &owner->entries[index - 1] : NULL;
}

#endif

