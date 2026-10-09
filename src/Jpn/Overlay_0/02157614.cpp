#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_0200fee4(struct S_10088* obj);
extern "C" int func_ov000_0215538c(GameObject* combatant);

struct Cnt0x1b1_02157614 { unsigned char counter : 4; unsigned char groupCount : 2; unsigned char unused : 2; };
struct GroupCnt_02157614 { unsigned char total : 4; unsigned char matched : 4; };
#define CNT1B1(o) ((struct Cnt0x1b1_02157614*)((o) + 0x81b1))
#define GCNT(g) ((struct GroupCnt_02157614*)((g) + 0xa))

// JPN: func_ov000_02157614
extern "C" ARM void func_ov000_02157614(unsigned char* obj) {
    int i;
    CNT1B1(obj)->counter = 0;
    for (i = 0; i < CNT1B1(obj)->groupCount; i++) {
        unsigned char* group = obj + 0x81b4 + i * 0x18;
        int j = 0;
        GCNT(group)->matched = 0;
        for (; j < GCNT(group)->total; j++) {
            short id = (short)(*(group + j + 2) + 0xc0);
            GameState* bs = GameState::GetInstance();
            GameObject* c = bs->GetCombatantByIndex(id);
            if (c != NULL && !func_0200fee4((struct S_10088*)c) && !func_ov000_0215538c(c)) {
                GCNT(group)->matched++;
                CNT1B1(obj)->counter++;
            }
        }
    }
}

#endif
