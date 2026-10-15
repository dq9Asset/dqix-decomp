#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_02042b1c
ARM void InitSelfPointer_02042b1c(MessageSystem* self) {
    self->controller.currentBounds = &self->primaryBounds;
}
