#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
extern "C" void func_0205f138(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov003_0215f1b4(char* base, void* buf);
extern "C" void func_0205e634(void* a, void* b, int p2, int p3, int p4, int p5, int p6);

// JPN: func_ov003_0215f108  (semantic: SetupBattleEntry_0215f108)
extern "C" ARM void func_ov003_0215f108(char* base) {
    func_0205f138((struct Struct0205de24*)(base + 0xb0), 0, 2);

    *(unsigned short*)(base + 0x100 + 0x50) = 0xb;
    *(unsigned short*)(base + 0x100 + 0x52) = 2;
    *(unsigned short*)(base + 0x100 + 0x54) = 0x14;
    *(unsigned short*)(base + 0x100 + 0x56) = 0;
    *(unsigned short*)(base + 0x100 + 0x58) = 0x10;
    *(unsigned short*)(base + 0x100 + 0x5a) = 4;
    *(unsigned short*)(base + 0x100 + 0x5c) = 8;
    *(unsigned short*)(base + 0x100 + 0x5e) = 8;

    *(unsigned char*)(base + 0x167) = 8;
    *(unsigned char*)(base + 0x161) = 0;
    *(unsigned char*)(base + 0x165) = 1;

    memset(*(void**)(base + 0x94), 0, 0x800);
    func_ov003_0215f1b4(base, *(void**)(base + 0x94));

    func_0205e634(base + 0xb0, *(void**)(base + 0x94), 0, 0, 0, 1, 0);
}

#endif
