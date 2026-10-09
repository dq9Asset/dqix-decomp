#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02010684(GameState* battleStruct);
extern "C" short func_02080fa4(void* obj, int id);
extern "C" unsigned char func_0207d8cc(int index);
extern "C" short func_0207d470(void* base, unsigned int index);
extern "C" int func_02054fe4(unsigned char* obj);
struct Slots02083960;
extern "C" int func_02084268(struct Slots02083960* s);
struct S_a0b8c;
extern "C" int func_020a2904(struct S_a0b8c* p);

// JPN: func_ov003_02178d64
extern "C" ARM int func_ov003_02178d64(char* obj) {
    int result = 0;
    GameState* battle = GameState::GetInstance();
    void* ptr = func_02010684(battle);
    short val = *(short*)(obj + 0xf7c + 0xc);
    void* field89c = *(void**)(obj + 0x818);

    if (val == 0x77) {
        short id = func_02080fa4(field89c, 0x1d);
        short idx = (short)(*(short*)(obj + 0xf7c + 0x12) - id);
        unsigned char tableVal = func_0207d8cc(idx);
        result = func_0207d470((char*)ptr + 0x1d4, tableVal);
    } else {
        signed char field43 = *(signed char*)(obj + 0xf7c + 0x43);
        int flag = result;
        if (field43 >= 0) {
            flag = (field43 <= 3) ? 1 : 0;
        }
        if (flag) {
            GameObject* combatant = battle->GetPartyMemberByIndex(field43);
            if (combatant != 0) {
                int f150 = func_02054fe4((unsigned char*)combatant);
                result = (short)func_02084268((struct Slots02083960*)f150);
            }
        } else {
            result = func_020a2904((struct S_a0b8c*)ptr);
        }
    }
    return result;
}

#endif
