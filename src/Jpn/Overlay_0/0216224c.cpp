#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov000_02175884(void* obj);
extern "C" void func_ov013_021882fc(void* obj);
struct Obj021d8c94;
extern "C" void func_ov023_021d9554(struct Obj021d8c94* obj);
extern "C" void func_ov023_021eb458(char* obj);
extern "C" void func_ov013_02185b20(void* obj);

// JPN: func_ov000_0216224c
extern "C" ARM void func_ov000_0216224c(char* obj) {
    if (*(int*)(obj + 0x5000 + 0x7e8) == 0) return;
    if (*(void**)(obj + 0x5000 + 0x7bc) != 0) {
        func_ov023_021eb458(*(char**)(obj + 0x5000 + 0x7bc));
    }
    if (*(void**)(obj + 0x5000 + 0x768) != 0) {
        func_ov013_02185b20(*(void**)(obj + 0x5000 + 0x768));
        if (*(void**)(obj + 0x5000 + 0x76c) == 0) return;
        func_ov013_021882fc(*(void**)(obj + 0x5000 + 0x76c));
        return;
    }
    if (*(struct Obj021d8c94**)(obj + 0x5000 + 0x778) != 0) {
        func_ov023_021d9554(*(struct Obj021d8c94**)(obj + 0x5000 + 0x778));
        return;
    }
    if (*(int*)(obj + 0x5000 + 0x7e4) & 0x40000) return;
    func_ov000_02175884(obj + 0x31c + 0x3400);
}

#endif
