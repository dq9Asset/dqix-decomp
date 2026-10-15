#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

extern int data_0210782c[];
extern "C" int func_02001aec(const void* a, const void* b, int length);

// USA: func_020424e4
ARM int FindEntryIndexByKey020424e4(const char* key, int tableIdx) {
    char* header;
    unsigned int i;
    if (key == 0) {
        return -1;
    }
    header = (char*)data_0210782c[tableIdx];
    for (i = 0; i < *(unsigned int*)(header + 4); i++) {
        FontCharacter* entry = *(FontCharacter**)(header + 0x10) + i;
        if (func_02001aec(entry->text, key, entry->byteLength) == 0) {
            return i;
        }
    }
    return -1;
}
