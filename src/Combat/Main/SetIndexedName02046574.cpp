#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

// USA: func_02046574
ARM void SetIndexedName02046574(MessageSystem* messages, int index, const char* str) {
    if (str == NULL) return;
    if (index < 0) return;
    if (index >= 0x10) return;
    strncpy(messages->indexedNames[index], str, 0x3f);
    messages->indexedNames[index][0x3f] = 0;
}
