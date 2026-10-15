#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

// USA: func_02069e34
ARM int WriteCommand0xff2c_02069e34(char** dst, const char* unused) {
    void* d = *dst;
    unsigned short v = 0xff2c;
    memcpy(d, &v, 2);
    return 2;
}
