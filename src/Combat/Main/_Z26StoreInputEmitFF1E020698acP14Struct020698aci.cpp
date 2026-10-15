#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"




// KEEP-NAME
// USA: func_020698ac
ARM int StoreInputEmitFF1E020698ac(char** obj, const char* input) {
    int val;
    unsigned short buf;
    void* dst;
    func_020696bc(input, &val, 1);
    PushToRingBuffer020457e8(GetGlobalField0x1c020421a0(), val);
    dst = *obj;
    buf = 0xff1e;
    memcpy(dst, &buf, 2);
    return 2;
}
