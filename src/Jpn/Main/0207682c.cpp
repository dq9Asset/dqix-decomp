#if defined(jpn)
#include <globaldefs.h>
#include "System/Memory.h"

struct Flag02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
    char* field4;
};

extern struct Flag02108dfc data_02108d40;
extern unsigned char data_020f0e90;

extern "C" void func_020d1b0c(int mode);
extern "C" int func_020d21a0();
extern "C" void func_020d1b1c(int value);
int GetCardReadManagerSharedStatus();
extern "C" int func_020d2300();
extern "C" void func_020767bc(void* obj);
extern "C" void func_020d20b8(int a, int b, int c, void* d, int e, int f, int g, int h, int i);

// JPN: func_0207682c
extern "C" ARM int func_0207682c(int a1, int a2, int a3, int a4) {
    if (data_02108d40.field4) {
        if (a1 >= 0x8000) {
            a1 -= 0x8000;
        }
        VectorizedInvertedMemcpy(data_02108d40.field4 + a1, (void*)a2, (unsigned int)a3);
        return 1;
    }

    if (data_020f0e90 == 0) {
        return 0;
    }

    data_02108d40.flag = 0;
    int result = 1;
    func_020d1b0c((int)data_02108d40.value);

    int b = ((func_020d21a0() & 0xff) == 1);
    if (b) {
        func_020d20b8(a1, a2, a3, func_020767bc, 0, 1, 6, 1, 0);
    } else {
        b = ((func_020d21a0() & 0xff) == 2);
        if (b) {
            func_020d20b8(a1, a2, a3, func_020767bc, 0, 1, 6, 1, 0);
        } else {
            b = ((func_020d21a0() & 0xff) == 3);
            if (b) {
                func_020d20b8(a1, a2, a3, func_020767bc, 0, 1, 6, 1, 0);
            }
        }
    }

    if (a4) {
        if (GetCardReadManagerSharedStatus()) {
            result = 0;
        }
    } else {
        func_020d2300();
        if (GetCardReadManagerSharedStatus()) {
            result = 0;
        }
        func_020d1b1c((int)data_02108d40.value);
        data_02108d40.flag = 1;
    }

    return result;
}

#endif
