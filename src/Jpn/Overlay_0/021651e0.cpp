#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0216017c(int a, short* buf, int max, int start);
extern "C" int func_ov000_0216039c(int a, short* buf, int max, int start);
struct Obj02049f50;
extern "C" void func_0204ad70(struct Obj02049f50* obj, int val, int count);

struct GatherObj02163a7c {
    char pad[0x218];
    int field29c;
};

// JPN: func_ov000_021651e0
extern "C" ARM void func_ov000_021651e0(struct GatherObj02163a7c* obj) {
    GameState* bs = GameState::GetInstance();
    short buf[16];
    int n = 0;
    n = n + func_ov000_0216017c(obj->field29c, buf, 0x10, n);
    n = n + func_ov000_0216039c(obj->field29c, buf + n, 0x10 - n, 0);
    short* p = buf;
    for (int i = 0; i < n; p++, i++) {
        GameObject* c = bs->GetCombatantByIndex(*p);
        if (c) {
            func_0204ad70((struct Obj02049f50*)c, 0x1f, 0);
        }
    }
}

#endif
