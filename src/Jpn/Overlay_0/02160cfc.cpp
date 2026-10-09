#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct ToggleBits3c_891b0 {
    unsigned char pad[0x3c];
    unsigned char bit0 : 1;
};

struct Inner02160cfc {
    char pad[0x10];
    unsigned int skip : 8;
    unsigned int slot : 3;
    unsigned int rest : 21;
};

struct Combatant02160cfc {
    char pad0[0x138];
    struct ToggleBits3c_891b0* field138;
    char pad1[0x148 - 0x13c];
    struct Inner02160cfc* field148;
};

struct ByteTable8_02160cfc {
    signed char v[8];
};

extern "C" GameObject* func_0200fd00(GameState* battleStruct, int combatantId);
extern "C" void func_02089aac(struct ToggleBits3c_891b0* obj);

extern struct ByteTable8_02160cfc data_ov000_02183b24;

static inline int InRange(int i) { return i >= 0 && i <= 3; }

// JPN: func_ov000_02160cfc
extern "C" ARM int func_ov000_02160cfc(struct Random* rng, int id) {
    if (InRange(id)) {
        return 0;
    }
    struct Combatant02160cfc* c = (struct Combatant02160cfc*)func_0200fd00(GameState::GetInstance(), id);
    struct Inner02160cfc* inner = c->field148;
    int flag = c->field138->bit0 ? 1 : 0;
    int r = NextRandomMax(rng, 2);
    struct ByteTable8_02160cfc t = data_ov000_02183b24;
    t.v[1] = r != 0;
    t.v[4] = flag != 0 ? 1 : 0;
    t.v[5] = flag == 0 ? 0 : 2;
    t.v[6] = flag != 0 ? 0 : 1;
    t.v[7] = flag == 0 ? 2 : 0;
    int result = t.v[inner->slot];
    func_02089aac(c->field138);
    return result;
}

#endif
