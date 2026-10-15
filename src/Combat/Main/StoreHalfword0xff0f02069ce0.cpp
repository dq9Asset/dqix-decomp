#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069ce0
ARM int StoreHalfword0xff0f02069ce0(char** obj, const char* unused) {
    void* d = *obj;
    unsigned short v = 0xff0f;
    memcpy(d, &v, 2);
    return 2;
}
