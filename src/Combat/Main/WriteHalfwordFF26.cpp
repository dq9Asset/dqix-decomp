#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069924
ARM int WriteHalfwordFF26(char** obj, const char* unused) {
    char* d = *obj;
    unsigned short v = 0xff26;
    memcpy(d, &v, 2);
    return 2;
}
