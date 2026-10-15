#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

// USA: func_02069b34
ARM int WriteCommand0xff06_02069b34(char** dst, const char* unused) {
    void* d = *dst;
    unsigned short v = 0xff06;
    memcpy(d, &v, 2);
    return 2;
}
