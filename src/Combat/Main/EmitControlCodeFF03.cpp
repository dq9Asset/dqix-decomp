#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


// USA: func_02069f9c
ARM int EmitControlCodeFF03(char** p, const char* unused) {
    void* d = *p;
    unsigned short code = 0xff03;
    memcpy(d, &code, 2);
    return 2;
}
