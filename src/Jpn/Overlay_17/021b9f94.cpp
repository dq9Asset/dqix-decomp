#if defined(jpn)
#include <globaldefs.h>

extern "C" void* func_0202a9d0(void);
struct SearchStruct0202c1a4;
extern "C" signed char func_0202bd54(struct SearchStruct0202c1a4* obj);
extern "C" void func_0202be38(void* obj);
extern "C" void* func_0205ff20(void);
extern "C" int func_02065c9c(void* a, int mode, void* c);
extern "C" void func_020708dc(void* p);
struct Obj_021b994c;
extern "C" void func_ov017_021b9e48(struct Obj_021b994c* obj);

struct SearchStruct0202c1a4 {
    char pad[0x100d];
    unsigned char entryLimit;
};

struct Obj_021b994c {
    char pad[0x12c];
    unsigned int field12c;
    unsigned char field130;
    unsigned char field131;
    unsigned char field132;
    unsigned char field133;
    char pad2[0x136 - 0x134];
    unsigned char field136;
};

struct LocalBuf021b9a98 { char pad[0x34]; };

// JPN: func_ov017_021b9f94
extern "C" ARM void func_ov017_021b9f94(Obj_021b994c* obj, int unused1, unsigned char matchType, unsigned char unused2, unsigned short flag) {
    SearchStruct0202c1a4* search = (SearchStruct0202c1a4*)func_0202a9d0();
    signed char arrEntry = func_0202bd54(search);
    if (matchType != arrEntry && matchType != 4) return;

    if (obj->field130 == 0) return;

    func_0202be38(search);

    int cnt = obj->field131 + 1;
    obj->field131 = (unsigned char)cnt;
    if ((cnt & 0xff) >= search->entryLimit - 1) obj->field130 = 0;

    if (obj->field136 == 0) {
        if (flag == 0) {
            obj->field133 = 0;
            *(short*)((char*)obj + 0x134) = (short)obj->field12c;
            void* list = func_0205ff20();
            LocalBuf021b9a98 c;
            if (func_02065c9c(list, 0x1a, &c)) {
                func_020708dc(&c);
            }
            func_ov017_021b9e48(obj);
            obj->field136 = 1;
        } else {
            int cnt2 = obj->field132 + 1;
            obj->field132 = (unsigned char)cnt2;
            if ((cnt2 & 0xff) < search->entryLimit - 1) return;

            obj->field133 = 1;
            *(short*)((char*)obj + 0x134) = (short)obj->field12c;
            void* list2 = func_0205ff20();
            LocalBuf021b9a98 c2;
            if (func_02065c9c(list2, 0x1a, &c2)) {
                func_020708dc(&c2);
            }
            func_ov017_021b9e48(obj);
            obj->field136 = 1;
        }
    }
}

#endif
