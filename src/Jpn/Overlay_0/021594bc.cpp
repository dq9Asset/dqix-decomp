#if defined(jpn)
#include <globaldefs.h>

struct ActionEntry {
    char pad0[0x20];
    short combatantId;
};

struct List02160094 {
    char pad0[8];
    unsigned char entryCount;
};

struct IdList {
    short v[8];
};

struct Battle {
    char pad0[0x81b1];
    unsigned char aliveCount : 4;
    unsigned char groupCount : 2;
    char pad81b2[0x8e14 - 0x81b2];
    signed char result;
};

extern IdList data_ov000_02183d2c;

extern "C" void func_ov000_02157614(Battle* battle);
extern "C" int func_ov000_0216017c(Battle* battle, short* buf, int max, int start);
extern "C" void func_ov000_02159d0c(Battle* battle, int combatantId, ActionEntry* entry);
extern "C" void func_ov000_0215b174(Battle* battle, int combatantId);
extern "C" ActionEntry* func_ov000_02161814(List02160094* list, int index);

// JPN: func_ov000_021594bc
extern "C" ARM void func_ov000_021594bc(Battle* battle, List02160094* action, int flag) {
    func_ov000_02157614(battle);
    IdList ids = data_ov000_02183d2c;
    if (func_ov000_0216017c(battle, ids.v, 8, 9) <= 0) {
        battle->result = 2;
    } else if (battle->aliveCount == 0) {
        battle->result = 1;
    } else {
        battle->result = 0;
    }
    if (battle->result == 0 && flag == 0) {
        int i;
        for (i = 0; i < action->entryCount; i++) {
            ActionEntry* entry = func_ov000_02161814(action, i);
            if (entry != 0) {
                func_ov000_02159d0c(battle, entry->combatantId, entry);
                func_ov000_0215b174(battle, entry->combatantId);
            }
        }
    }
}

#endif
