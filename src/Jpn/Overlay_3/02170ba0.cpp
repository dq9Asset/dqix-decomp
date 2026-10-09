#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_0202a9d0(void);
extern "C" int func_0202abb0(void* obj);
extern "C" void func_0202aca4(void* p);
extern "C" int func_0202b3b0(int* p);
extern "C" void func_0202bf10(void* self, int value);
extern "C" void func_0202aea0(void* obj);
extern "C" void func_0202bf9c(void* obj);

struct SearchStruct;
extern "C" void func_0202bdcc(struct SearchStruct* obj, int value);
extern "C" void func_0202be38(void* obj);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

// JPN: func_ov003_02170ba0
extern "C" ARM void func_ov003_02170ba0(char* self) {
    GameState* battle = GameState::GetInstance();
    void* search = func_0202a9d0();
    GameObject* combatant = battle->GetProtagonist();

    int r = func_0202abb0(search);
    if (r != 0) {
        if (r == 3) {
            return;
        }
        func_0202aca4(search);
        self[0] = 0xa;
        return;
    }

    func_0202b3b0((int*)search);
    func_0202bf10(search, *(int*)((char*)combatant + 0x134));
    func_0202aea0(search);
    func_0202bf9c(search);
    func_0202bdcc((struct SearchStruct*)search, 0xf);
    func_0202be38(search);

    int v = (rand() % 4 + 2) * 500;
    *(int*)(self + 4) = v;

    signed char b732 = *(volatile signed char*)(self + 0x62e);
    unsigned int half = (unsigned int)v >> 1;
    unsigned int q = _u32_div_f(half * b732, 3);
    *(int*)(self + 4) = q + half;

    *(int*)(self + 0x628) = 0;
    *(int*)(self + 0x618) = 0;
    *(int*)(self + 0x61c) = 0;
    *(int*)(self + 0x620) = 0;
    self[0] = 5;
}

#endif
