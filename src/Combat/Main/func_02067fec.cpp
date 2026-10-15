#include <globaldefs.h>

#include "Resource/ItemNameText.h"
#include "Resource/MessageGlyphSlot.h"

// USA: func_02067fec
extern "C" ARM int func_02067fec(ItemNameText* state, const char* address, int table)
{
    if (state && !state->bits.field30)
        return state->bits.field28;
    const char* key = address;
    FontCharacter* entry = FindEntryByKey0204254c(key, table);
    if (entry)
    {
        if (entry->reserved)
            return 1;
        int type = *key;
        key += entry->byteLength;
        if (type == 'h')
        {
            entry = FindEntryByKey0204254c(key, table);
            if (entry && entry->reserved)
                return !func_02067f9c(state, key + entry->byteLength, table);
        }
        else if (type == 'y')
            return !func_02067f9c(state, key, table);
    }
    return 0;
}
