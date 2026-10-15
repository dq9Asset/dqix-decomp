#include <globaldefs.h>
#include "Resource/ItemNameText.h"
#include "Resource/MessageGlyphSlot.h"

// USA: func_02067f9c
extern "C" ARM int func_02067f9c(ItemNameText* name, const char* text, int fontIndex) {
    if (name != 0) {
        unsigned int bit = ((unsigned int)name->flags << 3) >> 31;
        if (bit != 0) return 1;
    }
    if (text == 0) return 0;
    FontCharacter* entry = FindEntryByKey0204254c(text, fontIndex);
    if (entry != 0) return entry->reserved;
    return 0;
}
