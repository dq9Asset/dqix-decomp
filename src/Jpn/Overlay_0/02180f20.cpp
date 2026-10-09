#if defined(jpn)
#include <globaldefs.h>

struct Combatant02180f20 {
    char pad0[0xc];
    short field_0xc;
    char pad1[0x10 - 0xe];
    signed char field_0x10[8];
    signed char field_0x18;
    char pad2[0x24 - 0x19];
    unsigned char flags;
    char pad3[0x4c - 0x25];
    int id;
    char pad4[0x488 - 0x50];
};

struct Battle02180f20 {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x958 - 0x70];
    struct Combatant02180f20 combatants[4];
};

// JPN: func_ov000_02180f20
extern "C" ARM void func_ov000_02180f20(struct Battle02180f20* obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            struct Combatant02180f20* e = &obj->combatants[obj->order[i]];
            if (e->id >= 0) {
                e->flags |= 1;
                if (e->field_0xc == 0) {
                    e->field_0x10[e->field_0x18] = 100;
                    e->flags &= ~4;
                    e->flags &= ~1;
                }
            }
        }
        return;
    }
    int i;
    for (i = 0; i < 4; i++) {
        struct Combatant02180f20* e = &obj->combatants[obj->order[i]];
        if (id == e->id) {
            e->flags |= 1;
            return;
        }
    }
}

#endif
