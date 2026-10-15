#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"



// USA: func_020697b8
ARM int StoreInputEmitFF0B020697b8(char** obj, const char* input) {
    int val;
    unsigned short buf;
    void* dst;
    func_020696bc(input, &val, 1);
    GetGlobalField0x1c020421a0()->field195e = val;
    dst = *obj;
    buf = 0xff0b;
    memcpy(dst, &buf, 2);
    return 2;
}
