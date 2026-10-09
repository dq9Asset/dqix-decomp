#if defined(jpn)
#include <globaldefs.h>

struct SearchStruct0202c1a4;
extern "C" int func_0202bd54(struct SearchStruct0202c1a4*);
extern "C" void* func_0205ff20(void);
extern "C" void func_020105d0(char* obj, int v);
extern "C" void func_02010604(char* obj, int v);
extern "C" void func_02010638(char* base, int val);
extern "C" void func_0206f1d4(char* base, int index);
extern "C" void func_0206f224(char* base, int index);
extern "C" void func_0206f0c0(void* unused, unsigned char* array, int bit, int value);

struct Obj021ce174 {
    char pad0[4];
    unsigned char caseSel : 7;
    unsigned char flag7 : 1;
    short val6;
    unsigned short bit8;
};

// JPN: func_ov017_021ce61c
extern "C" ARM void func_ov017_021ce61c(void* unused, struct Obj021ce174* obj, char* target, int unused2, struct SearchStruct0202c1a4* search) {
    if (!obj->flag7) {
        if (func_0202bd54(search) == 0) {
            return;
        }
    }

    unsigned char* base = (unsigned char*)func_0205ff20();

    switch (obj->caseSel) {
    case 0:
        func_020105d0(target, obj->val6);
        func_02010604(target, 1);
        func_02010638(target, 1);
        func_0206f1d4((char*)base, base[0x332]);
        break;
    case 1:
        func_02010604(target, obj->val6);
        func_02010638(target, 1);
        func_0206f224((char*)base, base[0x332]);
        break;
    case 2:
        func_02010638(target, obj->val6);
        break;
    case 3:
        func_0206f0c0(base, base + 0x8c, obj->bit8, obj->val6);
        break;
    case 4:
        func_0206f0c0(base, base + base[0x332] * 0x1c + 0x3, obj->bit8, obj->val6);
        break;
    case 5:
        func_0206f0c0(base, base + base[0x332] * 0x1c + 0x10, obj->bit8, obj->val6);
        break;
    default:
        break;
    }
}

#endif
