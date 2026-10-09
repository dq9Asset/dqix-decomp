#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameResources* func_ov017_0218c1d0(void);

extern "C" void* func_ov017_021b8978(void* obj);
extern "C" void func_ov000_02169a28(void* p);
extern "C" void func_ov017_021d0fe0(int a, int b, int c);
extern "C" void func_ov017_021b1258(void* obj);
extern "C" int func_ov017_021b11e4(void);
extern "C" int func_02047928(void** obj);

struct Ctx021b08f4 {
    char pad0[0x9];
    unsigned char byte9;
    char pad1[0x26 - 0xa];
    unsigned char byte26;
    unsigned char byte27;
    char pad2[0x2c - 0x28];
    unsigned char byte2c;
    char pad3[0x34 - 0x2d];
    int field34;
};

// JPN: func_ov017_021b0f8c
extern "C" ARM unsigned char func_ov017_021b0f8c(Ctx021b08f4* obj) {
    GameState::GetInstance();
    int ctx = ((int)func_ov017_0218c1d0());
    char* base = (char*)ctx + 0x3000;
    void* p718 = *(void**)(base + 0x508);
    void* p700 = *(void**)(base + 0x4f0);
    if (*((unsigned char*)p718 + 0x2) != 0) {
        void* f6ac = func_ov017_021b8978(p718);
        if (f6ac != 0) {
            func_ov000_02169a28(f6ac);
        }
    }

    if (obj->byte9 == 0) {
        if (obj->byte26 == 0) {
            func_ov017_021d0fe0(5, 0, 0);
            if (((int (*)(void*))func_ov017_021b11e4)(obj) != 0) {
                obj->byte26 = obj->byte26 + 1;
            } else {
                obj->byte26 = 2;
            }
        } else if (obj->byte26 == 1) {
            if (func_02047928((void**)p700) != 0) {
                obj->byte26 = obj->byte26 + 1;
            }
        } else if (obj->byte26 == 2) {
            if ((obj->byte27 & 0x10) != 0) {
                func_ov017_021b1258(obj);
                func_ov017_021d0fe0(7, 0, 0);
                obj->byte26 = obj->byte26 + 1;
            }
        }
    } else {
        if (obj->byte26 == 0) {
            if (obj->field34 != 0) {
                if (((int (*)(void*))func_ov017_021b11e4)(obj) != 0) {
                    obj->byte26 = obj->byte26 + 1;
                } else {
                    func_ov017_021d0fe0(6, 0, 0);
                    obj->byte26 = 2;
                }
            }
        } else if (obj->byte26 == 1) {
            if (func_02047928((void**)p700) != 0) {
                func_ov017_021d0fe0(6, 0, 0);
                obj->byte26 = obj->byte26 + 1;
            }
        } else if (obj->byte26 == 2 && obj->byte2c == 2) {
            func_ov017_021b1258(obj);
        }
    }

    return *((unsigned char*)obj + 0xa);
}

#endif
