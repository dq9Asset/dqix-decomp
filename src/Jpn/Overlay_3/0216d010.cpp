#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_02042940();
extern "C" void func_02043d7c(void* obj, int count);
extern "C" void func_02044168(void* obj, int flag);

struct Obj0205d2bc;
extern "C" void func_0205e5ec(Obj0205d2bc* obj);

extern "C" void func_ov003_0216fb18(void* obj);
extern "C" void func_ov003_0215dd84(void* obj);
extern "C" void func_ov003_021730dc(void* obj);

struct S0216d010 {
    char pad0[4];
    short field4;
    short field6;
    char pad1[0x1150 - 0x8];
    void* field12c0;
};

// JPN: func_ov003_0216d010  (semantic: DispatchStateByField4And6_0216d010)
extern "C" ARM void func_ov003_0216d010(S0216d010* obj) {
    int g = func_02042940();
    func_02043d7c((void*)g, 2);
    func_02044168((void*)g, 0);

    void* p = obj->field12c0;
    if (p) {
        if (obj->field6 == 0 || obj->field6 == 1 || obj->field4 == 2) {
            func_0205e5ec((Obj0205d2bc*)p);
        }
    }

    if (obj->field4 == 4) {
        if (obj->field6 > 0) {
            func_ov003_0216fb18((char*)obj + 0x428);
            return;
        }
    }
    if (obj->field4 == 3) {
        if (obj->field6 == 1) {
            func_ov003_0215dd84((char*)obj + 0x14);
        }
        return;
    }
    if (obj->field4 == 5 && obj->field6 == 6) {
        func_ov003_021730dc((char*)obj + 0xda0);
    }
    return;
}

#endif
