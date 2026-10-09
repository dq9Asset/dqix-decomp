#if defined(jpn)
#include "Graphics/NSBXX/NSBXX.h"

static inline unsigned int GetNameListEntryCount(const NSBXXNameList *list) {
    return list->numEntries_;
}

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020b8ff8
ARM int NSBXXNameList_SearchIndex(NSBXXNameList *nameList, const char *name) {
    const uint32_t *targetIntArray = (const uint32_t *) name;
    if (name == NULL) return -1;

    unsigned int numEntries = nameList->numEntries_;
    if (numEntries < 16)
    {
        unsigned int searchIndex = 0;
        uint32_t target0         = targetIntArray[0];
        uint32_t target1         = targetIntArray[1];
        uint32_t target2         = targetIntArray[2];
        uint32_t target3         = targetIntArray[3];
        if (numEntries > searchIndex) {
            int offsetWithinNameData = 0;
            do {
                intptr_t sourcePtr;
                if (nameList != NULL && searchIndex < GetNameListEntryCount(nameList)) {
                    intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                    sourcePtr = dataStart + *(uint16_t *) (dataStart + 2);
                    sourcePtr += offsetWithinNameData;
                } else
                    sourcePtr = 0;

                const uint32_t *source = (const uint32_t *) sourcePtr;
                if (source[0] == target0 && source[1] == target1 && source[2] == target2 && source[3] == target3)
                    return searchIndex;

                searchIndex++;
                offsetWithinNameData += 16;
            } while (searchIndex < GetNameListEntryCount(nameList));
        }
    } else
    {
        NSBXXNameList::SearchTreeEntry *entryArray = &nameList->treeRoot_8_;
        int firstChild                             = entryArray[0].children_[0];
        if (firstChild != 0) {
            NSBXXNameList::SearchTreeEntry *searchCursor = &entryArray[firstChild];
            int bitIndex                                 = entryArray[firstChild].bitIndex_;
            unsigned int prevBitIndex                    = entryArray[0].bitIndex_;
            if (prevBitIndex > bitIndex) {
                do {
                    int integerToQuery = bitIndex >> 5;
                    int bitToQuery     = bitIndex & 0x1f;
                    int bitValue       = (targetIntArray[integerToQuery] >> bitToQuery) & 1;
                    int childID        = searchCursor->children_[bitValue];
                    prevBitIndex       = searchCursor->bitIndex_;
                    searchCursor       = &entryArray[childID];
                    bitIndex           = entryArray[childID].bitIndex_;

                } while (prevBitIndex > bitIndex);
            }

            unsigned int candidateIndex = searchCursor->resourceIndex_;
            intptr_t sourcePtr;
            if (nameList != NULL && candidateIndex < nameList->numEntries_) {
                intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                sourcePtr = dataStart + *(uint16_t *) (dataStart + 2) + (candidateIndex * 16);
            } else
                sourcePtr = 0;

            const uint32_t *sourceIntArray = (const uint32_t *) sourcePtr;
            if (sourceIntArray[0] == targetIntArray[0] && sourceIntArray[1] == targetIntArray[1] &&
                sourceIntArray[2] == targetIntArray[2] && sourceIntArray[3] == targetIntArray[3])
                return searchCursor->resourceIndex_;
        }
    }

    return -1;
}


#endif
