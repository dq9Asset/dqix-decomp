#if defined(jpn)
#include <globaldefs.h>
#include "Resource/GameResources.h"
extern "C" GameResources* func_ov017_0218c1d0(void);
#include "GameState/GameState.h"

struct Obj020397cc;
extern "C" void func_02039224(Obj020397cc* obj, int arg1);
extern "C" int func_0200ff54(char* obj);
extern "C" void func_020a4518(void* obj);
extern "C" void func_020a450c(void* obj);
extern "C" void func_0203af30(unsigned int* obj, unsigned int mask);
extern "C" void func_0203af40(unsigned int* obj, unsigned int mask);
extern "C" void func_02039218(void* obj);
extern "C" void func_ov017_0218e18c(void* obj);
struct ListHead02046b38;
struct ListNode02046b38;
extern "C" int func_02047958(ListHead02046b38* list, ListNode02046b38* target);
extern "C" void func_ov017_021b5fe4(void* self);

typedef int (*StateFn_021b58b8)(void*);
struct FuncTable_021d6c04 { StateFn_021b58b8 fn[7]; };
extern FuncTable_021d6c04 data_ov017_021d6ffc;

struct SelfState_021b58b8 {
    unsigned char pad0[0x1];
    unsigned char field1;
    unsigned char pad2[0x6];
    int field8;
    unsigned char pad3[0xc];
    unsigned short field18;
    unsigned char pad4[0x3a];
    unsigned char field54;
};

// JPN: func_ov017_021b5e6c
extern "C" ARM void func_ov017_021b5e6c(SelfState_021b58b8* self, ListNode02046b38* arg1) {
    if (self->field18 != 0) {
        GameState* battleStruct = GameState::GetInstance();
        GameObject* combatant = battleStruct->GetUnknownGameObject();
        if (combatant != 0) {
            unsigned int val = (unsigned int)battleStruct->GetEffectiveDeltaTime();
            if (val < self->field18) {
                func_02039224((Obj020397cc*)combatant, 1);
                *(unsigned short*)((char*)combatant + 0xb2) = 0;
                self->field18 = self->field18 - val;
                int flag = func_0200ff54((char*)battleStruct);
                if (flag != 0) {
                    func_020a4518((void*)flag);
                }
                GameResources* ov = func_ov017_0218c1d0();
                if (ov != 0) {
                    func_0203af30((unsigned int*)ov, 0x80);
                }
            } else if (self->field54 == 0) {
                func_02039218((void*)combatant);
                self->field18 = 0;
                int flag = func_0200ff54((char*)battleStruct);
                if (flag != 0) {
                    func_020a450c((void*)flag);
                }
                GameResources* ov = func_ov017_0218c1d0();
                if (ov != 0) {
                    func_0203af40((unsigned int*)ov, 0x80);
                }
            }
        }
    }

    GameResources* ov = func_ov017_0218c1d0();
    if (ov != 0) {
        func_ov017_0218e18c((void*)ov);
    }

    FuncTable_021d6c04 table = data_ov017_021d6ffc;
    StateFn_021b58b8 fn = table.fn[self->field8];
    if (fn != 0) {
        self->field8 = fn(self);
    }

    if (func_02047958((ListHead02046b38*)arg1, *(ListNode02046b38**)((char*)ov + 0x3000 + 0x4fc)) != 0) {
        self->field1 = 1;
        func_ov017_021b5fe4(self);
    }
    if (self->field1 != 0) {
        func_0203af40((unsigned int*)ov, 0x40);
    }
}

#endif
