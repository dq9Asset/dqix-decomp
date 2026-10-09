#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_02042940();
extern "C" void func_ov000_0217d98c(void* obj, int a, int b);
extern "C" void func_ov000_02178db0(void* obj, void* buf);
extern "C" void func_0205e634(void* a, void* b, int c, int d, int e, int f, int g);

struct InStruct_02178c64 {
    char pad[0x44];
    int x;
    int y;
};

// JPN: func_ov000_02178c64  (semantic: ApplyElemFieldsWithMode_02178c64)
extern "C" ARM void func_ov000_02178c64(void* objRaw, struct InStruct_02178c64* in, int mode, int arg3) {
    char* obj = (char*)objRaw;
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    func_ov000_0217d98c(obj, mode, arg3);
    char* s = obj + 0x188;
    *(short*)(s + 0xa0) = 0x15;
    *(short*)(s + 0xa2) = 1;
    *(short*)(s + 0xa4) = (x >> 3) + 9;
    *(short*)(s + 0xa6) = (y >> 3) + 1;
    *(short*)(s + 0xac) = 0xa;
    *(short*)(s + 0xae) = 0xd;
    if (mode == 2) {
        *(short*)(s + 0xa8) = 0xc;
        *(short*)(s + 0xaa) = 0xa;
    }
    if (mode == 3) {
        *(short*)(s + 0xa8) = 0xc;
        *(short*)(s + 0xaa) = 8;
    }
    if (mode == 4) {
        *(short*)(s + 0xac) = 0xa;
        *(short*)(s + 0xae) = 0xb;
        *(short*)(s + 0xa8) = 0xc;
        *(short*)(s + 0xaa) = 4;
    }
    *(unsigned char*)(s + 0xb1) = 3;
    void* buf = *(void**)((char*)func_02042940() + 0x28);
    memset(buf, 0, 0x800);
    func_ov000_02178db0(obj, buf);
    func_0205e634(s, buf, 0, 1, 0, 1, 0);
}

#endif
