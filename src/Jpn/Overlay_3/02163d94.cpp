#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned int func_020477d4(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_0202b388(unsigned int, unsigned int);
extern "C" unsigned int func_ov017_021960f8(unsigned int);
extern "C" unsigned int func_020541fc();
extern "C" unsigned int func_02012dac();
extern "C" unsigned int func_0202a9d0();
extern "C" unsigned int func_0202c094(unsigned int);
extern "C" unsigned int func_ov003_02161568();
extern "C" unsigned int func_ov017_021bc0dc(unsigned int, unsigned int, unsigned int);

// JPN: func_ov003_02163d94  (semantic: Trans_02163d94)
extern "C" ARM unsigned int func_ov003_02163d94(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    unsigned int r7 = 0;
    unsigned int r8 = 0;
    unsigned int r9 = 0;
    r9 = r0;
    r0 = (unsigned int)func_ov003_02161568();
    r0 = (unsigned int)GameState::GetInstance();
    r5 = r0;
    r0 = (unsigned int)func_02012dac();
    r4 = r0;
    r0 = (unsigned int)((unsigned int)func_ov017_0218c1d0());
    r6 = r0;
    r1 = r6 + 0x3000;
    r7 = *(unsigned int*)((char*)r1 + 0x4ec);
    r8 = *(unsigned int*)((char*)r1 + 0x524);
    r1 = r9 + 0x200;
    r1 = *(signed char*)((char*)r1 + 0xca);
    r0 = r5;
    r0 = (unsigned int)((GameState*)r0)->GetGameObjectByIndex(r1);
    r0 = (unsigned int)func_020541fc();
    r5 = r0;
    r0 = (unsigned int)func_0202a9d0();
    r1 = *(unsigned int*)((char*)r4 + 0x8);
    r4 = r0;
    r0 = r8;
    r2 = 0x1;
    r0 = (unsigned int)func_ov017_021bc0dc(r0, r1, r2);
    r1 = r9 + 0x200;
    r3 = *(signed char*)((char*)r1 + 0xca);
    r0 = r7;
    r2 = 0x0;
    *(unsigned char*)((char*)r8 + 0xc9) = (unsigned char)r3;
    r3 = *(unsigned char*)((char*)r5 + 0x14);
    r1 = r8;
    r3 = r3 << 0x1f;
    r3 = r3 >> 0x1f;
    *(unsigned char*)((char*)r8 + 0xca) = (unsigned char)r3;
    *(unsigned char*)((char*)r8 + 0xcb) = (unsigned char)r2;
    r0 = (unsigned int)func_020477d4(r0, r1, r2, r3);
    r0 = 0x10;
    *(unsigned char*)((char*)r9 + 0x2cb) = (unsigned char)r0;
    r1 = *(unsigned int*)((char*)r9 + 0x28c);
    r0 = r4;
    r1 = r1 & ~0x8000;
    *(unsigned int*)((char*)r9 + 0x28c) = (unsigned int)r1;
    r0 = (unsigned int)func_0202b388(r0, r1);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r0 = r4;
    r0 = (unsigned int)func_0202c094(r0);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r0 = r6;
    r0 = (unsigned int)func_ov017_021960f8(r0);
    return r0;
}

#endif
