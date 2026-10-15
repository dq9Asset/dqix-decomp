#include <globaldefs.h>

#include "Resource/CharacterCreationUI.h"


// USA: func_020e0310
ARM CreationTextEntry *BinarySearch020e0310(struct Container020e0310 *c, int key, CreationTextKeyReader fn) {
    CreationTextEntry *base;
    int count;
    int low;
    int high;
    int mid;
    CreationTextEntry *elem;
    int result;

    base = c->entries;
    if (base == NULL || fn == NULL) return NULL;
    count = c->count;
    if (count == 0) return NULL;
    high = count - 1;
    low = 0;
    while (low <= high) {
        mid = low + ((high - low + 1) >> 1);
        elem = base + mid;
        result = fn(&elem->key);
        if (result == key) return elem;
        if (result > key) high = mid - 1;
        else low = mid + 1;
    }
    return NULL;
}
