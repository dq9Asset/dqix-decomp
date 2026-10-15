#include <globaldefs.h>
#include "Resource/MessageSystem.h"


// USA: func_020696bc  (semantic: ParseDelimitedInts020696bc)
extern "C" ARM int func_020696bc(const char* str, int* out, int count) {
    int i;
    for (i = 0; i < count; i++) {
        char c = *str;
        if (c != 0 && ((c >= '0' && c <= '9') || c == '-')) {
            out[i] = func_02005a94(str);
            for (;;) {
                char c2 = *str;
                if (c2 == 0) break;
                if (c2 == ',' || c2 == '>') { str++; break; }
                str++;
            }
        }
    }
    return 0;
}
