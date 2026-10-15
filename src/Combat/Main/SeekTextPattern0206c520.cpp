#include <globaldefs.h>

#if defined(jpn)
extern "C" int func_02001aec(const void*, const void*, unsigned int);

// JPN: func_0206c520
extern "C" ARM void func_0206c520(void*, char** cursor, const void* pattern, unsigned int length) {
    if (!cursor || !pattern) return;
    char* text = *cursor;
    while (*text) {
        if (func_02001aec(text, pattern, length) == 0) break;
        text++;
    }
    *cursor = text;
}
#endif
