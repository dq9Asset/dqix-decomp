#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry_0205d6a0;
extern "C" void func_0205e9b4(struct Entry_0205d6a0* a, int flag);
extern "C" int func_ov000_02173348(int* obj);
extern "C" void func_0204d620(void* obj);

struct Combatant02176008 {
    char pad0[0xc];
    short fieldC;
    char pad1[0x44 - 0xe];
    int posX;
    int posY;
    int field4c;
    char pad2[0xc7 - 0x50];
    unsigned char field87;
    char pad3[0x488 - 0xc8];
};

struct Elem02176008 {
    char pad0[0xac];
    short x;
    short y;
    char pad1[0xc2 - 0xb0];
    short fieldC2;
};

// JPN: func_ov000_02176008
extern "C" ARM void func_ov000_02176008(char* obj) {
    struct Combatant02176008* c;
    int i;

    func_0205e9b4((struct Entry_0205d6a0*)(obj + 0x188), 1);
    memset(obj + 0x1f98, 0, 8);
    *(signed char*)(obj + 0x1fa0) = 0;
    (obj + *(signed char*)(obj + 0x1fa0))[0x1f98] = 1;

    for (i = 0; i < 4; i++) {
        c = (struct Combatant02176008*)(obj + 0x958) + *(signed char*)(obj + 0x6c + i);
        if (c->field4c < 0) continue;
        if (c->fieldC == 0) continue;
        if (func_ov000_02173348((int*)c)) continue;
        if (c->field87 == 0) continue;

        struct Elem02176008* elem = (struct Elem02176008*)(obj + 0x284);
        int x = c->posX;
        int y = c->posY;
        func_0204d620(elem);
        elem->x = (x >> 3) + 9;
        elem->y = y >> 3;
        elem->fieldC2 = 0;
        *(unsigned short*)(obj + 0x1faa) |= 2;
        return;
    }
}

#endif
