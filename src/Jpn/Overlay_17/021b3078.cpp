#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
extern "C" GameResources* func_ov017_0218c1d0(void);

extern "C" int func_02042e94(void);
extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int a, int b, int c, int d, unsigned char e, unsigned char f);
extern "C" void* func_020d8608(void);
struct FlagWord02046708;
extern "C" int func_02047528(struct FlagWord02046708* word, unsigned int mask);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void* obj, int value, int frames);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* obj, int value, int frames);
extern "C" void func_02039218(void* obj);

struct Obj021b2968 {
    unsigned char pad0;
    unsigned char flag1;
    char pad2[0x36];
    unsigned int flags0x38;
};

// JPN: func_ov017_021b3078
extern "C" ARM int func_ov017_021b3078(struct Obj021b2968* self) {
    GameResources* oddStruct = func_ov017_0218c1d0();

    unsigned int bit3 = (self->flags0x38 << 28) >> 31;
    if (bit3) {
        void* buf = (void*)func_02042e94();
        memset(buf, 0, 0x800);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(5, (int)buf, 0, 0x800, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(7, (int)buf, 0, 0x800, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(9, (int)buf, 0, 0x800, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(6, (int)buf, 0, 0x20, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(8, (int)buf, 0, 0x20, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0xa, (int)buf, 0, 0x20, 1, 0);

        struct FlagWord02046708* flagWord = (struct FlagWord02046708*)func_020d8608();
        if (!func_02047528(flagWord, 1) && !func_02047528(flagWord, 0x40)) {
            _Z17SetMainBrightnessP13GameResourcesii(oddStruct, 0, 0x28);
        } else {
            _Z13SetBrightnessP13GameResourcesii(oddStruct, 0, 0x28);
        }
    }

    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetUnknownGameObject();
    if (combatant) {
        func_02039218(combatant);
    }

    self->flag1 = 1;
    return 8;
}

#endif
