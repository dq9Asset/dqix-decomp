#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
extern "C" int func_02005a94(const char* text);

// USA: func_ov023_021db564
ARM int ParseCodeLetter_021db564(char* str) {
    char buf[5];
    int result = 0;
    __clear(buf, 5);
    strncpy(buf, str, 4);
    buf[3] = 0;
    short n = (short)func_02005a94(buf + 1);
    unsigned short base = (unsigned short)(n * 100);
    char c = buf[0];
    if (c == 'C') {
        result = base;
    } else if (c == 'M') {
        result = base + 0x3e8;
    } else if (c == 'X') {
        result = base + 0xfa0;
    } else if (c == 'D') {
        result = base + 0x358 + 0x1800;
    } else if (c == 'T') {
        result = base + 0x328 + 0x2000;
    } else if (c == 'S') {
        result = base + 0x388 + 0x1000;
    } else if (c == 'H') {
        result = base + 0x298 + 0x3800;
        if (result == 0x3db8) result = 0x4e58;
    }
    return result;
}
