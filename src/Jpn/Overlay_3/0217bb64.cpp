#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct6_0217dc94;
extern "C" void func_ov003_0217c918(Struct6_0217dc94* obj);
extern "C" int func_0205e410(void* p, int val);

struct Block10Words0217bb64 { unsigned int w[10]; };
extern struct Block10Words0217bb64 data_ov003_0217e438;
struct Pair0217bb64 { unsigned int a; unsigned int b; };
extern struct Pair0217bb64 data_020e7604;
struct DispatchEntry0217bb64 { unsigned int fn; unsigned int locator; };

struct Obj0217bb64 {
    char pad0[4];
    signed char field4;
    char pad1[8 - 5];
    unsigned short field8;
    char pad2[0x10 - 0xa];
    int field14;
    char pad3[0x8c - 0x14];
    void* field90;
};

// JPN: func_ov003_0217bb64
extern "C" ARM int func_ov003_0217bb64(struct Obj0217bb64* obj) {
    GameState* bs = GameState::GetInstance();
    func_ov003_0217c918((struct Struct6_0217dc94*)obj);
    if (obj->field8 & 1) return 1;

    unsigned int scaleCount = bs->GetTickCount();
    if (obj->field90 != 0) {
        obj->field14 = func_0205e410(obj->field90, scaleCount);
    }

    struct Block10Words0217bb64 buf;
    buf = data_ov003_0217e438;
    struct Pair0217bb64* pr = &data_020e7604;
    unsigned int tmp1 = pr->b;
    unsigned int tmp0 = pr->a;
    ((struct DispatchEntry0217bb64*)&buf)[4].locator = tmp1;
    ((struct DispatchEntry0217bb64*)&buf)[4].fn = tmp0;

    signed char idx = obj->field4;
    struct DispatchEntry0217bb64* entries = (struct DispatchEntry0217bb64*)&buf;
    if (entries[idx].fn == 0) return 0;
    struct DispatchEntry0217bb64* d = &entries[idx];
    void* base = (char*)obj + ((int)d->locator >> 1);
    void (*callback)(void*);
    if (d->locator & 1) {
        callback = (void(*)(void*))(*(void**)((char*)*(void**)base + d->fn));
    } else {
        callback = (void(*)(void*))d->fn;
    }
    callback(base);
    return 1;
}

#endif
