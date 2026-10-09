#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov000_02161510(void* obj, int flag);

struct Bits64_0215b6fc {
    unsigned long long value;
};

#define TEST_BIT_CONST(bits, n) (((bits)->value & (1ULL << (n))) != 0)

// JPN: func_ov000_0215b6fc
extern "C" ARM int func_ov000_0215b6fc(void* unused, struct Bits64_0215b6fc* bits) {
    if (TEST_BIT_CONST(bits, 5)) goto ret1;
    if (TEST_BIT_CONST(bits, 6)) goto ret1;
    if (TEST_BIT_CONST(bits, 9)) goto ret1;
    if (TEST_BIT_CONST(bits, 10)) goto ret1;
    if (TEST_BIT_CONST(bits, 12)) goto ret1;
    if (func_ov000_02161510(bits, 0x26) == 0) goto ret0;
ret1:
    return 1;
ret0:
    return 0;
}

#endif
