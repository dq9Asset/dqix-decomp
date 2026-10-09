#if defined(jpn)
#include <globaldefs.h>

struct Name021607bc {
    char text[0x16];
};

struct Element021607bc {
    char pad0[0x6c];
    Name021607bc name;
    unsigned char field82;
    unsigned char field83;
};

struct Container02070e60 {
    char pad0[4];
};

extern "C" Element021607bc* func_0207203c(struct Container02070e60* container, int key);

struct Unit021607bc {
    char pad0[0x3e];
    Name021607bc name;
    unsigned char field54;
    unsigned char field55;
    char pad56[0xa4 - 0x56];
};

struct Table021607bc {
    char pad0[0x400];
    Container02070e60 container;
};

struct BattleData021607bc {
    char pad0[0x158];
    Unit021607bc units[1];
    char pad1fc[0x284 - 0x1fc];
    Table021607bc table;
};

struct Group021607bc {
    unsigned short key;
    unsigned char members[8];
    unsigned char memberCount : 4;
    unsigned char matched : 4;
    char padb[0x18 - 0xb];
};

struct Battle021607bc {
    char pad0[0x81b1];
    unsigned char counter : 4;
    unsigned char groupCount : 2;
    unsigned char unused : 2;
    char pad81b2[2];
    Group021607bc groups[4];
    char pad8214[0x8e18 - 0x8214];
    BattleData021607bc* data;
};

// JPN: func_ov000_021607bc
extern "C" ARM void func_ov000_021607bc(Battle021607bc* self) {
    BattleData021607bc* data = self->data;
    Table021607bc* table = &data->table;
    Unit021607bc* units = data->units;
    Group021607bc* groups = self->groups;
    int i;
    unsigned char* members;
    int j;
    Unit021607bc* unit;
    Group021607bc* group;
    for (i = 0; i < self->groupCount; i++) {
        group = &groups[i];
        int key = group->key;
        members = group->members;
        for (j = 0; j < group->memberCount; j++) {
            unit = &units[members[j]];
            Element021607bc* e = func_0207203c(&table->container, key);
            if (e != NULL) {
                unit->name = e->name;
                unit->field54 = e->field82;
                unit->field55 = e->field83;
            }
        }
    }
}

#endif
