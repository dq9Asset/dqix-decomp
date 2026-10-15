#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

// USA: func_020698fc
ARM int WriteCommand0xff1f_020698fc(char** dst, const char* unused) {
    void* d = *dst;
    unsigned short v = 0xff1f;
    memcpy(d, &v, 2);
    return 2;
}
