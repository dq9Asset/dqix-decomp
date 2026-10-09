#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02058c9c(void* p);
extern "C" int func_ov000_02164074(void* obj, int idx, int* out);
extern "C" int func_020599f8(char* base, int value, void** out, int limit);

// JPN: func_ov000_021640c0
extern "C" ARM int func_ov000_021640c0(void* self) {
    GameState* bs = GameState::GetInstance();
    void* base = func_02058c9c(bs);
    int idx = *(int*)((char*)self + 0x5000 + 0x7c8);
    int localArray[12];
    int count = func_ov000_02164074(self, idx, localArray);
    int i = 0;
    while (i < count) {
        GameObject* c = bs->GetCombatantByIndex(localArray[i]);
        if (c != NULL) {
            if (*((unsigned char*)c + 0xbe) == 4) {
                return 1;
            }
        }
        i++;
    }
    return func_020599f8((char*)base, 2, NULL, 0) > 0;
}

#endif
