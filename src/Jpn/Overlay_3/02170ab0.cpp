#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202a9d0(void);
extern "C" void* func_0202a9dc(void);

struct SearchStruct;
extern "C" int func_0202c104(struct SearchStruct* obj, int value);

struct CheckField0AndGlobalHalfStruct0202c508;
extern "C" int func_0202c094(struct CheckField0AndGlobalHalfStruct0202c508* obj);

extern "C" void func_ov017_021d1c94(unsigned short a, unsigned short b, unsigned char c);
extern "C" int* func_0209402c(void);
extern "C" void func_02094950(int* a, unsigned short b, short c, unsigned char d);
extern "C" void func_0202bdcc(struct SearchStruct* obj, int value);

extern "C" void func_0202aca4(void* p);
extern "C" void func_ov003_021710d8(void*, void*);
extern "C" int func_0205f774(void* obj);

// JPN: func_ov003_02170ab0
extern "C" ARM void func_ov003_02170ab0(char* self) {
    GameState* battle = GameState::GetInstance();
    struct SearchStruct* search = (struct SearchStruct*)func_0202a9d0();
    void* dataPtr = func_0202a9dc();

    if (func_0202c104(search, *(unsigned char*)(self + 0x199)) != 0) {
        if (func_0202c094((struct CheckField0AndGlobalHalfStruct0202c508*)search) != 0) {
            ((void(*)(unsigned short, short, unsigned char))func_ov017_021d1c94)(4, -1, 0);
            int* g = func_0209402c();
            func_02094950(g, 4, -1, 0);
        }
        func_0202bdcc(search, *(unsigned char*)(self + 0x199));
    }

    int fieldVal = battle->GetEffectiveDeltaTime();
    *(int*)(self + 0x628) = fieldVal;
    if ((unsigned int)fieldVal > 0xbb8) {
        func_0202aca4(search);
        self[0] = 4;
        return;
    }

    if (*(int*)(self + 0x61c) != 0 && *(int*)(self + 0x618) != 0) {
        func_ov003_021710d8(self, self + 0x28a);
        func_0202aca4(search);
        self[0] = 4;
    }

    if (func_0205f774(dataPtr) != 0) {
        *(int*)(self + 0x61c) = 1;
    }
}

#endif
