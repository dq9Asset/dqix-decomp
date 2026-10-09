#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov003_0215ef68(void* obj);

struct Obj0215e27c;
extern "C" int func_ov003_0215f554(struct Obj0215e27c* obj, int amount);

struct Self0215e3fc;
extern "C" void func_ov003_0215f6d4(struct Self0215e3fc* self);

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* func_0205ebd8(struct Struct_0205d81c* s);
extern "C" int func_0204d5e8(unsigned char* obj);
extern "C" void func_0205cf84(void* obj, int value);
extern "C" int func_0205e410(void* p, int val);

typedef void (*DispatchFn_0217fe94)(void*, int);
struct DispatchEntry_0217fe94 {
    DispatchFn_0217fe94 fn;
    int flags;
};
extern struct DispatchEntry_0217fe94 data_ov003_0217e6ac[];

// JPN: func_ov003_0215dc40
extern "C" ARM int func_ov003_0215dc40(unsigned char* self, int amount) {
    if (self[0x3d4] == 5) {
        return 1;
    }

    func_ov003_0215ef68(self);

    if (func_ov003_0215f554((struct Obj0215e27c*)self, amount) != 0) {
        return 0;
    }

    if (self[0x40c] != 0 && self[0x40d] == 0) {
        func_ov003_0215f6d4((struct Self0215e3fc*)self);
        return 0;
    }

    if (self[0x3d4] != 0) {
        struct Elem_0205d81c* elem = func_0205ebd8((struct Struct_0205d81c*)(self + 0xb0));
        if (elem != 0 && func_0204d5e8((unsigned char*)elem) != 0 && (*((unsigned char*)elem + 0xc5) & 2) == 0) {
            func_0205cf84(self + 0xb4, -1);
        }
        self[0x3d2] = (unsigned char)func_0205e410(self + 0xb0, amount);
    }

    unsigned char idx = self[0x3d4];
    if (data_ov003_0217e6ac[idx].fn != 0) {
        struct DispatchEntry_0217fe94* entry = &data_ov003_0217e6ac[idx];
        void* obj = self + (entry->flags >> 1);
        DispatchFn_0217fe94 fn;
        if (entry->flags & 1) {
            fn = *(DispatchFn_0217fe94*)(*(int*)obj + (int)*(DispatchFn_0217fe94 volatile*)&entry->fn);
        } else {
            fn = *(DispatchFn_0217fe94 volatile*)&entry->fn;
        }
        fn(obj, amount);
    }
    return 0;
}

#endif
