#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* func_0200fd78(GameState*, int);

struct HpMpGauge02163cf8 {
    char pad0[8];
    unsigned short maxHP;
    unsigned short maxMP;
    short currHP;
    short currMP;
};

struct CombatantFlags02163cf8 {
    char pad[0x14];
    unsigned int flags;
};

struct BattleUi02163cf8 {
    char pad0[0x21c];
    unsigned char* activeBits;
    char pad2a4[0x371c - 0x220];
    char gauges[1];
};

extern "C" int func_020a5358(unsigned char* obj, unsigned int index);
extern "C" HpMpGauge02163cf8* func_ov000_02162a84(void* obj, int index);
extern "C" void func_ov000_02180848(HpMpGauge02163cf8* gauge);
extern "C" void func_ov000_021774fc(HpMpGauge02163cf8* gauge, unsigned short val);
extern "C" void func_ov000_02177518(HpMpGauge02163cf8* gauge, unsigned short val);

// JPN: func_ov000_02163cf8
extern "C" ARM void func_ov000_02163cf8(BattleUi02163cf8* self) {
    GameState* bs = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        if (!func_020a5358(self->activeBits, i & 0xff)) continue;
        GameObject* c = func_0200fd78(bs, i);
        if (!c) continue;
        HpMpGauge02163cf8* gauge = func_ov000_02162a84(self->gauges, i);
        if (!gauge) continue;
        if (gauge->currHP == 0 && !(((CombatantFlags02163cf8*)c->currentStats_)->flags & 1)) {
            func_ov000_02180848(gauge);
        }
        unsigned short hp = c->currentStats_->primaryStats.currHP;
        func_ov000_021774fc(gauge, hp);
        gauge->currHP = hp;
        unsigned short mp = c->currentStats_->primaryStats.currMP;
        func_ov000_02177518(gauge, mp);
        gauge->currMP = mp;
        gauge->maxHP = c->baseStats_->primaryStats.maxHP;
        gauge->maxMP = c->baseStats_->primaryStats.maxMP;
    }
}

#endif
