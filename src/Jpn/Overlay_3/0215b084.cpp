#if defined(jpn)
#include <globaldefs.h>

extern "C" void* func_02042940(void);
extern "C" void func_0205f1c8(void*, int, int);

struct Obj0205dee8;
extern "C" void func_0205f1fc(struct Obj0205dee8* obj, int val);

extern "C" int func_ov003_0215cba4(void* p);

// JPN: func_ov003_0215b084  (semantic: UpdateStepStateAndDispatch_0215b084)
extern "C" ARM void func_ov003_0215b084(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)func_02042940();

    if (*(int*)(g + 0x870) == 3) {
        *(unsigned char*)(g + 0x1000 + 0x7de) = 0;
    }

    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        func_0205f1c8(s + 0xf4, 0, 0);
        func_0205f1c8(s + 0xf4, 1, 0);
        func_0205f1c8(s + 0xf4, 2, 0);
        func_0205f1fc((struct Obj0205dee8*)(s + 0xf4), 1);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state != 1) return;

    int r = func_ov003_0215cba4(self);
    switch (r) {
    case -1:
        return;
    case 0:
        *(unsigned char*)(s + 0x588) = 3;
        break;
    case 1:
        *(unsigned char*)(s + 0x588) = 4;
        break;
    case 2:
        *(unsigned char*)(s + 0x588) = 5;
        break;
    case 3:
        *(unsigned char*)(s + 0x588) = 6;
        break;
    case 4:
        *(unsigned char*)(s + 0x588) = 7;
        break;
    case -2:
    case 5:
        *(unsigned char*)(s + 0x588) = 8;
        break;
    default:
        break;
    }
    *(unsigned char*)(s + 0x580) = 0;
}

#endif
