#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov000_02172774(void* obj);
extern "C" void func_0204ca28(void* a, int b, int size, void* src, int extra);
extern short data_ov000_02184440[];

// JPN: func_ov000_021764ac
extern "C" ARM void func_ov000_021764ac(char* obj) {
    char* elem;
    int i;
    for (i = 0; i < 4; i++) {
        int kind;
        signed char idx = *(signed char*)(obj + i + 0x6c);
        elem = obj + 0x958 + idx * 0x488;
        int cid = *(int*)(elem + 0x4c);
        int valid = (cid >= 0 && cid <= 3) ? 1 : 0;
        if (!valid) continue;
        kind = 0;
        int code = func_ov000_02172774(elem);
        switch (code) {
        case 4: kind = 1; break;
        case 5: kind = 2; break;
        case 6: kind = 3; break;
        }
        memcpy(*(void**)(obj + 0x178), &data_ov000_02184440[kind], 2);
        func_0204ca28(obj + 0x8c4, cid + 2, 0xa, *(void**)(obj + 0x178), 2);
    }
}

#endif
