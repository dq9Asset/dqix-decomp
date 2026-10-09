#if defined(jpn)
#include "Graphics/NSBXX/NSBXX.h"

static inline unsigned int GetNameListEntryCount(const NSBXXNameList *list) {
    return list->numEntries_;
}

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020b8e38
extern "C" ARM void *NSBXXNameList_Search(NSBXXNameList *nameList, const char *name) {
    const uint32_t *targetWords = (const uint32_t *) name;
    if (name == NULL) return NULL;

    unsigned int numEntries = nameList->numEntries_;
    if (numEntries < 16)
    {
        unsigned int searchIndex = 0;
        uint32_t target0         = targetWords[0];
        uint32_t target1         = targetWords[1];
        uint32_t target2         = targetWords[2];
        uint32_t target3         = targetWords[3];

        if (numEntries > searchIndex) {
            int nameByteOffset = 0;
            do {
                intptr_t nameAddress;
                if (nameList != NULL && searchIndex < GetNameListEntryCount(nameList)) {
                    intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                    nameAddress = dataStart + *(uint16_t *) (dataStart + 2);
                    nameAddress += nameByteOffset;
                } else
                    nameAddress = 0;

                const uint32_t *source = (const uint32_t *) nameAddress;
                if (source[0] == target0 && source[1] == target1 && source[2] == target2 && source[3] == target3) {
                    if (nameList != NULL && searchIndex < nameList->numEntries_) {
                        intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                        int stride         = *(uint16_t *) dataStart;
                        return (void *) (dataStart + 4 + stride * searchIndex);
                    }
                    return NULL;
                }

                searchIndex++;
                nameByteOffset += 16;
            } while (searchIndex < GetNameListEntryCount(nameList));
        }
    } else
    {
        NSBXXNameList::SearchTreeEntry *treeEntries = (NSBXXNameList::SearchTreeEntry *) &nameList->treeRoot_8_;
        int firstChild                              = treeEntries[0].children_[0];

        if (firstChild != 0) {
            NSBXXNameList::SearchTreeEntry *node = &treeEntries[firstChild];
            int bitIndex                         = treeEntries[firstChild].bitIndex_;
            unsigned int prevBitIndex            = treeEntries[0].bitIndex_;
            if (prevBitIndex > bitIndex) {
                do {

                    int wordIndex  = bitIndex >> 5;
                    int bitInWord  = bitIndex & 0x1f;
                    int bitValue   = (targetWords[wordIndex] >> bitInWord) & 1;
                    int childIndex = node->children_[bitValue];
                    prevBitIndex   = node->bitIndex_;
                    node           = &treeEntries[childIndex];
                    bitIndex       = treeEntries[childIndex].bitIndex_;

                } while (prevBitIndex > bitIndex);
            }

            unsigned int candidateIndex = node->resourceIndex_;
            intptr_t nameAddress;
            if (nameList != NULL && candidateIndex < numEntries) {
                intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                nameAddress = dataStart + *(uint16_t *) (dataStart + 2) + (candidateIndex * 16);
            } else
                nameAddress = 0;

            const uint32_t *candidateWords = (const uint32_t *) nameAddress;
            if (candidateWords[0] == targetWords[0] && candidateWords[1] == targetWords[1] &&
                candidateWords[2] == targetWords[2] && candidateWords[3] == targetWords[3])
            {
                if (nameList != NULL && candidateIndex < numEntries) {
                    intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                    int stride         = *(uint16_t *) dataStart;
                    return (void *) (dataStart + 4 + stride * candidateIndex);
                }
                return NULL;
            }
        }
    }

    return NULL;
}



#endif
