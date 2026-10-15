#include <globaldefs.h>

#include "Memory/SafeAllocator.h"

struct FlagWord02046708;

struct CombatResBuildView {
#if defined(jpn)
    unsigned char unknown0[0x6c0];
#else
    unsigned char unknown0[0x76c];
#endif
    SafeAllocator *allocator;
    void *sourceData;
    unsigned int size;
};

void *GetDataPtr02114e04_020d6c00();
int TestFlags02046708(FlagWord02046708 *flags, unsigned int mask);
extern "C" void VectorizedInvertedMemcpy(void *dst, void *src, unsigned int size);
#if defined(jpn)
extern "C" void func_020e2ad4(void *, void *, int, int);
#else
extern "C" void func_020e0ec4(void *obj, void *buf, int offset, int dead_r3);
#endif
void SetupWeightedEntriesAndSubmit_020e0df8(void*, int, int, int);
void SetupWeightedEntriesAndSubmitPair020e0cfc(void*, int, int, int);
extern "C" void func_020e0b4c(void *, void *, int, int);
void DelayThenSyncBit0_020c9820();
void CleanInvalidateCacheRange(const void *addr, unsigned int size);
extern "C" int LoadToSubObjVRAM(void *dst, int mode, unsigned int size);

// JPN: func_020e26ac
// USA: func_020e0a78
extern "C" ARM int func_020e0a78(void *receiver) {
    CombatResBuildView *state = static_cast<CombatResBuildView *>(receiver);

    if (state->allocator == 0) {
        return 0;
    }
    if (TestFlags02046708(static_cast<FlagWord02046708 *>(GetDataPtr02114e04_020d6c00()), 0x41)) {
        return 0;
    }

    void *buf = state->allocator->Allocate(state->size);
    VectorizedInvertedMemcpy(state->sourceData, buf, state->size);
#if defined(jpn)
    SetupWeightedEntriesAndSubmit_020e0df8(receiver, (int)buf, 0, 0x720);
    func_020e0b4c(receiver, buf, 0x720, 0xfc0);
    SetupWeightedEntriesAndSubmitPair020e0cfc(receiver, (int)buf, 0x1c60, 0x680);
    func_020e2ad4(receiver, buf, 0x16e0, 0x580);
#else
    SetupWeightedEntriesAndSubmit_020e0df8(receiver, (int)buf, 0, 0x700);
    func_020e0b4c(receiver, buf, 0x700, 0xfc0);
    func_020e0ec4(receiver, buf, 0x16c0, 0x9c0);
    SetupWeightedEntriesAndSubmitPair020e0cfc(receiver, (int)buf, 0x2080, 0xd00);
#endif
    DelayThenSyncBit0_020c9820();
    CleanInvalidateCacheRange(buf, state->size);
    LoadToSubObjVRAM(buf, 0, state->size);
    state->allocator->Free(buf);

    return 1;
}
