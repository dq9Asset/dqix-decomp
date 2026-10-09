#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3_021c3f68 {
    int x;
    int y;
    int z;
};
extern "C" void func_ov017_021c4430(struct Vec3_021c3f68* obj, int x, int y, int z);
extern "C" unsigned short func_ov017_021b8990(void* obj);
extern "C" void func_0203977c(unsigned char* obj);
struct Fields020407b4;
extern "C" void func_02040cb0(struct Fields020407b4* dst, int a, int b, int c);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Evt021d2b24 {
    char pad0[4];
    unsigned char id;
    unsigned char flag5;
    char pad6[2];
    int field8;
    int fieldc;
    int field10;
};

struct Entry021d2b24 {
    char pad0[3];
    unsigned char field3;
    char pad4[0xfb];
    unsigned char field103;
};

// JPN: func_ov017_021d2fa8
extern "C" ARM void func_ov017_021d2fa8(void* unused0, struct Evt021d2b24* evt, int unused2, void* ctxRaw) {
    unsigned char* ctx = (unsigned char*)ctxRaw;
    GameState* battle = GameState::GetInstance();

    if (evt->id == 0xce) {
        func_ov017_021c4430((struct Vec3_021c3f68*)((char*)battle + 0x7c8c), evt->field8, evt->fieldc, evt->field10);
    }

    GameObject* combatant = battle->GetPartyMemberByIndex(evt->id);
    if (combatant == NULL) {
        return;
    }

    struct Entry021d2b24* entryPtr = *(struct Entry021d2b24**)(ctx + 0x3000 + 0x524);
    if (entryPtr->field3 != 0 && entryPtr->field103 != 0) {
        return;
    }

    void* ptr718 = *(void**)(ctx + 0x3000 + 0x508);
    if (*(unsigned char*)((char*)ptr718 + 0x2) != 0 && func_ov017_021b8990(ptr718) == 0) {
        return;
    }

    func_0203977c((unsigned char*)combatant);
    func_02040cb0((struct Fields020407b4*)combatant, evt->field8, evt->fieldc, evt->field10);

    if (evt->flag5 != 0) {
        struct Vec3_021c3f68 tmp;
        func_ov017_021c4430(&tmp, evt->field8, evt->fieldc, evt->field10);
        _ZN8Vector3iaSERKS_((int*)((char*)combatant + 0xd4), (int*)&tmp);
        *(unsigned char*)((char*)combatant + 0xe0) |= 0x20;
    }

    *(unsigned short*)((char*)combatant + 0xac) = 0;

    if (evt->id == 0xce) {
        func_02040cb0((struct Fields020407b4*)combatant, evt->field8, evt->fieldc, evt->field10);
    }
}

#endif
