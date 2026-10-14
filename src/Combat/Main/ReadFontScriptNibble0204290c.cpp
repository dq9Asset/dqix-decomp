#include <globaldefs.h>

#if defined(jpn)
// JPN: func_0204290c
extern "C" ARM int func_0204290c(const unsigned int* words, unsigned char index) {
    if (index >= 80) return 0;
    unsigned char value = words[index / 8] >> ((index % 8) * 4);
    return value & 0xf;
}
#endif
