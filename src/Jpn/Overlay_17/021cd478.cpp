#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* func_0200fd78(GameState*, int);

extern "C" int func_02054fe4(unsigned char* obj);
struct BitScan02083a50;
extern "C" int func_0208435c(struct BitScan02083a50* obj, short* out, int max);
extern "C" void* func_0202a9dc(void);
extern "C" void func_0205f61c(void* a, void* b, int c);

struct LocalEvt021ccfd0 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char threeBit : 3;
    unsigned char count : 3;
    unsigned char pad4 : 2;
    unsigned char pad5;
    short vals[7];
};

// JPN: func_ov017_021cd478
extern "C" ARM void func_ov017_021cd478(int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = func_0200fd78(bs, combatantId);
    if (!combatant) {
        return;
    }
    int field150 = func_02054fe4((unsigned char*)combatant);
    if (!field150) {
        return;
    }

    unsigned short buffer[288];
    void* p;
    int consumed;
    int j;
    int count;

    count = (unsigned short)func_0208435c((struct BitScan02083a50*)field150, (short*)buffer, 0x11f);
    p = func_0202a9dc();
    consumed = 0;
    j = 0;
    struct LocalEvt021ccfd0 evt;
    evt.tag = 0x10;
    evt.threeBit = (unsigned char)combatantId;

    while (consumed < count) {
        int i = 0;
        for (; i < 7; i++) {
            if (count <= consumed + i) {
                break;
            }
            evt.vals[i] = buffer[j * 7 + i];
        }
        evt.count = i;
        func_0205f61c(p, &evt, 0);
        consumed += evt.count;
        j++;
    }
}

#endif
