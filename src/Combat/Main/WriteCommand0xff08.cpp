#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

// USA: func_02069b84
ARM int WriteCommand0xff08_02069b84(char** dst, const char* unused) {
    void* d = *dst;
    unsigned short v = 0xff08;
    memcpy(d, &v, 2);
    return 2;
}
