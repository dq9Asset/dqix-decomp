#if defined(jpn)
#include <globaldefs.h>

struct Struct4ec_021682c0 { char pad[0x4d8]; void* field4dc; char pad2[0xc]; unsigned char field4ec; char pad3[0xb2]; unsigned char field59f; };

extern "C" ARM void func_ov003_021692e0(void* obj, int id);
extern "C" ARM void func_ov003_02168464(void* obj);
extern "C" ARM void func_ov003_0216a95c(void* obj);
extern "C" void func_ov003_021684dc(void* obj);
extern "C" void func_ov003_021689d4(void* obj);
extern "C" ARM void func_ov003_02168b48(void* obj);
extern "C" void func_ov003_02168bbc(void* obj, void* arg, int val);
extern "C" ARM void func_ov003_0216925c(void* obj);
extern "C" void func_ov003_0216a62c(void* obj);

// JPN: func_ov003_021682c0  (semantic: UpdateStateAndDispatch_021682c0)
extern "C" ARM int func_ov003_021682c0(struct Struct4ec_021682c0* obj, void* arg) {
    obj->field4dc = arg;
    unsigned char state = obj->field4ec;
    if (state != 0 && state != 3 && state != 4) {
        unsigned char flags = obj->field59f;
        if (!(flags & 2) || (flags & 4)) {
            func_ov003_021692e0(obj, (int)arg);
        }
    }
    if (obj->field4ec != 0) {
        func_ov003_02168464(obj);
    }
    unsigned char flags2 = obj->field59f;
    if ((flags2 & 2) && !(flags2 & 4)) {
        func_ov003_0216a95c(obj);
        return obj->field4ec == 6;
    }
    switch (obj->field4ec) {
        case 0: func_ov003_021684dc(obj); break;
        case 1: func_ov003_021689d4(obj); break;
        case 2: func_ov003_02168b48(obj); break;
        case 3: func_ov003_02168bbc(obj, arg, 0x3f2); break;
        case 4: func_ov003_02168bbc(obj, arg, 0x3fc); break;
        case 5: func_ov003_0216925c(obj); break;
        case 6: return 1;
        default: break;
    }
    func_ov003_0216a62c(obj);
    return 0;
}

#endif
