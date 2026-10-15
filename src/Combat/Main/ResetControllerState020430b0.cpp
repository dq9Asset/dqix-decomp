#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

void ClearField8ViaPointer0x440(MessageSlotController* controller);

// USA: func_020430b0
ARM void ResetControllerState020430b0(MessageSystem* window) {
    ClearField8ViaPointer0x440(&window->controller);
    window->controller.currentBounds = &window->foo930;
    ClearField8ViaPointer0x440(&window->controller);
    window->controller.currentBounds = &window->primaryBounds;
    window->b19b1 = 0;
    window->b19ae = 0;
    window->b19af = 0;
    window->b19bd = 0;
    window->selectedEntry = -1;
    window->selectedValue = 0;
}
