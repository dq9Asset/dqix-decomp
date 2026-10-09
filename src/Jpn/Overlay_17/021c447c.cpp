#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* func_0200fd78(GameState*, int);

struct Field150Holder02052e14;
extern "C" short* func_020541e4(struct Field150Holder02052e14* obj);
extern "C" void* func_0202a9dc(void);
extern "C" void func_0205f61c(void* a, void* b, int c);

struct Evt021c3fb4 {
    unsigned char tag;
    unsigned char pad[3];
    unsigned char combatantId : 4;
    unsigned char flag : 1;
    unsigned char slots[5];
    short values[5];
};

// JPN: func_ov017_021c447c
extern "C" ARM void func_ov017_021c447c(int combatantId, int flag) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = func_0200fd78(bs, combatantId);
    if (c == NULL) return;

    short* list = func_020541e4((struct Field150Holder02052e14*)c);
    if (list == NULL) return;

    void* data = func_0202a9dc();

    struct Evt021c3fb4 evt;
    evt.tag = 2;
    evt.combatantId = combatantId;

    evt.slots[0] = 0;
    evt.values[0] = list[0];
    evt.slots[1] = 1;
    evt.values[1] = list[1];
    evt.slots[2] = 2;
    evt.values[2] = list[2];
    evt.slots[3] = 3;
    evt.values[3] = list[3];
    evt.slots[4] = 4;
    evt.values[4] = list[4];
    evt.flag = 0;
    func_0205f61c(data, &evt, 0);

    evt.slots[0] = 5;
    evt.values[0] = list[5];
    evt.slots[1] = 6;
    evt.values[1] = list[6];
    evt.slots[2] = 7;
    evt.values[2] = list[7];
    evt.slots[3] = 8;
    evt.values[3] = list[8];
    evt.slots[4] = 9;
    evt.values[4] = list[9];
    evt.flag = flag;
    func_0205f61c(data, &evt, 0);
}

#endif
