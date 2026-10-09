#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int func_02042940();
extern "C" void func_ov000_0217d98c(void* obj, int a, int b);
extern "C" void func_ov000_02178b7c(void* obj, void* buf);
extern "C" void func_0205e634(void* a, void* b, int c, int d, int e, int f, int g);
extern "C" void* func_0202a9d0(void);
extern "C" int func_0202b388(int* obj);
extern "C" int func_0200ff04(GameState* battleStruct);

struct InStruct_02178a38 {
    char pad[0x44];
    int x;
    int y;
};

// JPN: func_ov000_02178a38
extern "C" ARM void func_ov000_02178a38(void* objRaw, struct InStruct_02178a38* in, int arg2, int arg3) {
    char* obj = (char*)objRaw;
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    func_ov000_0217d98c(obj, arg2, arg3);
    char* s = obj + 0x188;
    *(short*)(s + 0xa0) = 0xa;
    *(short*)(s + 0xa2) = 7;
    *(short*)(s + 0xa4) = (x >> 3) + 9;
    *(short*)(s + 0xa6) = (y >> 3) + 1;
    *(short*)(s + 0xa8) = 0xc;
    *(short*)(s + 0xaa) = 7;
    *(short*)(s + 0xac) = 0xa;
    *(short*)(s + 0xae) = 0xd;
    if (func_0202b388((int*)func_0202a9d0())) {
        if (func_0200ff04(GameState::GetInstance()) == 0) {
            *(short*)(s + 0xa8) = 0xc;
            *(short*)(s + 0xaa) = 4;
            *(short*)(s + 0xac) = 0xa;
            *(short*)(s + 0xae) = 0xb;
        }
    }
    *(unsigned char*)(s + 0xb1) = 2;
    void* buf = *(void**)((char*)func_02042940() + 0x28);
    memset(buf, 0, 0x800);
    func_ov000_02178b7c(obj, buf);
    func_0205e634(s, buf, 0, 1, 0, 1, 0);
}

#endif
