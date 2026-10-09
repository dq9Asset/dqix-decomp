#if defined(jpn)
#include <globaldefs.h>

extern short data_ov003_0217e0dc[3];

extern "C" void func_0208131c(void* obj, int id, short* outX, short* outY);
extern "C" void func_02081348(void* obj, int id, int x, int y);

struct Parent809a0;
extern "C" ARM void func_020814a0(struct Parent809a0* obj, int id, short x, short y);

// JPN: func_ov003_02160930  (semantic: RepositionEntriesInRange_02160930)
extern "C" ARM void func_ov003_02160930(void* self) {
    short* base = *(short**)((char*)self + 0x298);
    if (base == 0) {
        return;
    }
    void* list = *(void**)((char*)self + 0x20c);
    for (int i = 0; i < 3; i++) {
        short* basePtr = *(short**)((char*)self + 0x298);
        short id = data_ov003_0217e0dc[i];
        short baseVal = *basePtr;
        if (id > baseVal) {
            continue;
        }
        if (baseVal >= id + 4) {
            continue;
        }
        for (int j = 0; j < 4; j++) {
            short x, y;
            func_0208131c(list, id, &x, &y);
            func_02081348(list, id, x, y);
            func_020814a0((struct Parent809a0*)list, id, 0xd0, 0xa);
            id = (short)(id + 1);
        }
    }
}

#endif
