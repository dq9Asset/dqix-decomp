#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069efc
ARM int StoreHalfword0xff1502069efc(char** obj, const char* unused) {
    void* d = *obj;
    unsigned short v = 0xff15;
    memcpy(d, &v, 2);
    return 2;
}
