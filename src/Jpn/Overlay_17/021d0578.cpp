#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02010684(GameState* battleStruct);
extern "C" GameObject* func_0200fd78(GameState* battleStruct, int combatantId);
extern "C" int func_02054fe4(unsigned char* obj);

struct ShortArrayCommand {
    int id;
    unsigned char idx;
    unsigned char count;
    short arr[6];
};

// JPN: func_ov017_021d0578
extern "C" ARM void func_ov017_021d0578(int unused0, char* p1raw, GameState* bs) {
    struct ShortArrayCommand* p1 = (struct ShortArrayCommand*)(p1raw + 4);
    int id = p1->id;
    unsigned char* list = (unsigned char*)func_02010684(bs);
    int i;
    for (i = 0; i < list[0xf7c]; i++) {
        unsigned char* row = list + i;
        if (id == row[0xf78]) return;
    }

    GameObject* c = func_0200fd78(bs, id);
    if (!c) return;
    int field144 = func_02054fe4((unsigned char*)c);
    if (!field144) return;

    char* dst = (char*)field144 + 0x454;
    unsigned char idx = p1->idx;
    unsigned char cnt = p1->count;
    for (int j = 0; j < cnt; j++) {
        *(short*)(dst + (idx + j) * 2) = p1->arr[j];
    }
}

#endif
