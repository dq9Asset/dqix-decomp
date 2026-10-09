#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"

struct TableEntry_021d4ce4 {
    int key;
    int offset;
};
struct SearchTable_021d4ce4 {
    int unk0;
    int defaultOffset;
    int unk8;
    int entriesOffset;
    int entryCount;
};
struct TypeEntry_021d4ce4 {
    int field0;
    int unk4;
    int field8;
    int fieldC;
};

extern "C" void func_ov017_021d5288(void* obj, int arg1);

// JPN: func_ov017_021d5134
extern "C" ARM int func_ov017_021d5134(void* objRaw, int key) {
    unsigned char* obj = (unsigned char*)objRaw;
    if (*(struct SearchTable_021d4ce4**)(obj + 0x44) == NULL) {
        return -1;
    }

    *(int*)(obj + 0x14) = *(int*)(obj + 0x10);
    *(int*)(obj + 0x28) = *(int*)(obj + 0x24);
    *(struct TypeEntry_021d4ce4**)(obj + 0x34) = NULL;

    if (key < 0) {
        struct SearchTable_021d4ce4* table = *(struct SearchTable_021d4ce4**)(obj + 0x44);
        *(struct TypeEntry_021d4ce4**)(obj + 0x34) = (struct TypeEntry_021d4ce4*)((char*)table + table->defaultOffset);
    } else {
        struct TableEntry_021d4ce4* entry;
        int i;
        struct SearchTable_021d4ce4* table = *(struct SearchTable_021d4ce4**)(obj + 0x44);
        entry = (struct TableEntry_021d4ce4*)((char*)table + table->entriesOffset);
        for (i = 0; i < table->entryCount; i++, entry++) {
            if (entry->key == key) {
                *(struct TypeEntry_021d4ce4**)(obj + 0x34) = (struct TypeEntry_021d4ce4*)((char*)table + entry->offset);
                break;
            }
        }
    }

    if (*(struct TypeEntry_021d4ce4**)(obj + 0x34) == NULL) {
        return -1;
    }

    int newField30 = *(int*)(obj + 0x14) - (*(struct TypeEntry_021d4ce4**)(obj + 0x34))->fieldC * 8;
    *(int*)(obj + 0x30) = newField30;
    *(int*)(obj + 0x14) = newField30 + (*(struct TypeEntry_021d4ce4**)(obj + 0x34))->field8 * 8;

    int dst = *(int*)(obj + 0x30) + (*(struct TypeEntry_021d4ce4**)(obj + 0x34))->fieldC * 8;
    int size = ((*(struct TypeEntry_021d4ce4**)(obj + 0x34))->field8 - (*(struct TypeEntry_021d4ce4**)(obj + 0x34))->fieldC) * 8;
    memset((void*)dst, 0, size);

    int callArg = *(int*)(obj + 0x48) + (*(struct TypeEntry_021d4ce4**)(obj + 0x34))->field0;
    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x50) = 0;

    func_ov017_021d5288(obj, callArg);

    return (*(int*)(obj + 0x3c) == 0) ? 1 : 0;
}

#endif
