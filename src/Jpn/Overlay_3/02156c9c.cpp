#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct IntField0x23c_020a27c4;
extern "C" int func_0200ff54(char* obj);
extern "C" int func_020a453c(struct IntField0x23c_020a27c4* obj);
extern "C" int func_020121c0(unsigned short* obj, int mask);
extern "C" int func_ov003_021567c4(void* obj);
extern "C" int func_ov003_021568f0(void* self);

struct Obj0205eaa0;
extern "C" void func_0205fd8c(struct Obj0205eaa0* obj, int a, int b);

struct Obj2081;
extern "C" void func_02080908(struct Obj2081* obj, int key);

struct Obj0208203c;
extern "C" void func_02082978(struct Obj0208203c* obj);

struct Obj020e25e8;
extern "C" void func_020e4188(struct Obj020e25e8* obj);

extern unsigned short data_02114ad0;
extern struct Obj0205eaa0 data_021086a4;

// JPN: func_ov003_02156c9c
extern "C" ARM int func_ov003_02156c9c(char* obj) {
    *(void**)(obj + 8) = obj + 0x1e6;
    int result = 0;
    int flagB = result;

    GameState* battle = GameState::GetInstance();
    struct IntField0x23c_020a27c4* p = (struct IntField0x23c_020a27c4*)func_0200ff54((char*)battle);
    if (p != 0 && ((*((unsigned char*)p + 0x244) & 2) != 0 || func_020a453c(p) == 0)) {
        flagB = (func_020121c0(&data_02114ad0, 0x200) != 0) ? 1 : 0;
    }

    if (func_ov003_021567c4(obj) != 0 || flagB != 0) {
        func_0205fd8c(&data_021086a4, 1, 0);
        result = -1;
        if (*(short*)(obj + 0x1e6) == 6) {
            result = 1;
        }
    } else {
        if (func_ov003_021568f0(obj) != 0) {
            result = -1;
        }
    }

    if (result != 0) {
        func_02080908(*(struct Obj2081**)(obj + 0x18), *(short*)(obj + 0x1e2));
        func_02082978((struct Obj0208203c*)(obj + 0x80));
        *(void**)(obj + 8) = 0;
    }

    if (*(void**)(obj + 0x1c) != 0 && result != 0) {
        func_020e4188(*(struct Obj020e25e8**)(obj + 0x1c));
    }

    return result;
}

#endif
