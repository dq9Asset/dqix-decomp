#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Elem_0205d81c {
    char pad0[0xac];
    short posX;
    short posY;
};

struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* func_0205ebd8(struct Struct_0205d81c* s);
extern "C" int func_0204d5fc(unsigned char* obj);

struct Struct_0205c570;
extern "C" int func_0205eaa8(struct Struct_0205c570* s);

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void func_0205b6e8(struct Container0205a3d0* c, int key);
extern "C" struct Elem0205a3d0* func_0205b76c(struct Container0205a3d0* c, int key);
extern "C" void func_020e438c(struct Container0205a3d0* c, int key, short a, short b);

struct Container0205a330;
extern "C" void func_0205b6a8(struct Container0205a330* c, int arg);

extern "C" void func_0205c228(void* obj);

// JPN: func_ov003_0216d688
extern "C" ARM void func_ov003_0216d688(char* obj) {
    GameState* battle = GameState::GetInstance();
    struct Elem_0205d81c* elem = func_0205ebd8(*(struct Struct_0205d81c**)(obj + 0x1000 + 0x150));
    if (elem != 0 && func_0204d5fc((unsigned char*)elem) != 0) {
        short y = elem->posY << 3;
        short x = elem->posX;
        short sum = func_0205eaa8(*(struct Struct_0205c570**)(obj + 0x1000 + 0x150));
        short row = y + sum * 12;
        struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + 0x138);
        if (cont == 0) return;
        func_0205b6e8(cont, 0);
        struct Elem0205a3d0* e = func_0205b76c(cont, 0);
        if (e != 0) {
            *(unsigned char*)((char*)e + 0x15) |= 8;
        }
        func_0205b6a8((struct Container0205a330*)cont, battle->GetTickCount());
        func_020e438c(cont, 0, (short)(x * 8) - 4, row + 2);
        func_0205c228(obj + 0x10fc);
        return;
    }

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + 0x138);
    if (cont == 0) return;
    struct Elem0205a3d0* e = func_0205b76c(cont, 0);
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}

#endif
