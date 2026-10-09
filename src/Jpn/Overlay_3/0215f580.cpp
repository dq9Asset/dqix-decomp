#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" Elem_0205d81c* func_0205ebd8(Struct_0205d81c*);
extern "C" int func_0204d5fc(unsigned char*);
extern "C" int func_02042940(void);

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void func_0205b6e8(Container0205a3d0*, int);
extern "C" Elem0205a3d0* func_0205b76c(Container0205a3d0*, int);

struct Container0205a330;
extern "C" void func_0205b6a8(Container0205a330*, int);

extern "C" void func_0205b7c8(Container0205a3d0*, int, int);
extern "C" void func_0205c228(void*);

// JPN: func_ov003_0215f580
extern "C" ARM void func_ov003_0215f580(char* base) {
    if (*(unsigned char*)(base + 0x3da) == 0) return;

    Elem_0205d81c* elem = func_0205ebd8((Struct_0205d81c*)(base + 0xb0));
    if (elem == NULL) return;
    if (*(unsigned char*)((char*)elem + 0xc4) != 1) return;
    if (!func_0204d5fc((unsigned char*)elem)) return;
    if (*(unsigned char*)((char*)elem + 0xc5) & 0x20) return;

    short a = *(short*)((char*)elem + 0xac);
    short b = *(short*)((char*)elem + 0xae);
    short d = *(short*)((char*)elem + 0xbc);
    short e = *(short*)((char*)elem + 0xbe);

    short x = (short)(d + (short)((a << 3)));
    short y = (short)(e + (short)((b << 3)));
    x = (short)(x - 8);
    y = (short)(y - 2);

    if (*(unsigned char*)(base + 0x40a) != 0) {
        int f = func_02042940();
        int v = *(short*)((char*)f + 0x700 + 0xe6);
        x = (short)(x - 2);
        y = (short)(y + (short)(v % 8));
    }

    GameState* battleStruct = GameState::GetInstance();
    Container0205a3d0* cont = *(Container0205a3d0**)(base + 0x3ac);
    if (cont == NULL) return;

    func_0205b6e8(cont, 0);
    Elem0205a3d0* entry = func_0205b76c(cont, 0);
    if (entry != NULL) {
        *(unsigned char*)((char*)entry + 0x15) |= 8;
    }

    int scaleCount = (int)battleStruct->GetTickCount();
    func_0205b6a8((Container0205a330*)cont, scaleCount);

    entry = func_0205b76c(cont, 0);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x4) = x;
        *(short*)((char*)entry + 0x6) = y;
    }

    func_0205b7c8(cont, 0, 0x3f);
    func_0205c228(base + 0x370);
}

#endif
