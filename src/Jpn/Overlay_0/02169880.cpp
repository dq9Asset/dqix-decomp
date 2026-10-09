#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"
extern "C" Vec2_0216f74c func_ov000_02170e78(int*);

extern "C" int func_ov000_021555c0(void* obj, short* buf, int max, int start);
extern "C" int func_0204a1c4(unsigned char* obj);
extern "C" void func_0204a9f4(unsigned char* obj, int* src);

struct Words3_02169880 { unsigned int v[3]; };
extern struct Words3_02169880 data_ov000_0218419c;

static inline Vec2_0216f74c GetFormationPosition(const int& cell) {
    return func_ov000_02170e78(const_cast<int*>(&cell));
}

// JPN: func_ov000_02169880
extern "C" ARM void func_ov000_02169880(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    short ids[12];
    int count = func_ov000_021555c0(*(void**)(obj + 0x218), ids, 0xc, 0);
    int i;
    for (i = 0; i < count; i++) {
        GameObject* c = battle->GetCombatantByIndex(ids[i]);
        if (c != 0) {
            Vec2_0216f74c pos = GetFormationPosition(func_0204a1c4((unsigned char*)c));
            struct Words3_02169880 fields = data_ov000_0218419c;
            fields.v[0] = pos.x;
            fields.v[2] = pos.y;
            func_0204a9f4((unsigned char*)c, (int*)&fields);
        }
    }
}

#endif
