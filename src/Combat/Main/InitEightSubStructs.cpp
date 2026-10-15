#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern "C" void func_0204719c(void* obj);

// USA: func_0202f1a4
ARM void InitEightSubStructs_0202f1a4(MessageSlotController* obj) {
    int i;
    for (i = 0; i < 8; i++) {
        func_0204719c(&obj->slots[i]);
    }
    obj->currentBounds = 0;
    obj->allocator = 0;
}
