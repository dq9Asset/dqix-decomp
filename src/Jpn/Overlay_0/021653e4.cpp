#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void* func_02010684(GameState*);

struct S021653e4 { char pad[0x21c]; unsigned char* bitsPtr; };

struct Obj02086b98;
struct S_10088;
extern "C" int func_020a5358(unsigned char* obj, unsigned int index);
extern "C" int func_020874b8(struct Obj02086b98* o);
extern "C" int func_0200fee4(struct S_10088* obj);

// JPN: func_ov000_021653e4
extern "C" ARM int func_ov000_021653e4(struct S021653e4* self, int checkEnemies) {
    GameState* bs = GameState::GetInstance();
    struct Obj02086b98* list = (struct Obj02086b98*)func_02010684(bs);
    int partyOk = 1;
    int i;
    int j;
    for (i = 0; i < 4; i++) {
        GameObject* m = bs->GetPartyMemberByIndex(i);
        if (m == NULL) continue;
        if (func_020a5358(self->bitsPtr, i & 0xff)) continue;
        if (!(**(int**)((char*)m + 0x130) & 1)) partyOk = 0;
    }
    int enemiesOk = func_020874b8(list) != 0;
    if (checkEnemies) {
        enemiesOk = 1;
        for (j = 0; j < 4; j++) {
            GameObject* c = bs->GetCombatantByIndex(j);
            if (c == NULL) continue;
            if (!func_020a5358(self->bitsPtr, j & 0xff)) continue;
            if (!func_0200fee4((struct S_10088*)c)) enemiesOk = 0;
        }
    }
    if (enemiesOk && !partyOk) {
        unsigned char* bits = self->bitsPtr;
        if (bits[0x24] != 0 || bits[0x25] != 0) return 1;
    }
    return 0;
}

#endif
