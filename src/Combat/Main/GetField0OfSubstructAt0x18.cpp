#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

#if !defined(jpn)

// USA: func_020416cc
ARM const char* GetField0OfSubstructAt0x18(MessageGlyphSlot* slot) {
    FontCharacter* character = slot->character;
    return character != 0 ? character->text : 0;
}

#endif
