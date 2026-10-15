#include <globaldefs.h>

#include "Combat/BattleSkillEligibility.h"
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"
#include "World/Zone3D.h"

extern "C" void* func_0202ae18(void);
extern "C" Zone3D* func_02012fe4(void);
extern "C" int func_0202c540(void* p);

int GetIntField0x260_02039750(void* obj);
int GetGlobalField0x1c020421a0();
void* GetGlobalContext020daf90(void);
int IsField0Null_02046b08(void** obj);

struct Something02015a2c;
int CheckSlotsForFlagState02015a2c(struct Something02015a2c* obj);

int GetField0x50_020db2d4(void* obj);

extern "C" void func_ov017_021a5bac(unsigned char* base);
void InitFieldArenaLists_021a5b48(unsigned char* base);
extern "C" void func_ov017_021a5cbc(GameResources* self);

typedef union {
    unsigned short raw;
    struct {
        unsigned short priority : 2;
        unsigned short charBase : 4;
        unsigned short mosaic : 1;
        unsigned short colorMode : 1;
        unsigned short screenBase : 5;
        unsigned short extPalette : 1;
        unsigned short screenSize : 2;
    };
} BgControl;

static inline BgControl GetBg1Control() {
    return *(volatile BgControl*)0x400000a;
}

static inline BgControl GetBg2Control() {
    volatile BgControl* reg = (volatile BgControl*)0x400000c;
    return *reg;
}

// USA: func_ov017_021a624c
extern "C" ARM void func_ov017_021a624c(GameResources* self) {
    void* searchObj = func_0202ae18();
    GameState* gs = GameState::GetInstance();
    GameObject* protagonist = gs->GetProtagonist();
    if (protagonist == 0) return;

    int f260 = GetIntField0x260_02039750(protagonist);
    int glob1c = GetGlobalField0x1c020421a0();
    GrottoStruct* grotto;
    Zone3D_StructPtr_8* info;
    Zone3D* zone = func_02012fe4();
    info = zone->pUnknownStruct_8_;
    grotto = gs->GetGrottoStruct();
    void* ctx = GetGlobalContext020daf90();

    if (gs->GetGrottoStruct()->unknown_0[0] == 0 ||
        self->unknown_4080 != 0 || f260 != -1 ||
        !IsField0Null_02046b08((void**)self->unknown_ptr_array_36fc[0]) ||
        func_0202c540(searchObj) ||
        IsGlobalU16InRange_020117f0(GameState::GetInstance()) != 0 ||
        *(int*)((char*)glob1c + 0x998) != 0 ||
        CheckSlotsForFlagState02015a2c((struct Something02015a2c*)zone) ||
        info == 0 || info->unknown_c_low_ != 0 ||
        GetField0x50_020db2d4(ctx)) {
        grotto->unknown_0[2] = 1;
        func_ov017_021a5bac((unsigned char*)self);
    } else if (*(int*)(self->unknown_4094 + 0x12c) == 0) {
        *(BgControl*)self->unknown_ptr_array_4088[0] = GetBg1Control();
        *(BgControl*)self->unknown_ptr_array_4088[1] = GetBg2Control();
        grotto->unknown_0[2] = 0;
        InitFieldArenaLists_021a5b48((unsigned char*)self);
        *(int*)(self->unknown_4094 + 0x12c) = 1;
    } else {
        func_ov017_021a5cbc(self);
    }
}
