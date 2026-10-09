#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_02173ac0(void* obj);
extern "C" void* func_0202a9d0(GameState* gs);

struct Entry02175f08 {
    char pad0[0x24];
    unsigned char field24;
    char pad25[0x44 - 0x25];
    int posX;
    int posY;
    int combatantId;
    char pad50[0x488 - 0x50];
};

struct Obj02175f08 {
    char pad0[0x6c];
    signed char order[4];
    char pad70[0x958 - 0x70];
    struct Entry02175f08 entries[4];
};

// JPN: func_ov000_02175f08
extern "C" ARM void func_ov000_02175f08(struct Obj02175f08* obj) {
    func_ov000_02173ac0(obj);
    func_0202a9d0(GameState::GetInstance());
    int any = 0;
    for (int i = 0; i < 4; i++) {
        struct Entry02175f08* entry = &obj->entries[obj->order[i]];
        if (entry->combatantId < 0) {
            continue;
        }
        int flag = (entry->field24 & 4) ? 1 : 0;
        any = (any | flag) ? 1 : 0;
    }
    int y = 0;
    if (!any) {
        y = 0x20;
    }
    struct Entry02175f08* entry;
    for (int j = 0; j < 4; j++) {
        entry = &obj->entries[obj->order[j]];
        int id = entry->combatantId;
        int valid = 0;
        if (id >= 0) {
            valid = id <= 3;
        }
        if (!valid) {
            continue;
        }
        entry->posX = 0;
        entry->posY = y;
        if (entry->field24 & 4) {
            y += 0x48;
        } else {
            y += 0x28;
        }
    }
}

#endif
