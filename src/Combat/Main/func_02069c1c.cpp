#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

extern "C" double func_020055d4(const char* str);

// USA: func_02069c1c
extern "C" ARM int func_02069c1c(char** obj, const char* str) {
    float localArr[1];
    for (int i = 0; i < 1; i++) {
        signed char c = *str;
        if (c != 0 && c >= '0' && c <= '9') {
            float f = (float)func_020055d4(str);
            localArr[i] = f;
            while (1) {
                c = *str;
                if (c == 0) break;
                if (c == ',' || c == '>') {
                    str++;
                    break;
                }
                str++;
            }
        }
    }
    MessageSystem* g = GetGlobalField0x1c020421a0();
    g->unknown1840 = (int)(localArr[0] * 4096.0f);
    void* dst = *obj;
    unsigned short marker = 0xff2a;
    memcpy(dst, &marker, 2);
    return 2;
}
