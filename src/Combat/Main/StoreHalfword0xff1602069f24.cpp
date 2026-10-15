#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069f24
ARM int StoreHalfword0xff1602069f24(char** obj, const char* unused) {
    void* d = *obj;
    unsigned short v = 0xff16;
    memcpy(d, &v, 2);
    return 2;
}
