#if defined(jpn)
#include <globaldefs.h>

extern "C" void* func_ov000_02162a84(void* obj, int id);
extern "C" int func_ov000_021775b4(char* base, int index);

// JPN: func_ov000_021642fc
extern "C" ARM void func_ov000_021642fc(void* self, int unused1, int c, int unused3, int compareVal, signed char idx6, signed char p2) {
    int flags = *(int*)((char*)self + 0x5000 + 0x7e4);
    if (!(flags & 0x10000)) {
        return;
    }
    if (flags & 0x800000) {
        return;
    }
    int bestIdx = -1;
    int i = 0;
    while (i < 12) {
        int val = func_ov000_021775b4((char*)self + 0x31c + 0x3400, i);
        if (compareVal == val) {
            bestIdx = i;
            break;
        }
        i++;
    }
    void* entry = func_ov000_02162a84((char*)self + 0x31c + 0x3400, idx6);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x26) = (short)c;
        *(unsigned char*)((char*)entry + 0x1d) = (unsigned char)bestIdx;
        *(unsigned char*)((char*)entry + 0x2e) = (unsigned char)p2;
    }
}

#endif
