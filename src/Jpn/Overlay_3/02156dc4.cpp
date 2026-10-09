#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" float _fflt(int v);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float v);
extern "C" void* func_0202a9d0(void);
extern "C" int func_0202b388(int* obj);
extern "C" void func_ov017_021ca2b0(int id, int flagA, int flagB, int flagC);

// JPN: func_ov003_02156dc4  (semantic: RescaleCombatantSizeTarget_02156dc4)
extern "C" ARM void func_ov003_02156dc4(char* obj) {
    GameState* battle = GameState::GetInstance();
    signed char idx = *(signed char*)(obj + 0x1f3);
    GameObject* c = battle->GetPartyMemberByIndex(idx);
    if (c == 0) {
        return;
    }

    if (*(int*)(obj + 0x1f8) & 1) {
        unsigned short* src = *(unsigned short**)((char*)c + 0x134);
        unsigned short w = src[0x30 / 2];
        int v1 = _ffix(_fmul(*(float*)(obj + 0x32c), _fflt(w)));
        unsigned short h = src[0x32 / 2];
        int v2 = _ffix(_fmul(*(float*)(obj + 0x330), _fflt(h)));

        if (v1 <= 0) v1 = 1;
        if (v2 <= 0) v2 = 0;
        if (w < v1) v1 = w;
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = (unsigned short)v1;
        if (h < v2) v2 = h;
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = (unsigned short)v2;
    } else {
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x30);
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x32);
    }

    void* ptr = func_0202a9d0();
    if (func_0202b388((int*)ptr) == 0) {
        return;
    }
    signed char id2 = *(signed char*)(obj + 0x1f3);
    func_ov017_021ca2b0(id2, 1, 0, 1);
}

#endif
