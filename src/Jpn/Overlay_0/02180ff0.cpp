#if defined(jpn)
#include <globaldefs.h>

// JPN: func_ov000_02180ff0  (semantic: ClearField24Bit0_02180ff0)
extern "C" ARM void func_ov000_02180ff0(void* obj, int id) {
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            signed char j = *((signed char*)obj + i + 0x6c);
            void* e = (char*)obj + 0x158 + 0x800 + j * 0x488;
            if (*(int*)((char*)e + 0x4c) >= 0) {
                unsigned char v = *((unsigned char*)e + 0x24);
                v &= ~1;
                *((unsigned char*)e + 0x24) = v;
            }
        }
        return;
    }
    int i;
    for (i = 0; i < 4; i++) {
        signed char j = *((signed char*)obj + i + 0x6c);
        void* e = (char*)obj + 0x158 + 0x800 + j * 0x488;
        if (id == *(int*)((char*)e + 0x4c)) {
            unsigned char v = *((unsigned char*)e + 0x24);
            v &= ~1;
            *((unsigned char*)e + 0x24) = v;
            return;
        }
    }
}

#endif
