#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_0205e410(void* p, int val);
extern "C" int func_ov023_021e2d10(void* obj);
extern unsigned char data_02114af4;

struct Block16Words0216d988 { unsigned int w[16]; };
extern struct Block16Words0216d988 data_ov003_0217e224;
struct Pair0216d988 { unsigned int a; unsigned int b; };
extern struct Pair0216d988 data_020e7604;
struct DispatchEntry0216d988 { unsigned int fn; unsigned int locator; };

struct Obj0216d988 {
    char pad0[1];
    signed char field1;
    char pad1[0xc - 2];
    short fieldC;
    short fieldE;
    char pad2[0x3c - 0x10];
    void* field3c;
    char pad3[0xd4 - 0x40];
    void* fieldD4;
};

// JPN: func_ov003_0216d988
extern "C" ARM int func_ov003_0216d988(struct Obj0216d988* obj) {
    unsigned int scaleCount = GameState::GetInstance()->GetTickCount();
    if (obj->field3c != 0) {
        func_0205e410(obj->field3c, scaleCount);
    }
    if (obj->fieldD4 != 0) {
        obj->fieldC = (short)func_ov023_021e2d10(obj->fieldD4);
        if (*(&data_02114af4 + 0x55) != 0) {
            obj->fieldE = obj->fieldC;
        } else {
            obj->fieldE = 0;
        }
    }

    struct Block16Words0216d988 buf;
    buf = data_ov003_0217e224;
    struct Pair0216d988* pr = &data_020e7604;
    unsigned int tmp1 = pr->b;
    unsigned int tmp0 = pr->a;
    ((struct DispatchEntry0216d988*)&buf)[7].locator = tmp1;
    ((struct DispatchEntry0216d988*)&buf)[7].fn = tmp0;

    signed char idx = obj->field1;
    struct DispatchEntry0216d988* entries = (struct DispatchEntry0216d988*)&buf;
    if (entries[idx].fn == 0) return 0;
    struct DispatchEntry0216d988* d = &entries[idx];
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
