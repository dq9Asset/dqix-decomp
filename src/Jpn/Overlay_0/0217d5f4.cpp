#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* func_0200fd78(GameState*, int);

struct Outer_02054000;
extern "C" void* func_02055378(struct Outer_02054000* p);
extern "C" int func_ov000_02176754(void* objRaw);

struct Data0217c2a0 {
    void* field8;
    int field0;
    int field4;
};
extern Data0217c2a0 data_ov000_02185394;

// JPN: func_ov000_0217d5f4
extern "C" ARM int func_ov000_0217d5f4(void* objRaw) {
    char* obj = (char*)objRaw;
    int result = 0;
    GameState* battleStruct = GameState::GetInstance();
    int combId = *(int*)(obj + 0x4c);
    GameObject* combatant = func_0200fd78(battleStruct, combId);
    if (combatant != 0) {
        void* sub = func_02055378((struct Outer_02054000*)combatant);
        if (sub != 0) {
            short val = *(short*)((char*)sub + 0x18);
            if (val > 0) {
                struct Bits02f4 { unsigned int bit0 : 1; unsigned int bit1 : 1; unsigned int hi : 30; };
                struct Bits02f4* bits = (struct Bits02f4*)(*(int*)((char*)combatant + 0x144) + 0x2f4);
                if (bits->bit1) {
                    result = 1;
                } else {
                    if (bits->bit0) {
                        if (func_ov000_02176754(data_ov000_02185394.field8) == 1) {
                            result = 1;
                        }
                    }
                }
            }
        }
        if (data_ov000_02185394.field0 == 1) {
            result = 1;
        }
    }
    return result;
}

#endif
