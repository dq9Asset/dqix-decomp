#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameResources* func_ov017_0218c1d0(void);

extern "C" void* func_0202a9d0(void* ctx);
struct SearchStruct0202c1a4;
extern "C" signed char func_0202bd54(struct SearchStruct0202c1a4* obj);
struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
struct ListHead02046b60;
extern "C" int func_02047980(struct ListHead02046b60* list, int id);
extern "C" int func_02042940();
extern "C" void func_ov017_021d0c4c(unsigned char a, unsigned char b, unsigned short c);

struct Obj021b996c { char pad[0x12c]; int field12c; };

// JPN: func_ov017_021b9e68
extern "C" ARM void func_ov017_021b9e68(struct Obj021b996c* self, int combatantId, int checkVal, unsigned char tag, unsigned short arg5) {
    void* search = func_0202a9d0(self);
    signed char cur = func_0202bd54((struct SearchStruct0202c1a4*)search);
    if (checkVal != cur && checkVal != 4) return;

    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetGameObjectByIndex(combatantId);
    GameObject* combatant2 = battle->GetUnknownGameObject();
    unsigned short u1 = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant);
    unsigned short u2 = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant2);
    if (u1 != u2) {
        func_ov017_021d0c4c(tag, 1, 1);
        return;
    }

    int field5724;
    if (self->field12c != arg5 && (field5724 = *(int*)((char*)battle + 0x54c4)) != arg5) {
        void* p = ((void* (*)(void*))func_ov017_0218c1d0)((void*)field5724);
        struct ListHead02046b60* list = *(struct ListHead02046b60**)((char*)p + 0x3000 + 0x4ec);
        if (func_02047980(list, 4)) {
            func_ov017_021d0c4c(tag, 1, 0);
        } else {
            func_ov017_021d0c4c(tag, 1, 1);
        }
        return;
    }

    int g = func_02042940();
    if (*(int*)(g + 0x868) != 0) {
        func_ov017_021d0c4c(tag, 1, 0);
        return;
    }

    unsigned char cur2 = (unsigned char)func_0202bd54((struct SearchStruct0202c1a4*)search);
    if (tag < cur2) {
        func_ov017_021d0c4c(tag, 1, 1);
    } else {
        func_ov017_021d0c4c(tag, 1, 0);
    }
}

#endif
