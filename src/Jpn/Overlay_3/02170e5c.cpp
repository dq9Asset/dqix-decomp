#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;
extern "C" void* func_0202a9d0(void);
extern "C" void* func_0202a9dc(void);
extern "C" int func_0202c104(struct SearchStruct*, int);
extern "C" void func_0202bdcc(struct SearchStruct*, int);
extern "C" void func_0202aca4(void*);

struct Element0202bad4;
struct ElementArray0202bad4;
extern "C" Element0202bad4* func_0202b684(struct ElementArray0202bad4*, int);

extern "C" void func_ov003_021710d8(void*, void*);
extern "C" int func_0205f774(void*);

struct Obj02170e5c {
    unsigned char field0;
    char pad1[0x199 - 1];
    unsigned char field199;
    char pad2[0x618 - 0x19a];
    int field71c;
    int field720;
    char pad3[0x628 - 0x620];
    unsigned int field72c;
};

// JPN: func_ov003_02170e5c  (semantic: AdvanceSearchTimerAndDispatch_02170e5c)
extern "C" ARM void func_ov003_02170e5c(struct Obj02170e5c* obj) {
    GameState* battle = GameState::GetInstance();
    struct SearchStruct* searchPtr = (struct SearchStruct*)func_0202a9d0();
    void* ptr2 = func_0202a9dc();

    if (func_0202c104(searchPtr, obj->field199)) {
        func_0202bdcc(searchPtr, obj->field199);
    }
    obj->field72c += battle->GetEffectiveDeltaTime();
    if (obj->field72c > 0xbb8) {
        func_0202aca4(searchPtr);
        obj->field0 = 0;
        return;
    }
    if (func_0202c104(searchPtr, 0) && obj->field71c == 0) {
        func_0202b684((struct ElementArray0202bad4*)searchPtr, obj->field199);
        func_0202aca4(searchPtr);
        obj->field0 = 0;
        return;
    }
    if (obj->field720 != 0 && obj->field71c != 0) {
        struct Element0202bad4* elem = func_0202b684((struct ElementArray0202bad4*)searchPtr, obj->field199);
        func_ov003_021710d8(obj, (char*)elem + 0x68);
        func_0202aca4(searchPtr);
        obj->field0 = 0;
    }
    if (func_0205f774(ptr2) != 0) {
        obj->field720 = 1;
    }
}

#endif
