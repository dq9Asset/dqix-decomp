#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02042940(void);
extern "C" void* func_020d8608(void);
extern "C" void* func_0205ff20(void);
extern "C" int func_0206f104(int a, unsigned char* p, int bit);
extern "C" int func_02047928(void** p);
extern "C" int func_02039278(void* obj);
extern "C" int func_02054940(signed char* p);
struct BitField0203402c;
extern "C" int func_02033b64(BitField0203402c* p);
struct FlagWord02046708;
extern "C" int func_02047528(FlagWord02046708* w, unsigned int mask);
extern "C" int func_020397d4(char* p);
extern "C" int func_020c5494(volatile unsigned short* p);
extern "C" int func_020121c0(int* flags, int mask);
struct Obj0205eaa0;
extern "C" int func_0205fd8c(Obj0205eaa0* obj, int a, int b);
extern "C" void func_02043978(char* p);
extern "C" void* func_020d9458(void);
struct Obj020d7aa0;
extern "C" void func_020d94a4(Obj020d7aa0* obj);
extern "C" void* func_02012dac(void);
extern "C" void* func_020179f8(void* a);
extern "C" void func_ov017_021c0d08(unsigned char* obj, unsigned char flag);
extern "C" void func_0204785c(void* list, void* node);

extern int data_02114ad0;
extern Obj0205eaa0 data_021086a4;

// JPN: func_ov017_021c0b9c
extern "C" ARM void func_ov017_021c0b9c(void* p9, unsigned char p8, unsigned char p7, int p6) {
    void* g = func_02042940();
    if (p6 != 0) {
        GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
        void* d = func_020d8608();
        void* f = func_0205ff20();
        if (func_0206f104((int)f, (unsigned char*)f + 0x8c, 0x119a) == 0) return;
        if (func_02047928((void**)*(void**)((char*)p9 + 0x3000 + 0x4ec)) == 0) return;
        if (func_02039278(combatant) == 0) return;
        if (func_02054940((signed char*)combatant) != 0) return;
        if (*(int*)((char*)combatant + 0x180) & 1) return;
        if (func_02033b64((BitField0203402c*)combatant) != 0 ||
            *(short*)((char*)combatant + 0xac) != 0 ||
            *(int*)((char*)g + 0x868) != 0) return;
        if (func_02047528((FlagWord02046708*)d, 0x800) != 0) return;
        if (func_020397d4((char*)combatant) != 0) return;
        if (func_020c5494((volatile unsigned short*)0x400006c) != 0) return;
        if (func_020121c0(&data_02114ad0, 4) == 0) return;
        *(unsigned short*)((char*)combatant + 0xb2) = 0;
        func_0205fd8c(&data_021086a4, 1, 0);
    } else {
        if (*(int*)((char*)g + 0x868) != 0) func_02043978((char*)g);
    }

    void* reset = func_020d9458();
    func_020d94a4((Obj020d7aa0*)reset);
    func_020179f8(func_02012dac());

    func_ov017_021c0d08((unsigned char*)*(void**)((char*)p9 + 0x3000 + 0x91c), p8);
    char* base = (char*)p9 + 0x3000;
    *((unsigned char*)*(void**)(base + 0x91c) + 0x24) = p7;
    func_0204785c(*(void**)(base + 0x4ec), *(void**)(base + 0x91c));
}

#endif
