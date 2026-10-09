#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;
struct Element0202bad4;
struct ElementArray0202bad4;

extern "C" void* func_0202a9d0(void);
extern "C" void func_0202aca4(void* ptr);
extern "C" void func_0202be38(void* ptr);
extern "C" unsigned short func_0202b83c(struct SearchStruct* obj);
extern "C" int func_0202b69c(void* search);
extern "C" struct Element0202bad4* func_0202b684(struct ElementArray0202bad4* base, int index);
extern "C" void func_0202bd98(struct SearchStruct* obj, int value);

struct Obj021709a0 {
    unsigned char state;
    char pad1[3];
    unsigned int timer;
    char pad8[0x199 - 8];
    signed char selected;
};

// JPN: func_ov003_021709a0
extern "C" ARM void func_ov003_021709a0(struct Obj021709a0* obj) {
    GameState* battle = GameState::GetInstance();
    void* search = func_0202a9d0();
    unsigned int dt = battle->GetEffectiveDeltaTime();

    if (dt < obj->timer) {
        obj->timer -= dt;
        unsigned short mask = func_0202b83c((struct SearchStruct*)search);
        int count = func_0202b69c(search);
        for (int i = 1; i < count; i++) {
            if (mask & (1 << i)) {
                func_0202b684((struct ElementArray0202bad4*)search, i);
                obj->selected = i;
                func_0202bd98((struct SearchStruct*)search, (unsigned char)i);
                func_0202be38(search);
                obj->state = 2;
                return;
            }
        }
    } else {
        obj->timer = 0;
        func_0202aca4(search);
        obj->state = 4;
    }
}

#endif
