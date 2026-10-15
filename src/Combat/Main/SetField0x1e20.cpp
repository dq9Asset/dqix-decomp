#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_02042b10
ARM void SetField0x1e20_02042b10(MessageSystem* obj, Foo02042fcc* value) {
    obj->controller.currentBounds = value;
}
