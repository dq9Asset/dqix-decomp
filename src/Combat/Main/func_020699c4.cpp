#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"



// USA: func_020699c4
extern "C" ARM int func_020699c4(char** ctx, const char* p1) {
    int buf[3];
    MessageSystem* g;

    func_020696bc(p1, buf, 3);

    g = GetGlobalField0x1c020421a0();
    unsigned short v = (unsigned short)buf[2];
    int b1 = (buf[1] != 0);
    int b0 = (buf[0] != 0);
    g->b19c6 = b0;
    g->b19c7 = b1;
    g->h187e = v;

    void* d = *ctx;
    unsigned short stage = 0xff1b;
    memcpy(d, &stage, 2);

    return 2;
}
