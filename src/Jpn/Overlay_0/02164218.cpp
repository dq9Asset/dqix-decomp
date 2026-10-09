#if defined(jpn)
#include <globaldefs.h>

struct StructAt3c_02164218 {
    signed char f0;
    signed char f1;
    char pad2;
    unsigned char f3;
    signed char f4;
    char pad5;
    short f6;
    unsigned short f8;
};

extern "C" int func_ov000_021775b4(char* base, int index);
extern "C" void func_ov000_021759e4(void* obj, int a, int f0, int f1, int bestIdxByte, int f6, int f4, int f8);

// JPN: func_ov000_02164218
extern "C" ARM void func_ov000_02164218(void* self, int a, struct StructAt3c_02164218* s) {
    int flags = *(int*)((char*)self + 0x5000 + 0x7e4);
    if (!(flags & 0x10000)) {
        return;
    }
    if (flags & 0x800000) {
        return;
    }
    void* mirrorPtr = *(void**)((char*)self + 0x218);
    int val1 = *(int*)((char*)mirrorPtr + 0x8000 + 0xe20);
    if (val1 == 0) {
        if (*(unsigned char*)((char*)mirrorPtr + 0x8000 + 0xe49) == 2) {
            return;
        }
    }
    int bestIdx = -1;
    int i = 0;
    while (i < 12) {
        int val = func_ov000_021775b4((char*)self + 0x31c + 0x3400, i);
        if (s->f3 == val) {
            bestIdx = i;
            break;
        }
        i++;
    }
    func_ov000_021759e4((char*)self + 0x31c + 0x3400, a, s->f0, s->f1, (signed char)bestIdx, s->f6, s->f4, s->f8);
}

#endif
