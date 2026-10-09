#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void* func_02010684(GameState*);

extern "C" int func_020a5358(unsigned char* obj, unsigned int index);
struct ArrayContainsByteStruct;
extern "C" int func_02087810(struct ArrayContainsByteStruct* s, int val);
extern "C" int func_02054fe4(unsigned char* obj);
extern "C" void func_02084560(void* p, int flag, int mode);

// JPN: func_ov000_02168c34
extern "C" ARM void func_ov000_02168c34(unsigned char* obj, int skipArrayCheck) {
    GameState* battle = GameState::GetInstance();
    struct ArrayContainsByteStruct* base = (struct ArrayContainsByteStruct*)func_02010684(battle);
    unsigned char* bits = *(unsigned char**)((char*)*(void**)(obj + 0x218) + 0x8000 + 0xe18);
    for (int i = 0; i < 4; i++) {
        if (!func_020a5358(bits, (unsigned char)i)) continue;
        if (skipArrayCheck == 0) {
            if (!func_02087810(base, i)) continue;
        }
        GameObject* c = battle->GetPartyMemberByIndex(i);
        if (!c) continue;
        int val150 = func_02054fe4((unsigned char*)c);
        int contains = func_02087810(base, i);
        func_02084560((void*)val150, contains, 1);
    }
}

#endif
