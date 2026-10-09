#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02042940(void);
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" void* func_020e2070(void*, int);
extern "C" void func_020426a8(char*, const char*);
extern "C" void func_0205f1c8(void*, int, int);
extern "C" void func_ov003_0215a73c(void*, void*);
extern "C" void func_ov003_0215c8b8(void*);
extern "C" void func_ov003_0215cca0(void*);
extern "C" void func_ov003_0215ca24(void*);

// JPN: func_ov003_0215afa0
extern "C" ARM void func_ov003_0215afa0(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)func_02042940();
    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        if (*(unsigned char*)(s + 0x59d) != 0) return;

        int isSet = _ZNK9GameState21IsMorningDayOrEveningEv((void*)GameState::GetInstance());
        int key = 0x3e8;
        if (!isSet) key += 1;
        void* val = func_020e2070(s + 0x64, key);
        func_020426a8(*(char**)(s + 0x7c), (const char*)val);

        *(int*)(g + 0x868) = 1;
        func_ov003_0215a73c(self, *(void**)(s + 0x7c));

        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (!(state == 1 && *(unsigned char*)(s + 0x59d) == 0 && *(int*)(g + 0x870) == 3)) return;

    func_ov003_0215c8b8(self);
    func_ov003_0215cca0(self);
    func_ov003_0215ca24(self);

    func_0205f1c8(s + 0xf4, 0, 0);
    func_0205f1c8(s + 0xf4, 1, 0);
    func_0205f1c8(s + 0xf4, 2, 0);

    *(unsigned char*)(s + 0x588) = 2;
    *(unsigned char*)(s + 0x580) = 0;
}

#endif
