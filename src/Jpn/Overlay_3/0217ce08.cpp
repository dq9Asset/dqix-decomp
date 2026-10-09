#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" Elem_0205d81c* func_0205ebd8(Struct_0205d81c*);

extern "C" int func_0204d5fc(unsigned char*);

struct Struct_0205c570;
extern "C" int func_0205eaa8(Struct_0205c570*);

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void func_0205b6e8(Container0205a3d0*, int);
extern "C" Elem0205a3d0* func_0205b76c(Container0205a3d0*, int);

struct Container0205a330;
extern "C" void func_0205b6a8(Container0205a330*, int);


extern "C" void func_0205c228(void*);

// JPN: func_ov003_0217ce08
extern "C" ARM void func_ov003_0217ce08(void* obj) {
    GameState* battleStruct = GameState::GetInstance();
    void* sub = *(void**)((char*)obj + 0x8c);
    Elem_0205d81c* elem = func_0205ebd8((Struct_0205d81c*)sub);
    if (elem == NULL) return;
    if (!func_0204d5fc((unsigned char*)elem)) return;

    sub = *(void**)((char*)obj + 0x8c);
    short a = *(short*)((char*)elem + 0xae);
    short c = *(short*)((char*)elem + 0xac);
    int field68 = *(int*)((char*)sub + 0x68);
    short d = a << 3;

    int e = func_0205eaa8((Struct_0205c570*)sub);
    short g = (short)e - field68 * 6;
    short comp = (short)((int)g * 13 + d);

    Container0205a3d0* cont = *(Container0205a3d0**)((char*)obj + 0x74);
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
        *(short*)((char*)entry + 0x4) = (short)((int)c << 3) - 4;
        *(short*)((char*)entry + 0x6) = comp + 2;
    }

    func_0205c228((char*)obj + 0x38);
}

#endif
