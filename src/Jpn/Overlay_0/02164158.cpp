#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02048c90;
extern "C" void func_02049ab0(struct Obj02048c90* obj);
extern "C" void func_0204a904(unsigned char* obj);
extern "C" void func_0204a278(unsigned char* obj, unsigned char value);
extern "C" void func_0204a29c(unsigned char* obj, unsigned char value);
extern "C" void func_0204a1fc(unsigned char* obj, unsigned char value);
extern "C" int func_ov000_0216017c(int a, short* buf, int max, int start);
extern "C" int func_ov000_0216039c(int a, short* buf, int max, int start);

struct GatherObj02164158 {
    char pad[0x218];
    int field29c;
};

// JPN: func_ov000_02164158
extern "C" ARM void func_ov000_02164158(struct GatherObj02164158* obj) {
    GameState* bs = GameState::GetInstance();
    short buf[12];
    int n = 0;
    n = n + func_ov000_0216017c(obj->field29c, buf, 0xc, n);
    n = n + func_ov000_0216039c(obj->field29c, buf + n, 0xc - n, 0);
    for (int i = 0; i < n; i++) {
        GameObject* c = bs->GetCombatantByIndex(buf[i]);
        if (c) {
            func_02049ab0((struct Obj02048c90*)c);
            func_0204a904((unsigned char*)c);
            func_0204a278((unsigned char*)c, 0xff);
            func_0204a29c((unsigned char*)c, 0xff);
            func_0204a1fc((unsigned char*)c, 0xff);
        }
    }
}

#endif
