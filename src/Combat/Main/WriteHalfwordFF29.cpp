#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_0206999c
ARM int WriteHalfwordFF29(char** obj, const char* unused) {
    char* d = *obj;
    unsigned short v = 0xff29;
    memcpy(d, &v, 2);
    return 2;
}
