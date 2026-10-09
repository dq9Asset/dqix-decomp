#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameResources* func_ov017_0218c1d0(void);
#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" void* func_0202a9d0(void);
extern "C" GameObject* func_0200fd78(GameState* battleStruct, int combatantId);
struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
extern "C" unsigned short func_02027ccc(void* a, void* b);
extern "C" int func_0202c094(void* obj);
extern "C" void* func_02012dac(void);
extern "C" int func_ov017_021a2bb8(void* a, int b, int c, int d, void* e, int f, int g, int h);

struct Buf3_021b5648 { unsigned int a, b, c; };
extern struct Buf3_021b5648 data_ov017_021d6fc4;

// JPN: func_ov017_021b5bfc
extern "C" ARM void func_ov017_021b5bfc(char* self) {
    GameState* bs = GameState::GetInstance();
    void* ctx = func_0202a9d0();

    int i;
    for (i = 0; i < 4; i++) {
        GameObject* c = func_0200fd78(bs, i);
        if (c == 0) continue;
        void* p8 = *(void**)(self + 0x8);
        if (*(unsigned short*)p8 != _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)c)) continue;

        unsigned short v = func_02027ccc((char*)p8 + 0x14, (char*)c + 0x44);
        *(unsigned short*)((char*)c + 0xb8) = v;
        ((unsigned char*)c)[0xc2] |= 0x40;
    }

    if (func_0202c094(ctx) != 0 && *(unsigned short*)(self + 0x12) != 0) {
        GameState* bs2 = GameState::GetInstance();
        void* obj5 = func_ov017_0218c1d0();
        bs2->GetGrottoStruct();
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012dac() + 0x240c);
        unsigned char env = grotto->GetActiveGrottoEnviron() & 0xff;

        struct Buf3_021b5648 local = data_ov017_021d6fc4;
        switch (env) {
            case 1: local.c = 0xfffecccd; break;
            case 2: local.c = 0xffff019a; break;
            case 3: local.c = -0x13800; break;
            case 4: local.c = 0xfffecccd; break;
            case 5: local.c = 0xfffebb34; break;
            default: local.c = 0xfffecccd; break;
        }

        unsigned char flags = 0;
        if (((unsigned char*)self)[0x11] == 1) flags |= 2;
        else if (((unsigned char*)self)[0x11] == 2) flags |= 4;

        func_ov017_021a2bb8(obj5, *(unsigned short*)(*(void**)(self + 0x8)),
                             *(unsigned short*)(self + 0x12), -1, &local, 0, 0, flags);
    }

    *(unsigned short*)((char*)(*(void**)(self + 0x8)) + 2) |= 0x8;
    self[1] = 1;
}

#endif
