#if defined(jpn)
#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_020d1b0c(int mode);
extern "C" int func_020d21a0();
extern "C" void func_020d1b1c(int value);
extern "C" void func_020767c0(void* obj);
int GetCardReadManagerSharedStatus();
extern "C" int func_020d2300();
extern "C" void func_020d20b8(const void* src, int offset, unsigned int length, void (*proc)(void*), int a4, int a5, int a6, int a7, int a8);

struct Flag02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
    void* base;
};

extern struct Flag02108dfc data_02108d40;
extern unsigned char data_020f0e90;

// JPN: func_020769e8
extern "C" ARM int func_020769e8(int offset, void* src, unsigned int length, int arg3) {
    int result;
    int isOne;
    int isTwo;
    int isThree;

    if (data_02108d40.base != 0) {
        if (offset >= 0x8000) {
            offset -= 0x8000;
        }
        VectorizedInvertedMemcpy(src, (void*)((unsigned char*)data_02108d40.base + offset), length);
        return 1;
    }

    if (data_020f0e90 == 0) {
        return 0;
    }

    data_02108d40.flag = 0;
    result = 1;
    func_020d1b0c((int)data_02108d40.value);

    isOne = (func_020d21a0() & 0xff) == 1;
    if (isOne) {
        func_020d20b8(src, offset, length, func_020767c0, 0, 1, 8, 10, 2);
    } else {
        isTwo = (func_020d21a0() & 0xff) == 2;
        if (isTwo) {
            func_020d20b8(src, offset, length, func_020767c0, 0, 1, 7, 10, 2);
        } else {
            isThree = (func_020d21a0() & 0xff) == 3;
            if (isThree) {
                func_020d20b8(src, offset, length, func_020767c0, 0, 1, 8, 10, 2);
            }
        }
    }

    if (arg3 != 0) {
        if (GetCardReadManagerSharedStatus() != 0) {
            result = 0;
        }
    } else {
        func_020d2300();
        if (GetCardReadManagerSharedStatus() != 0) {
            result = 0;
        }
        func_020d1b1c((int)data_02108d40.value);
        data_02108d40.flag = 1;
    }

    return result;
}

#endif
