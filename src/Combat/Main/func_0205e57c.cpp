#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct Inner0205e3ec { unsigned int v[4]; };
struct Struct0205e3ec { unsigned char a; unsigned char b; unsigned char pad[2]; struct Inner0205e3ec mid; };
struct Struct0205e3ec* CopyStruct0205e3ec(struct Struct0205e3ec* dst, struct Struct0205e3ec* src);

struct QNode0205e1e4 {
    char pad[0x18];
    struct QNode0205e1e4* next;
};
struct QList0205e1e4 {
    struct QNode0205e1e4* head;
    struct QNode0205e1e4* tail;
    int count;
};
struct QNode0205e1e4* DequeueNode(struct QList0205e1e4* list);

struct QNode0205e18c {
    char pad[0x18];
    struct QNode0205e18c* next;
};
struct QList0205e18c {
    struct QNode0205e18c* head;
    struct QNode0205e18c* tail;
    int count;
};
void EnqueueNode(struct QList0205e18c* list, struct QNode0205e18c* node);

struct BitArrayObj0205e830;
int TestBitInArray0x1524(struct BitArrayObj0205e830* obj, int index);

struct SearchStruct0202c1a4;
extern "C" void* func_0202ae18(void);
void* GetSubstructAt0x7c0_0202c19c(void* base);
int TestBitBySignedByteIndex_0202c1c0(SearchStruct* obj, int index);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct SearchHeader0205e57c {
    unsigned char pad[0xfc0];
    int busy;
};

struct SlotEntry0205e57c {
    SearchEntry0202c178 head;
    struct Struct0205e3ec slots[5];
};

struct Node0205e57c {
    struct Struct0205e3ec data;
    short group;
    unsigned short flags;
    struct Node0205e57c* next;
};

struct List0205e57c {
    struct Node0205e57c* head;
    struct Node0205e57c* tail;
    int count;
};

struct Obj0205e57c {
    struct Node0205e57c nodes[0xc0];
    struct List0205e57c free;
    struct List0205e57c pending;
    struct List0205e57c active;
};

static int sPendingBytes;
static int sActiveBytes;

// USA: func_0205e57c
extern "C" ARM void func_0205e57c(struct Obj0205e57c* obj) {
    static unsigned char sSeq;

    SearchStruct* search = (SearchStruct*)func_0202ae18();
    if (sSeq >= 0xfa) {
        sSeq = 0;
    }
    if (((struct SearchHeader0205e57c*)search)->busy != 0) {
        return;
    }

    struct SlotEntry0205e57c* table = (struct SlotEntry0205e57c*)GetSubstructAt0x7c0_0202c19c(search);
    for (int i = 0; i < 5; i++) {
        if (table->slots[i].a != 0xff) {
            sPendingBytes += 0x10;
        }
        table->slots[i].a = 0xff;
    }

    for (int j = 0; j < 5; j++) {
        int allFree;
        if (table->slots[j].a != 0xff) continue;
        struct Node0205e57c* node = obj->pending.head;
        if (node == NULL) continue;
        if (node->flags & 1) {
            allFree = 1;
            struct SlotEntry0205e57c* cur = (struct SlotEntry0205e57c*)GetSubstructAt0x7c0_0202c19c(func_0202ae18());
            for (int k = 0; k < 5; k++) {
                if (cur->slots[k].a != 0xff) {
                    allFree = 0;
                    break;
                }
            }
            if (allFree) {
                node->flags &= ~1;
            }
        }
        if (node->flags & 1) continue;
        DequeueNode((struct QList0205e1e4*)&obj->pending);
        CopyStruct0205e3ec(&table->slots[j], &node->data);
        table->slots[j].b = ++sSeq;
        EnqueueNode((struct QList0205e18c*)&obj->free, (struct QNode0205e18c*)node);
    }

    for (int g = 0; g < 4; g++) {
        if (!TestBitBySignedByteIndex_0202c1c0(search, g)) continue;
        if (g == GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search)) continue;
        struct SlotEntry0205e57c* entry = (struct SlotEntry0205e57c*)GetEntryBySignedByteIndex_0202c178(search, g);
        if (entry == NULL) continue;
        if (entry->head.flags.selected == 0) continue;
        for (int s = 0; s < 5; s++) {
            GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search);
            if (entry->slots[s].a == 0xff) continue;
            if (!TestBitInArray0x1524((struct BitArrayObj0205e830*)obj, entry->slots[s].a)) continue;
            struct Node0205e57c* node = (struct Node0205e57c*)DequeueNode((struct QList0205e1e4*)&obj->free);
            if (node == NULL) continue;
            CopyStruct0205e3ec(&node->data, &entry->slots[s]);
            node->group = g;
            EnqueueNode((struct QList0205e18c*)&obj->active, (struct QNode0205e18c*)node);
            sActiveBytes += 0x10;
        }
    }
}
