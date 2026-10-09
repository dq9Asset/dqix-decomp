#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void* func_02010684(GameState*);

extern "C" int func_02054fe4(unsigned char* obj);
extern "C" void func_ov017_021b7168(int combatantId);
extern "C" int func_ov017_021b7310(int a, void* buf);
extern "C" void func_02087098(void* map, void* buf, int c, int d);

// JPN: func_ov003_02163e64  (semantic: AdvanceTargetSearchStep_02163e64)
extern "C" ARM void func_ov003_02163e64(char* obj) {
    unsigned char step = obj[0x2cc];
    if (step == 0) {
        char buf[0x23c];
        GameState* bs = GameState::GetInstance();
        void* map = func_02010684(bs);
        short id = *(short*)(obj + 0x200 + 0xaa);
        GameObject* c = bs->GetPartyMemberByIndex(id);
        if (c == NULL) {
            obj[0x2cb] = 0x10;
            return;
        }
        unsigned char* field150 = (unsigned char*)func_02054fe4((unsigned char*)c);
        if (field150 == NULL) {
            obj[0x2cb] = 0x10;
            return;
        }
        *(short*)(obj + 0x200 + 0xac) = 0xd;
        short v54 = *(short*)(field150 + 0x400 + 0x54);
        if (v54 > 0) {
            *(short*)(obj + 0x200 + 0xae) = 0xe;
        }
        func_ov017_021b7168(*(short*)(obj + 0x200 + 0xaa));
        func_ov017_021b7310(*(short*)(obj + 0x200 + 0xaa), buf);
        func_02087098(map, buf, 0, 0);
        short sv = (buf[0] << 26) >> 26;
        *(short*)(obj + 0x200 + 0xa8) = sv;
        obj[0x2cc] = (unsigned char)obj[0x2cc] + 1;
        *(int*)(obj + 0x28c) |= 8;
        return;
    }
    if (step != 1) return;
    *(short*)(obj + 0x200 + 0xac) = 2;
    *(int*)(obj + 0x28c) |= 8;
    obj[0x2cb] = 1;
    obj[0x2cc] = 0;
}

#endif
