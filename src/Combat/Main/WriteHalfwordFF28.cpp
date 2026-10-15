#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069974
ARM int WriteHalfwordFF28(char** obj, const char* unused) {
    char* d = *obj;
    unsigned short v = 0xff28;
    memcpy(d, &v, 2);
    return 2;
}
