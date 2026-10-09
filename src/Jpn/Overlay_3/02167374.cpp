#if defined(jpn)
#include <globaldefs.h>

struct Obj0207fc6c;
extern "C" void func_020807a8(struct Obj0207fc6c* obj, int arg);

struct Obj02167374 {
    char pad0[0x10];
    void* field10;
    char pad14[0x38 - 0x14];
    int field68;
    int field6c;
    char pad70[0x44 - 0x40];
    unsigned char field74;
};

// JPN: func_ov003_02167374  (semantic: UpdateHwRegsFromCounter_02167374)
extern "C" ARM void func_ov003_02167374(struct Obj02167374* obj, int arg) {
    if (obj->field74 == 0 || obj->field10 == 0) return;

    if (arg == 0) arg = 1;
    func_020807a8((struct Obj0207fc6c*)obj->field10, arg);

    *(volatile int*)0x4001010 = 0;

    obj->field68 -= arg << 11;
    obj->field6c += arg << 11;

    if (obj->field68 < -0x100000) {
        obj->field68 += 0x100000;
    }
    if (obj->field6c > 0x100000) {
        obj->field6c -= 0x100000;
    }

    int mask = 0x1ff;
    int shiftedField6c = obj->field6c >> 12;
    int maskHi = mask << 16;
    int hi = maskHi & (shiftedField6c << 16);
    int lo = mask & (obj->field68 >> 12);
    *(volatile int*)0x4001014 = lo | hi;
}

#endif
