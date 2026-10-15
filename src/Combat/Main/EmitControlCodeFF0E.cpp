#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069fc4
ARM int EmitControlCodeFF0E(char** p, const char* unused) {
    void* d = *p;
    unsigned short code = 0xff0e;
    memcpy(d, &code, 2);
    return 2;
}
