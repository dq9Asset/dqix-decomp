#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069ae4
ARM int WriteHalfwordFF04(char** obj, const char* unused) {
    char* d = *obj;
    unsigned short v = 0xff04;
    memcpy(d, &v, 2);
    return 2;
}
