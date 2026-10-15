#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069d6c
ARM int StoreHalfword0xff1102069d6c(char** obj, const char* unused) {
    void* d = *obj;
    unsigned short v = 0xff11;
    memcpy(d, &v, 2);
    return 2;
}
