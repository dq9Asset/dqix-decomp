#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

// USA: func_02069e5c
ARM int WriteCommand0xff2d_02069e5c(char** dst, const char* unused) {
    void* d = *dst;
    unsigned short v = 0xff2d;
    memcpy(d, &v, 2);
    return 2;
}
