#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02049efc;

struct CombatantStatus02164428 {
    char pad0[0x14];
    unsigned int flags;
    char pad18[0x22 - 0x18];
    unsigned short b1e : 2;
    unsigned short b1d : 4;

    unsigned int GetFlags() { unsigned int f = flags; return f; }
    unsigned char GetB1d() { unsigned char v = b1d; return v; }
    unsigned char GetB1e() { unsigned char v = b1e; return v; }
};

struct Combatant02164428 {
    char pad0[0xc1];
    unsigned char fieldC1;
    char padC2[0x138 - 0xc2];
    CombatantStatus02164428* status;
};

struct Battle02164428 {
    char pad0[0x218];
    void* field29c;
};

extern "C" int func_ov000_021555c0(void* obj, short* buf, int max, int start);
extern "C" void func_0204ad1c(struct Obj02049efc* obj);
extern "C" void func_ov000_02164530(Battle02164428* self, GameObject* lead, Combatant02164428* actor, unsigned int flags,
                                    int b1d, int b1e, unsigned long long mask, int zero);

// JPN: func_ov000_02164428
extern "C" ARM void func_ov000_02164428(Battle02164428* self) {
    GameState* bs = GameState::GetInstance();
    short ids[12];
    int count = func_ov000_021555c0(self->field29c, ids, 0xc, 0);
    for (int i = 0; i < count; i++) {
        Combatant02164428* c = (Combatant02164428*)bs->GetCombatantByIndex(ids[i]);
        if (!c) continue;
        func_0204ad1c((struct Obj02049efc*)c);
        if (c->status->flags & 1) continue;
        c->fieldC1 &= ~0xf0;
        CombatantStatus02164428* st = c->status;
        func_ov000_02164530(self, NULL, c, st->GetFlags(), st->GetB1d(), st->GetB1e(), 0, 0);
    }
}

#endif
