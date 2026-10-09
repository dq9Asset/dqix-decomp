#if defined(jpn)
#include <globaldefs.h>

struct TaskEntry02169db8 {
    signed char id;
    unsigned char flags;
    short taskA;
    short taskB;

    signed char GetId() const { return id; }
};

struct TaskEntryOwner02169db8 {
    char pad[0x79c6];
    TaskEntry02169db8 entries[4];
    unsigned char count;
};

// JPN: func_ov000_02169db8
extern "C" ARM void func_ov000_02169db8(TaskEntryOwner02169db8* owner, int id) {
    int removed = 0;
    int j = 0;
    for (int i = 0; i < owner->count; i++) {
        if (id == owner->entries[i].GetId()) {
            removed = 1;
        } else {
            owner->entries[j].id = owner->entries[i].id;
            owner->entries[j].flags = owner->entries[i].flags;
            owner->entries[j].taskA = owner->entries[i].taskA;
            owner->entries[j].taskB = owner->entries[i].taskB;
            j++;
        }
    }
    if (removed) {
        owner->count--;
    }
}

#endif
