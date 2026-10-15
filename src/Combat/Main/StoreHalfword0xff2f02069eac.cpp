#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069eac
ARM int StoreHalfword0xff2f02069eac(char** obj, const char* unused) {
    void* d = *obj;
    unsigned short v = 0xff2f;
    memcpy(d, &v, 2);
    return 2;
}
