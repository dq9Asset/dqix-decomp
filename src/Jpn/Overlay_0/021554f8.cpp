#if defined(jpn)
#include <globaldefs.h>
#include "Util/Random.h"

extern short data_ov000_02183ccc[8];
extern short data_ov000_02183c3c[8];
extern "C" int func_ov000_0216029c(struct Random* rand, short* buf, int count, int flag);

// JPN: func_ov000_021554f8
extern "C" ARM void func_ov000_021554f8(struct Random* rand, int exclude, short* out) {
    short buf1[8];
    unsigned short* dst1 = (unsigned short*)buf1;
    unsigned short* src1 = (unsigned short*)data_ov000_02183ccc;
    int cnt1 = 8;
    do {
        *dst1 = *src1;
        dst1++;
        src1++;
    } while (--cnt1);
    short* p1 = buf1;
    int count = func_ov000_0216029c(rand, p1, 8, 1);
    short buf2[8];
    int cnt2 = 8;
    unsigned short* dst2 = (unsigned short*)buf2;
    unsigned short* src2 = (unsigned short*)data_ov000_02183c3c;
    do {
        *dst2 = *src2;
        dst2++;
        src2++;
    } while (--cnt2);
    short* p2 = buf2;
    int n = 0;
    for (int i = 0; i < count; i++) {
        if (exclude != p1[i]) {
            p2[n] = p1[i];
            n++;
        }
    }
    if (n <= 0) {
        *out = (short)exclude;
        return;
    }
    int idx = NextRandomMax(rand, n);
    *out = p2[idx];
}

#endif
