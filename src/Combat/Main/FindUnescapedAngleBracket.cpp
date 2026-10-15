#include <globaldefs.h>

// USA: func_020424ac
ARM const char* FindUnescapedAngleBracket_020424ac(const char* str) {
    if (str != 0) {
        while (*str != 0) {
            if (*str == '>' && str[1] != '>') {
                return str;
            }
            str++;
        }
    }
    return 0;
}
