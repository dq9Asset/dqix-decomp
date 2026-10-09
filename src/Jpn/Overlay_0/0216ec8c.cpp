#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"


struct Flags0202ecfc;
extern "C" void func_0202e86c(struct Flags0202ecfc* p);
extern "C" short _Z8fix32sini(int x);
extern "C" short _Z8fix32cosi(int x);

struct Block0202ecc8 { unsigned int v[12]; };
struct Dst0202ecc8;
extern "C" void func_0202e838(struct Dst0202ecc8* dst, struct Block0202ecc8* src);

extern "C" void func_ov000_0216e960(void* a, void* b, void* c);

struct Field44_0216ec8c { unsigned int v[3]; };
struct Field50_0216ec8c { int x, y, z; };
struct Table_0216ec8c { int x, y, z; };

struct Obj0216ec8c {
    char pad[0x224];
    int field224;
};

// JPN: func_ov000_0216ec8c  (semantic: SomeFunc_0216ec8c)
extern "C" ARM void func_ov000_0216ec8c(struct Obj0216ec8c* obj, int id) {
    GameObject* c = GameState::GetInstance()->GetGameObjectByIndex(id);
    if (!c) {
        obj->field224 = -1;
        func_0202e86c((struct Flags0202ecfc*)obj);
    } else {
        struct Field44_0216ec8c fieldA = *(struct Field44_0216ec8c*)((char*)c + 0x44);
        struct Field50_0216ec8c fieldB = *(struct Field50_0216ec8c*)((char*)c + 0x50);
        struct Table_0216ec8c tbl;
        struct Block0202ecc8 block;
        tbl.x = _Z8fix32sini(fieldB.y);
        tbl.y = 0;
        tbl.z = _Z8fix32cosi(fieldB.y);
        func_ov000_0216e960(&tbl, &fieldA, &block);
        func_0202e838((struct Dst0202ecc8*)obj, &block);
    }
}

#endif
