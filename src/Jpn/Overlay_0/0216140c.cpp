#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0216029c(void* p0, short* arr, int count, int flag);
extern "C" GameObject* func_0200fd00(GameState* battleStruct, int combatantId);
extern short data_ov000_02183cfc[8];

struct ShortBlob8_0216140c { short v[8]; };

struct Inner0216140c { char pad[0x10]; unsigned short val; };

// JPN: func_ov000_0216140c
extern "C" ARM int func_ov000_0216140c(void* p0, int targetVal) {
    short localArray[8];
    *(struct ShortBlob8_0216140c*)localArray = *(struct ShortBlob8_0216140c*)data_ov000_02183cfc;
    int count = (short)func_ov000_0216029c(p0, localArray, 8, 0);
    int i = 0;
    while (i < count) {
        short id = localArray[i];
        GameState* bs = GameState::GetInstance();
        GameObject* c = func_0200fd00(bs, id);
        if (c != NULL) {
            struct Inner0216140c* inner = *(struct Inner0216140c**)((char*)c + 0x144);
            if (inner != NULL) {
                if (inner->val == targetVal) {
                    return 1;
                }
            }
        }
        i++;
    }
    return 0;
}

#endif
