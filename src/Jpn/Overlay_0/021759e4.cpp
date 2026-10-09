#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02162a84(void* obj, int id);
extern "C" int func_0200ff04(GameState* battleStruct);
struct Obj0205eaa0;
extern "C" void func_0205fd8c(struct Obj0205eaa0* obj, int a, int b);
extern int data_021086a4;
struct Obj02171d90;
extern "C" void func_ov000_0217363c(struct Obj02171d90* obj, int key);
extern "C" void func_ov000_021728a8(void* obj);

// JPN: func_ov000_021759e4
extern "C" ARM void func_ov000_021759e4(void* obj, int id, int val100, int param3,
                                          signed char param4, short param5, signed char param6, unsigned short param7) {
    void* r4 = func_ov000_02162a84(obj, id);
    if (!r4) return;
    GameState* bs = GameState::GetInstance();
    int f3ac = func_0200ff04(bs);
    if (id != f3ac && val100 == 0x64) {
        signed char off = *(signed char*)((char*)r4 + 0x18);
        signed char pval = *(signed char*)((char*)r4 + off + 0x10);
        if (val100 != pval) {
            func_0205fd8c((struct Obj0205eaa0*)&data_021086a4, 0x19, 0);
        }
    }
    if (*((unsigned char*)r4 + 0x47e)) return;
    int valid = 0;
    int val4c = *(int*)((char*)r4 + 0x4c);
    if (val4c >= 0 && val4c <= 3) valid = 1;
    if (!valid) return;
    signed char off2 = *(signed char*)((char*)r4 + 0x18);
    signed char* p10 = (signed char*)((char*)r4 + off2 + 0x10);
    *p10 = (signed char)val100;
    *((unsigned char*)r4 + 0x1c) = (unsigned char)param3;
    *((unsigned char*)r4 + 0x1d) = (unsigned char)param4;
    *(short*)((char*)r4 + 0x2c) = param5;
    *((unsigned char*)r4 + 0x2e) = (unsigned char)param6;
    *(unsigned short*)((char*)r4 + 0x26) = param7;
    func_ov000_0217363c((struct Obj02171d90*)r4, param5);
    func_ov000_021728a8(r4);
}

#endif
