#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern "C" void func_0202f24c(MessageSlotController* controller);

// USA: func_020440a4
ARM void TailForward020440a4(MessageSystem* window) {
    func_0202f24c(&window->controller);
}
