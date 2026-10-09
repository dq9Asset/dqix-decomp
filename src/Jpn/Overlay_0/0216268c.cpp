#if defined(jpn)
#include <globaldefs.h>

struct Entry40 { unsigned char bytes[0x28]; };
struct EntryOwner { unsigned char unknown[0x821c]; Entry40 entries[1]; };
struct EntrySelection {
    unsigned char unknown0[0x218];
    EntryOwner* owner;
    unsigned char unknown1[0x57c8 - 0x21c];
    int index;
    unsigned char unknown2[0x78fc - 0x57cc];
    Entry40* overrideEntry;
};

// JPN: func_ov000_0216268c
extern "C" ARM Entry40* func_ov000_0216268c(EntrySelection* self) {
    EntryOwner* owner = self->owner;
    if (owner == NULL) return NULL;
    Entry40* entry = self->overrideEntry;
    if (entry == NULL) entry = &owner->entries[self->index];
    return entry;
}

#endif

