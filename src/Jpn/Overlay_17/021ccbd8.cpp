#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameObject* func_0200fd78(GameState*, int);

extern "C" void* func_0202a9dc(void);
extern "C" void func_0205f61c(void* a, void* b, int c);
extern "C" int func_02054fe4(unsigned char* obj);

struct LocalEvt021cc730 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short idLow3:3;
    unsigned short byteVal:8;
    unsigned short idxLow4:4;
    unsigned short flagBit:1;
    unsigned short field6;
    unsigned int field8;
    unsigned char fieldc;
    unsigned char fieldd;
    unsigned char fielde;
    unsigned char pad2[4];
};

// JPN: func_ov017_021ccbd8
extern "C" ARM void func_ov017_021ccbd8(int id, unsigned char arg1, unsigned char arg2, unsigned char arg3) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = func_0200fd78(bs, id);
    if (combatant == 0) return;
    int field150 = func_02054fe4((unsigned char*)combatant);
    if (field150 == 0) return;

    void* p = func_0202a9dc();
    LocalEvt021cc730 buf;
    int idx = *(int*)((char*)field150 + 0x8b8);

    buf.tag = 0xa;
    buf.idLow3 = (unsigned short)id;
    buf.byteVal = *(unsigned short*)((char*)field150 + idx * 2 + 0x16c);
    buf.idxLow4 = (unsigned short)*(int*)((char*)field150 + 0x8b8);
    buf.field8 = *(unsigned int*)((char*)field150 + idx * 4 + 0x138);
    buf.field6 = *(unsigned short*)((char*)field150 + 0x564);
    buf.fieldc = *(unsigned char*)((char*)field150 + idx + 0x186);
    buf.flagBit = (unsigned short)arg1;
    buf.fieldd = arg2;
    buf.fielde = arg3;

    func_0205f61c(p, &buf, 0);
}

#endif
