#include <globaldefs.h>

#include "System/Memory.h"

int GetListEntryWord8020bd8ac(unsigned int index);
void SetListEntryWord8020bd8d4(unsigned int index, int value);
extern "C" int func_020bd7c4(unsigned int index, void* buf, int size, int flag);
void* GetGlobalContext02110370_020bd444(void);
void CleanCacheRange(const void* addr, unsigned int size);

struct Obj020bda58;
extern void* AllocateAndLinkEntry020bda58(struct Obj020bda58* obj, unsigned int size, int a2, int a3, int a4);
void PrepareAndClearList020be4d4(int a0, int a1, int a2, int a3);

struct ListHeader020be2ec {
    char _00[0x38];
    unsigned int field38;
};
#if defined(jpn)
extern struct ListHeader020be2ec data_02110014;
#else
extern struct ListHeader020be2ec data_02110374;
#endif

// JPN: func_020bfdb8
// USA: func_020be2ec
extern "C" ARM void* func_020be2ec(unsigned int index, struct Obj020bda58* obj, int flag) {
    unsigned int size2;
    void* entry = (void*)GetListEntryWord8020bd8ac(index);
    if (entry != NULL) {
        goto done;
    }
#if defined(jpn)
    struct ListHeader020be2ec* hdr = (struct ListHeader020be2ec*)0x02110014;
#else
    struct ListHeader020be2ec* hdr = (struct ListHeader020be2ec*)0x02110374;
#endif
    if (func_020bd7c4(index,
#if defined(jpn)
        &data_02110014,
#else
        &data_02110374,
#endif
        0x3c, 0) != 0x3c) {
        return NULL;
    }
    unsigned int sizeField = hdr->field38;
    unsigned int size1 = sizeField * 4;
    size2 = size1 * 2;
    if (obj == NULL) {
        return NULL;
    }
    void* ctx = flag ? GetGlobalContext02110370_020bd444() : NULL;
    entry = AllocateAndLinkEntry020bda58(obj, size2 + 0x5c, (int)&PrepareAndClearList020be4d4, (int)ctx, index);
    if (entry == NULL) {
        return NULL;
    }
    int fillResult = func_020bd7c4(index, entry, size1 + 0x3c, 0);
    if (fillResult != (int)size1 + 0x3c) {
        return NULL;
    }
    unsigned int count = *(unsigned int*)((char*)entry + 0x38);
    VectorizedInvertedMemcpy((char*)entry + 0x3c, (char*)entry + 0x3c + count * 4, size1);
    VectorizedMemset((char*)entry + 0x3c, 0, size1);
    CleanCacheRange(entry, size2 + 0x3c);
    if (flag) {
        SetListEntryWord8020bd8d4(index, (int)entry);
    }
done:
    return entry;
}
