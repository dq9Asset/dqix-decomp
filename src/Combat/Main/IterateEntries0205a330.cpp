#include <globaldefs.h>

struct Container0205a330 {
    char unk0[4];
    unsigned short count;
};

extern "C" void func_0205a254(struct Container0205a330*, int, int);

// USA: func_0205a330
ARM void IterateEntries0205a330(struct Container0205a330* c, int arg) {
    unsigned short i;
    for (i = 0; i < c->count; i++) {
        func_0205a254(c, i & 0xff, arg);
    }
}
