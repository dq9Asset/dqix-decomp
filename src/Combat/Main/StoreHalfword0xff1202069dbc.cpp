#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069dbc
ARM int StoreHalfword0xff1202069dbc(char** obj, const char* unused) {
    void* d = *obj;
    unsigned short v = 0xff12;
    memcpy(d, &v, 2);
    return 2;
}
