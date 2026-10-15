#include <globaldefs.h>
#include "Resource/MessageSystem.h"

int CheckByteFlagAndInvoke0205bea0(Struct_0205bbcc* p);


// USA: func_0205c6bc
ARM int CallFunc0205bea0IfFlag0x94(Struct_0205c53c* obj) {
    int result = 0;
    if (obj->field94) {
        result = CheckByteFlagAndInvoke0205bea0(&obj->first);
    }
    return result;
}
