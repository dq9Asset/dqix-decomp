#include <globaldefs.h>
#include "Combat/TryApplyElemFields.h"

class Battle0215b9a4;

#if defined(jpn)
enum { WindowOffset = 0xe20, TextOffset = 0x1a98, DirtyOffset = 0x1a94, ModeOffset = 0x1a80, TextCapacity = 0x800, PageCount = 47 };
#define data_ov002_0216cfac data_ov002_0216d618
#define data_ov002_0216d3b0 data_ov002_0216db30
#define data_ov002_0216cae8 data_ov002_0216d0f0
#define data_ov002_0216caec data_ov002_0216d0f4
#else
enum { WindowOffset = 0xec8, TextOffset = 0x1bd0, DirtyOffset = 0x1bcc, ModeOffset = 0x1bb8, TextCapacity = 0x960, PageCount = 44 };
#endif

typedef void (Battle0215b9a4::*PageFn0215b9a4)(void *buf, int flag);

struct ModePage0215b9a4 {
    int a;
    int b;
};

extern PageFn0215b9a4 data_ov002_0216cfac[PageCount];
extern unsigned int data_ov002_0216d3b0[2];
extern PageFn0215b9a4 data_020e6d5c;
extern ModePage0215b9a4 data_ov002_0216cae8[];
extern ModePage0215b9a4 data_ov002_0216caec[];

extern "C" void *memset(void *dst, int value, unsigned int length);
struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);

// USA: func_ov002_0215b9a4
// JPN: func_ov002_0215cb1c
extern "C" ARM void func_ov002_0215b9a4(Battle0215b9a4 *self, unsigned char key, int flag) {
    char *base          = (char *) self;
    unsigned char *elem = (unsigned char*)FindElementByC40205d81c((Struct_0205d81c*)(base + WindowOffset), key);
    if (elem == 0) {
        return;
    }
    if (flag) {
        elem[0xc5] |= 0x40;
    } else {
        elem[0xc5] &= ~0x40;
    }
    int hl = 0;
    if (elem[0xc5] & 2) {
        hl = 1;
    }
    memset(*(void **) (base + TextOffset), 0, TextCapacity);
    if (!(data_ov002_0216d3b0[1] & 1)) {
        PageFn0215b9a4 nul      = data_020e6d5c;
        data_ov002_0216cfac[0]  = nul;
#if defined(jpn)
        data_ov002_0216cfac[24] = nul;
        data_ov002_0216cfac[31] = nul;
        data_ov002_0216cfac[34] = nul;
        data_ov002_0216cfac[35] = nul;
        data_ov002_0216cfac[39] = nul;
        data_ov002_0216cfac[43] = nul;
        data_ov002_0216cfac[44] = nul;
        data_ov002_0216cfac[45] = nul;
        data_ov002_0216cfac[46] = nul;
#else
        data_ov002_0216cfac[23] = nul;
        data_ov002_0216cfac[30] = nul;
        data_ov002_0216cfac[36] = nul;
        data_ov002_0216cfac[40] = nul;
        data_ov002_0216cfac[41] = nul;
        data_ov002_0216cfac[42] = nul;
        data_ov002_0216cfac[43] = nul;
#endif
        data_ov002_0216d3b0[1] |= 1;
    }
    if (data_ov002_0216cfac[key] == 0) {
        return;
    }
    (self->*data_ov002_0216cfac[key])(*(void **) (base + TextOffset), hl);
    TryApplyElemFields0205d5d0((StructA0205d5d0*)(base + WindowOffset), key, (int)(*(void **) (base + TextOffset)),
#if defined(jpn)
                             1);
#else
                             0, 0);
#endif
    if (*(int *) (base + DirtyOffset) == 0) {
        return;
    }
    for (int i = 0; data_ov002_0216cae8[i].a >= 0; i++) {
        if (*(int *) (base + ModeOffset) == data_ov002_0216cae8[i].a) {
            int page = data_ov002_0216caec[i].a;
            memset(*(void **) (base + TextOffset), 0, TextCapacity);
            if (data_ov002_0216cfac[page] == 0) {
                break;
            }
            (self->*data_ov002_0216cfac[page])(*(void **) (base + TextOffset), hl);
            TryApplyElemFields0205d5d0((StructA0205d5d0*)(base + WindowOffset), (unsigned char) page, (int)(*(void **) (base + TextOffset)),
#if defined(jpn)
                                     1);
#else
                                     0, 0);
#endif
        }
    }
    *(int *) (base + DirtyOffset) = 0;
}

#if defined(jpn)
#undef data_ov002_0216cfac
#undef data_ov002_0216d3b0
#undef data_ov002_0216cae8
#undef data_ov002_0216caec
#endif
