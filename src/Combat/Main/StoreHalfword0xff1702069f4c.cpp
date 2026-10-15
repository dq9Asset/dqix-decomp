#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069f4c
ARM int StoreHalfword0xff1702069f4c(char** obj, const char* unused) {
    void* d = *obj;
    unsigned short v = 0xff17;
    memcpy(d, &v, 2);
    return 2;
}
