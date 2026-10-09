#if defined(jpn)
#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_0200f9e8(int* obj);
extern "C" int func_02042940();
extern "C" void func_02043978(char* obj);

struct Outer020e28dc;
extern "C" int func_020e447c(struct Outer020e28dc* o);
struct Obj020e25e8;
extern "C" void func_020e4188(struct Obj020e25e8* obj);

extern "C" void _Z16SetSubBrightnessP13GameResourcesii(int obj, int value, int frames);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(int* obj);
extern "C" void func_ov023_021eb378(char* obj);
extern "C" void func_ov023_021eb3a0(void* obj);
extern "C" void func_ov023_021eb1d0(void* obj);

// JPN: func_ov003_02159700  (semantic: HandleStateTransition3_02159700)
extern "C" ARM void func_ov003_02159700(void* p) {
    char* self = (char*)p;
    GameState* bs = GameState::GetInstance();
    int word0 = func_0200f9e8((int*)bs);
    unsigned char state = *(unsigned char*)(self + 0x1f5);

    if (state == 0) {
        *(int*)(self + 0x328) = 0;
        func_02043978((char*)func_02042940());

        *(short*)(self + 0x1ea) = -1;
        *(short*)(self + 0x1e8) = *(short*)(self + 0x1ea);

        if (*(void**)(self + 0x1c) != 0 &&
            func_020e447c((struct Outer020e28dc*)*(void**)(self + 0x1c)) != 0) {
            func_020e4188((struct Obj020e25e8*)*(void**)(self + 0x1c));
        }

        unsigned char newState = 3;
        *(unsigned char*)(self + 0x1f5) = newState;
        if (*(void**)(self + 0x200) == 0) return;
        _Z16SetSubBrightnessP13GameResourcesii(word0, newState - 0x13, 0);
        *(unsigned char*)(self + 0x1f5) = 1;
        return;
    }

    if (state == 1) {
        if (_Z31IsSubBrightnessTransitionActiveP13GameResources((int*)word0) != 0) return;
        func_ov023_021eb378(*(char**)(self + 0x200));
        *(unsigned char*)(self + 0x1f5) = 2;
        return;
    }

    if (state == 2) {
        func_ov023_021eb3a0(*(void**)(self + 0x200));
        if (*(unsigned short*)(*(char**)(self + 0x200) + 0x438) & 4) {
            func_ov023_021eb1d0(*(void**)(self + 0x200));
            ((SafeAllocator*)(*(char**)(self + 0) + 0x64))->Reset();
            *(int*)(self + 0x200) = 0;
            *(int*)(self + 0x1fc) = 0;
            *(unsigned char*)(self + 0x1f5) = 3;
        }
        return;
    }

    if (state == 3) {
        *(unsigned char*)(self + 0x1f4) = 5;
        *(unsigned char*)(self + 0x1f5) = 0;
    }
}

#endif
