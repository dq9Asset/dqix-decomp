#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct OutStruct0215ccbc;

extern "C" void func_ov000_0215c00c(void* world, void* entry, int value);
extern "C" void func_ov000_02161604(void* chain, void* entry, int idx);
extern "C" void func_ov000_0215b62c(void* world, void* buf, int kind);
extern "C" void func_ov000_0215e43c(
    void* world, struct OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    unsigned long long words, unsigned char byteE);

static inline short CurrHP(GameObject* c) { short v = c->currentStats_->primaryStats.currHP; return v; }
static inline short CurrMP(GameObject* c) { short v = c->currentStats_->primaryStats.currMP; return v; }

// JPN: func_ov000_02159c68
extern "C" ARM void func_ov000_02159c68(void* world, struct OutStruct0215ccbc* entry, GameObject* combatant,
                                        void* chain, int value, unsigned char kind) {
    func_ov000_0215c00c(world, entry, (unsigned short)value);
    func_ov000_02161604(chain, entry, 1);
    ((unsigned char*)world)[0x8e02]++;
    unsigned long long words = 0;
    func_ov000_0215b62c(world, &words, kind);
    func_ov000_0215e43c(
        world, entry, combatant, 0, CurrHP(combatant), CurrMP(combatant), words, 0);
}

#endif
