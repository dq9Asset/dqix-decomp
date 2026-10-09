#if defined(jpn)
#include <globaldefs.h>

struct Combatant0218108c {
    char pad0[0x24];
    unsigned char flags;
    char pad1[0x4c - 0x25];
    int id;
    char pad2[0x488 - 0x50];
};

struct Battle0218108c {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x958 - 0x70];
    struct Combatant0218108c combatants[4];
};

// JPN: func_ov000_0218108c
extern "C" ARM bool func_ov000_0218108c(struct Battle0218108c* obj, int id) {
    bool result = false;
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            struct Combatant0218108c* e = &obj->combatants[obj->order[i]];
            if (e->id >= 0) {
                result |= (e->flags & 1) != 0;
            }
        }
    } else {
        int i;
        for (i = 0; i < 4; i++) {
            struct Combatant0218108c* e = &obj->combatants[obj->order[i]];
            if (id == e->id) {
                result = (e->flags & 1) != 0;
                break;
            }
        }
    }
    return result;
}

#endif
