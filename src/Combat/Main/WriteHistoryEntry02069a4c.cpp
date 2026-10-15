#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"




// USA: func_02069a4c
ARM int WriteHistoryEntry02069a4c(char** ctx, const char* p1) {
    int buf[3];
    MessageSystem* t;
    int a, b;

    func_020696bc(p1, &buf[1], 2);

    t = GetGlobalField0x1c020421a0();
    b = buf[2];

    t->b1956 = t->b1956 % 4;
    a = buf[1];
    t->b194e[t->b1956] = (signed char)a;
    t->b1952[t->b1956] = (signed char)b;
    t->b1956 = t->b1956 + 1;

    {
        void* d = *ctx;
        *(unsigned short*)&buf[0] = 0xff1c;
        memcpy(d, &buf[0], 2);
    }

    return 2;
}
