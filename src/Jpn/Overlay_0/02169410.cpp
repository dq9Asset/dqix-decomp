#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_0200f9e8(int* obj);
extern "C" int func_ov000_0216029c(struct Random* rand, short* buf, int count, int flag);
extern "C" int func_0204a1c4(unsigned char* obj);
extern "C" void func_0204a1b0(unsigned char* obj, unsigned char value);
extern "C" void func_0204a9f4(unsigned char* obj, int* src);
extern "C" void func_0204aa80(unsigned char* obj, int* src);
extern "C" void __clear(void* dst, int count);

struct Vec2_0216f74c { int x; int y; };
extern "C" struct Vec2_0216f74c func_ov000_02170e78(int* in);

extern unsigned char data_ov000_021841c4[][8];
struct Words3_02169410 { unsigned int v[3]; };
extern struct Words3_02169410 data_ov000_02184178;

// JPN: func_ov000_02169410  (semantic: AssignFormationPositions_02169410)
extern "C" ARM void func_ov000_02169410(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    func_0200f9e8((int*)battle);
    struct Random* rand = *(struct Random**)(obj + 0x218);
    short ids[8];
    int count = func_ov000_0216029c(rand, ids, 8, 0);
    int i = 0;
    while (i < count) {
        GameObject* c = battle->GetCombatantByIndex(ids[i]);
        if (c != 0) {
            int tmp = data_ov000_021841c4[count - 1][i];
            if (func_0204a1c4((unsigned char*)c) != 0xff) {
                tmp = func_0204a1c4((unsigned char*)c);
            }
            struct Vec2_0216f74c pos = func_ov000_02170e78(&tmp);
            struct Words3_02169410 fields = data_ov000_02184178;
            fields.v[0] = pos.x;
            fields.v[2] = pos.y;
            int zeroBuf[3];
            __clear(zeroBuf, 0xc);
            func_0204a1b0((unsigned char*)c, (unsigned char)(tmp & 0xff));
            func_0204a9f4((unsigned char*)c, (int*)&fields);
            func_0204aa80((unsigned char*)c, zeroBuf);
        }
        i++;
    }
}

#endif
