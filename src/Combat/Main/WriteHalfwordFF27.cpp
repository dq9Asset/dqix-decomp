#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_0206994c
ARM int WriteHalfwordFF27(char** obj, const char* unused) {
    char* d = *obj;
    unsigned short v = 0xff27;
    memcpy(d, &v, 2);
    return 2;
}
