#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct ResetHalfwordPair0208977c;
extern "C" void func_0208a078(struct ResetHalfwordPair0208977c* p);

struct Combatant0215ed08 {
    char pad0[0x138];
    struct ResetHalfwordPair0208977c* stats;
};

struct Slot0215ed08 {
    char pad0[0xf];
    unsigned char active;
    char pad10[0x18 - 0x10];
};

struct Battle0215ed08 {
    char pad0[0x81b0];
    struct Slot0215ed08 slots[3];
};

struct IdList { short v[16]; };
extern IdList data_ov000_02183dcc;

extern "C" void func_ov000_0215e810(struct Battle0215ed08* self);
extern "C" int func_ov000_021555c0(void* obj, short* buf, int max, int start);

// JPN: func_ov000_0215ed08
extern "C" ARM void func_ov000_0215ed08(struct Battle0215ed08* self) {
    func_ov000_0215e810(self);
    for (int i = 0; i < 3; i++) {
        self->slots[i].active = 0;
    }
    IdList ids = data_ov000_02183dcc;
    int count = func_ov000_021555c0(self, ids.v, 0x10, 0);
    for (int i = 0; i < count; i++) {
        int id = ids.v[i];
        GameState* gs = GameState::GetInstance();
        Combatant0215ed08* c = (Combatant0215ed08*)gs->GetCombatantByIndex(id);
        if (c != NULL) {
            func_0208a078(c->stats);
        }
    }
}

#endif
