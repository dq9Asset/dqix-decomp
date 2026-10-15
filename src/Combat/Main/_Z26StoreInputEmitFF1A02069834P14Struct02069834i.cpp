#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"




// KEEP-NAME
// USA: func_02069834
ARM int StoreInputEmitFF1A02069834(char** obj, const char* input) {
    int val;
    unsigned short buf;
    void* dst;
    func_020696bc(input, &val, 1);
    PushToRingBuffer020457e8(GetGlobalField0x1c020421a0(), val);
    dst = *obj;
    buf = 0xff1a;
    memcpy(dst, &buf, 2);
    return 2;
}
