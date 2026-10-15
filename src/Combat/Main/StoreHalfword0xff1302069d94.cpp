#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069d94
ARM int StoreHalfword0xff1302069d94(char** obj, const char* unused) {
    void* d = *obj;
    unsigned short v = 0xff13;
    memcpy(d, &v, 2);
    return 2;
}
