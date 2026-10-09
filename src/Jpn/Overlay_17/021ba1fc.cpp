#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct BattleStruct021b9d00;

struct S_020103b4;
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(struct S_020103b4* obj);

struct Struct02030b7c { int field0; void* field4; };
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

extern "C" int func_ov017_021ba0c8(int a, void* b);

struct Data021b9d00_8438 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
    unsigned char pad8[8];
    int field10;
};
extern struct Data021b9d00_8438 data_ov017_021d8cf8;

struct Data021b9d00_7c54 { signed char byte0; signed char byte1; };
extern struct Data021b9d00_7c54 data_ov017_021d8430;

// JPN: func_ov017_021ba1fc
extern "C" ARM int func_ov017_021ba1fc(struct Variant02030b0c* v, int idx) {
    if (data_ov017_021d8cf8.field10 != 0) return 1;
    if (data_ov017_021d8cf8.byte0 != 0) return 1;
    if (data_ov017_021d8430.byte0 > -1) return 1;
    if (data_ov017_021d8cf8.byte1 != 0) return 1;
    if (data_ov017_021d8430.byte1 > -1) return 1;

    GameState::GetInstance();
    int a = _ZNK6Script9Parameter5ToIntEv(v);
    struct Variant02030b0c* vn = (struct Variant02030b0c*)((char*)v + 8);
    v = (struct Variant02030b0c*)((char*)v + 16);
    int b = _ZNK6Script9Parameter5ToIntEv(vn);
    if (a >= 0 && (data_ov017_021d8cf8.field4 < a || b < data_ov017_021d8cf8.field4)) return 1;

    if (idx >= 5) {
        int c = _ZNK6Script9Parameter5ToIntEv(v);
        v = (struct Variant02030b0c*)((char*)v + 8);
        if (c != 0) {
            if (_ZNK9GameState21IsMorningDayOrEveningEv((struct S_020103b4*)GameState::GetInstance())) return 1;
            data_ov017_021d8cf8.byte2 = 1;
        }
    } else {
        if (data_ov017_021d8cf8.byte2 != 0) return 1;
    }

    int d = _ZNK6Script9Parameter5ToIntEv(v);
    void* e = _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)((char*)v + 8));
    if (e == 0) return 0;
    func_ov017_021ba0c8(d, e);
    return 1;
}

#endif
