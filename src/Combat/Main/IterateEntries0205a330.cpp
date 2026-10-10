#include <globaldefs.h>

struct Container0205a330 {
    char unk0[4];
    unsigned short count;
};

#if defined(jpn)
#define RegionEntry func_0205b5cc
#else
#define RegionEntry func_0205a254
#endif
extern "C" void RegionEntry(struct Container0205a330*, int, int);

// USA: func_0205a330
ARM void IterateEntries0205a330(struct Container0205a330* c, int arg) {
    unsigned short i;
    for (i = 0; i < c->count; i++) {
        RegionEntry(c, i & 0xff, arg);
    }
}
