#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* func_02042940(void);
extern "C" void* func_020e2070(void*, int);
extern "C" void func_ov003_0215a73c(void*, void*);
extern "C" void func_02043898(void*);
extern "C" void func_0209e5a8(void*, unsigned short);
extern "C" int func_0209e7a4(void*);

extern unsigned char data_021098ac;

// JPN: func_ov003_0215c528
extern "C" ARM void func_ov003_0215c528(void* self) {
    unsigned char* s = (unsigned char*)self;
    GameState::GetInstance();
    unsigned char* g = (unsigned char*)func_02042940();
    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        if (*(unsigned char*)(s + 0x59d) != 0) return;

        void* val0 = func_020e2070(s + 0x64, 0x44c);
        if (val0 != 0 && strlen((char*)val0) != 0) {
            *(int*)(g + 0x868) = 1;
            void* val1 = func_020e2070(s + 0x64, 0x44c);
            func_ov003_0215a73c(self, val1);
        } else {
            func_02043898(g);
        }
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 1) {
        if (*(int*)(g + 0x868) != 0) return;
        func_0209e5a8(&data_021098ac, 0x3b);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state != 2) return;

    if (*(int*)(g + 0x870) == 3) {
        *(unsigned char*)(g + 0x1000 + 0x7de) = 0;
    }
    if (func_0209e7a4(&data_021098ac) == 0) {
        *(unsigned char*)(s + 0x588) = 1;
        *(unsigned char*)(s + 0x580) = 0;
    }
}

#endif
