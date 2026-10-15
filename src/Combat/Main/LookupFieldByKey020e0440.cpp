#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

short GetShortAt0x0020dfbd4(short* key);

// USA: func_020e0440
ARM const char* LookupFieldByKey020e0440(Container020e0310* table, int key) {
    CreationTextEntry* entry;
    if (table == NULL) return 0;
    entry = BinarySearch020e0310(table, key, GetShortAt0x0020dfbd4);
    if (entry != NULL) return entry->text;
    return 0;
}
