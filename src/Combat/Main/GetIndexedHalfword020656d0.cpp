#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

// USA: func_020656d0
ARM unsigned short MessageSystem::GetIndexedHalfword_020656d0() {
    return this->firstLineBuffer[this->tokenIndex];
}
