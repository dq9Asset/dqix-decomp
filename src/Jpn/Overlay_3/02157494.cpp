#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02054fe4(unsigned char* obj);
extern "C" void func_020845d4(void* a, void* obj, void* tail);
extern "C" void func_02084740(void* a, int arg2);
extern "C" void* func_0202a9d0(void);
extern "C" int func_0202b388(int* obj);

extern "C" void func_ov017_021ccbd8(int id, unsigned char arg1, unsigned char arg2, unsigned char arg3);
extern "C" void func_ov017_021cf520(int combatantId, unsigned short slot, unsigned char flag);
extern "C" void func_ov017_021cd0dc(int combatantId);
extern "C" void func_ov017_021ca2b0(int id, int flagA, int flagB, int flagC);

// JPN: func_ov003_02157494  (semantic: SyncFlaggedCombatantAndDispatch_02157494)
extern "C" ARM void func_ov003_02157494(void* p) {
    char* obj = (char*)p;
    GameState* bs = GameState::GetInstance();
    signed char idx = *(signed char*)(obj + 0x1f3);
    GameObject* c = bs->GetPartyMemberByIndex(idx);
    if (c == 0) {
        return;
    }
    int t = *(int*)((char*)c + 0x144);
    int slot = *(int*)((char*)t + 0x8b8);
    int field150 = func_02054fe4((unsigned char*)c);
    char* arr = (char*)field150;
    *(short*)(arr + slot * 2 + 0x16c) = 1;
    unsigned char* cntArr = (unsigned char*)(arr + 0x186);
    *(int*)(arr + slot * 4 + 0x138) = 0;
    unsigned char v = ++cntArr[slot];
    if (v > 10) {
        cntArr[slot] = v = 10;
    }
    func_020845d4(arr, obj + 0x90, obj + 0xcc);
    func_02084740(arr, 0);
    *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x30);
    *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x32);
    if (func_0202b388((int*)func_0202a9d0()) == 0) {
        return;
    }
    signed char id2 = *(signed char*)(obj + 0x1f3);
    func_ov017_021ccbd8(id2, 1, 0, 0);
    func_ov017_021cf520(id2, (unsigned char)slot, 0);
    func_ov017_021cd0dc(id2);
    func_ov017_021ca2b0(id2, 1, 0, 1);
}

#endif
