#include <globaldefs.h>
#include "Resource/MessageSystem.h"

#if !defined(jpn)
#include "std_library_functions.h"


const char* FindUnescapedAngleBracket_020424ac(const char* str);
extern "C" int func_02001aec(const void* a, const void* b, int n);
FontCharacter* FindEntryByKey0204254c(const char* key, int tableIdx);
void ToUpperBounded_02067f5c(signed char* s, int count);

extern char data_020f0916[];

// USA: func_020695f4
extern "C" ARM void func_020695f4(void* unused, const char* src, char* dst, int id) {
    for (;;) {
        char c = *src;
        if (c == 0) {
            break;
        }
        if (c == '<') {
            const char* gt = FindUnescapedAngleBracket_020424ac(src);
            if (gt != 0 && func_02001aec(src + 1, data_020f0916, 4) == 0) {
                src = gt + 1;
                FontCharacter* e = FindEntryByKey0204254c(src, id);
                if (e != 0 && e->uppercase) {
                    int len = e->byteLength;
                    memcpy(dst, src, len);
                    ToUpperBounded_02067f5c((signed char*)dst, len);
                    src += len;
                    dst += len;
                }
                continue;
            }
        }
        *dst++ = *src++;
    }
    *dst = 0;
}

#endif
