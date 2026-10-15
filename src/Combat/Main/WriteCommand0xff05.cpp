#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

// USA: func_02069b0c
ARM int WriteCommand0xff05_02069b0c(char** dst, const char* unused) {
    void* d = *dst;
    unsigned short v = 0xff05;
    memcpy(d, &v, 2);
    return 2;
}
