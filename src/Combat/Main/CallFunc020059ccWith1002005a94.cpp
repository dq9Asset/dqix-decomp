#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern "C" int func_020059cc(const char*, const char**, int);

// USA: func_02005a94  (semantic: CallFunc020059ccWith10_02005a94)
extern "C" ARM int func_02005a94(const char* p) {
    return func_020059cc(p, 0, 0xa);
}
