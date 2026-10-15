#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069ed4
ARM int StoreHalfword0xff1402069ed4(char** obj, const char* unused) {
    void* d = *obj;
    unsigned short v = 0xff14;
    memcpy(d, &v, 2);
    return 2;
}
