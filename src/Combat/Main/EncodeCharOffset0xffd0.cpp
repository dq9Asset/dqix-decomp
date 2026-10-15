#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

// USA: func_02069bac
ARM int EncodeCharOffset0xffd0_02069bac(char** dst, const char* src) {
    void* d = *dst;
    unsigned short base = 0xffd0;
    base += (unsigned short)(*src - 0x40);
    unsigned short v = base;
    memcpy(d, &v, 2);
    return 2;
}
