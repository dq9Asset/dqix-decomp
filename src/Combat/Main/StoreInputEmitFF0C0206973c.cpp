#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"



// USA: func_0206973c
ARM int StoreInputEmitFF0C0206973c(char** obj, const char* input) {
    int val;
    unsigned short buf;
    void* dst;
    func_020696bc(input, &val, 1);
    GetGlobalField0x1c020421a0()->b1960 = val;
    dst = *obj;
    buf = 0xff0c;
    memcpy(dst, &buf, 2);
    return 2;
}
