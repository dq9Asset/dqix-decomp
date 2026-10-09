#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020bdb70(int id);
struct Obj020bc180;
extern "C" void func_020bdc4c(struct Obj020bc180* obj, int value, int arg);
extern "C" void* func_020bdb34(void* obj, int unused);
extern "C" void func_0203a4d8(void* obj, int arg2);
extern "C" int func_0203a550(void* obj, void* arg1, int* out);
struct Obj0203aba8;
extern "C" int func_0203a600(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void func_0209e058(void* obj, int a, int b);
extern "C" void func_020bd868(void);
extern "C" void func_0203a668(void* obj, void* a, int b);
extern "C" int func_0203a5c4(void* obj, void* arg1);

struct Actor0209c840 {
    char pad0[0xb0];
    int state;                   // 0xb0
    int field_b4;                // 0xb4
    short field_b8;               // 0xb8
    short field_ba;                // 0xba
    void* fieldBC;                  // 0xbc
    void* fieldC0;                    // 0xc0
    void* fieldC4;                      // 0xc4
    unsigned char fc8_bit0 : 1;           // 0xc8
    unsigned char fc8_rest : 7;
    unsigned char field_c9;                 // 0xc9  phase
    unsigned short field_ca;                  // 0xca  timer
    unsigned char field_cc;                     // 0xcc
    unsigned char field_cd;                       // 0xcd
    short field_ce;                                 // 0xce
};

// JPN: func_0209e5b8
extern "C" ARM void func_0209e5b8(struct Actor0209c840* actor) {
    GameState* battle = GameState::GetInstance();

    if (actor->field_c9 == 1) {
        actor->field_ca = 0x320;
        if (actor->state == 1) {
            int count = func_020bdb70(actor->field_b8);
            if (count <= 0) {
                actor->field_ca = 0;
            } else {
                actor->fc8_bit0 = 1;
                func_020bdc4c((struct Obj020bc180*)&actor->fieldBC, 0, 0x14);
            }
        } else if (actor->state == 2) {
            actor->field_ca = 0;
        }
        actor->field_c9 = 2;
        return;
    }

    if (actor->field_c9 == 2) {
        unsigned int elapsed = battle->GetEffectiveDeltaTime();
        if (elapsed < actor->field_ca) {
            actor->field_ca = actor->field_ca - elapsed;
            return;
        }
        func_020bdb34(&actor->fieldBC, 1);
        if (actor->field_b4 > 0) {
            func_0203a4d8(actor, actor->field_b4);
        }
        func_0203a550(actor, (void*)(int)actor->field_ce, 0);
        func_0203a600((struct Obj0203aba8*)actor, (void*)(int)actor->field_ce, &actor->fieldC4);
        func_0209e058(actor, actor->field_cd, 0);
        func_020bd868();
        actor->field_ca = 0x1f4;
        actor->field_c9 = 3;
        return;
    }

    if (actor->field_c9 != 3) {
        return;
    }

    if (actor->field_ce > -1 && func_020bdb70(actor->field_ce) > 0) {
        return;
    }

    {
        unsigned int elapsed = battle->GetEffectiveDeltaTime();
        if (elapsed < actor->field_ca) {
            actor->field_ca = actor->field_ca - elapsed;
            return;
        }
    }

    func_0203a668(actor, &actor->fieldC4, 0);
    actor->field_ce = -1;
    if (actor->state == 1) {
        if (actor->field_b4 > 0) {
            func_0203a4d8(actor, actor->field_b4);
        }
        func_0203a5c4(actor, (void*)(int)actor->field_b8);
        if (actor->fc8_bit0) {
            func_020bdb34(&actor->fieldBC, 0);
            func_020bdc4c((struct Obj020bc180*)&actor->fieldBC, 0, 0);
            func_0209e058(actor, actor->field_cd, 0x1e);
        } else {
            func_0209e058(actor, actor->field_cd, 0);
        }
    }
    actor->field_c9 = 0;
}


#endif
