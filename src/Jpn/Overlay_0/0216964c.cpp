#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02049e88;
extern "C" void func_0204aca8(struct Obj02049e88* obj);
extern "C" void func_0204a904(unsigned char* obj);
extern "C" int func_020a5358(unsigned char* obj, unsigned int index);

// JPN: func_ov000_0216964c  (semantic: ResetSubFlagsForCombatants_0216964c)
extern "C" ARM void func_ov000_0216964c(unsigned char* obj) {
    GameState* bs = GameState::GetInstance();
    GameObject* c;
    int i;
    for (i = 0; i < 4; i++) {
        if (func_020a5358(*(unsigned char**)(obj + 0x21c), i & 0xff)) {
            c = bs->GetCombatantByIndex(i);
            if (c) {
                func_0204aca8((struct Obj02049e88*)c);
                func_0204a904((unsigned char*)c);
            }
        }
    }
    for (i = 0xc0; i < 0xc8; i++) {
        c = bs->GetCombatantByIndex(i);
        if (c) {
            func_0204aca8((struct Obj02049e88*)c);
            func_0204a904((unsigned char*)c);
        }
    }
    obj[0x5b41] &= ~0x3;
}

#endif
