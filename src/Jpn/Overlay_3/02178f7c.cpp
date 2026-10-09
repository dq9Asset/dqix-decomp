#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov003_02178e20(void* obj);
extern "C" void func_ov003_02176d60(void* obj);
extern "C" void func_ov003_021759f8(void* obj);

// JPN: func_ov003_02178f7c
extern "C" ARM void func_ov003_02178f7c(void* p) {
    char* obj = (char*)p;
    int flags = *(int*)(obj + 0xf60);
    int delta = 0;
    if (flags & 0x10) {
        delta = 1;
    } else if (flags & 0x20) {
        delta -= 1;
    }

    *(short*)(obj + 0xf7c + 0x14) = *(short*)(obj + 0xf7c + 0x14) + delta;
    if (*(short*)(obj + 0xf7c + 0x16) <= *(short*)(obj + 0xf7c + 0x14)) {
        *(short*)(obj + 0xf7c + 0x14) = 0;
    }
    if (*(short*)(obj + 0xf7c + 0x14) < 0) {
        *(short*)(obj + 0xf7c + 0x14) = *(short*)(obj + 0xf7c + 0x16) - 1;
    }

    if (delta != 0) {
        func_ov003_02178e20(obj);
        func_ov003_02176d60(obj);
        if (*(short*)(obj + 0xf7c + 0xc) == 0x77) {
            func_ov003_021759f8(obj);
        }
    }
    func_ov003_02178e20(obj);

    if (*(short*)(obj + 0xf7c) == **(short**)(obj + 0xf74)) return;
    func_ov003_02176d60(obj);
    if (*(short*)(obj + 0xf7c + 0xc) != 0x77) return;
    func_ov003_021759f8(obj);
}

#endif
