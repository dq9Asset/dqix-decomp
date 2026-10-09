#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" void MemoryMapTexturePalette(void);
extern "C" void LoadToTexturePalette(void* ptr, int a, unsigned int b);
extern "C" void MemoryUnmapTexturePalette(void);
extern "C" void _Z28LockStagedTextureVRAMCopyingv(void);
extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);
extern "C" int _ZNK8Object3D23GetTexturePaletteOffsetEv(unsigned char* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void _Z30UnlockStagedTextureVRAMCopyingv(void);

struct S0217b7ac {
    SafeAllocator* allocator;
    char pad4[0x88 - 4];
    void* field88;
};

struct Inner0217b7ac {
    char pad0[0x2c];
    int field2c;
    char pad30[0x30 - 0x30];
    unsigned short field30;
};

// JPN: func_ov003_0217b7ac  (semantic: AllocateAndFillBuffer_0217b7ac)
extern "C" ARM void func_ov003_0217b7ac(S0217b7ac* obj, unsigned short fillValue) {
    GameState::GetInstance();
    _Z28LockStagedTextureVRAMCopyingv();
    MemoryMapTexturePalette();

    void* p88 = obj->field88;
    if (p88 != NULL) {
        Inner0217b7ac* inner = (Inner0217b7ac*)_ZN7Model3D7GetTEX0Ev(p88);
        if (inner != NULL) {
            int size = inner->field2c;
            if (_ZNK8Object3D23GetTexturePaletteOffsetEv((unsigned char*)obj + 0x80)) {
                size = _ZNK8Object3D23GetTexturePaletteOffsetEv((unsigned char*)obj + 0x80);
            }

            void* buf;
            unsigned int allocSize = (unsigned int)inner->field30 << 3;
            int scaledSize = (unsigned short)size << 3;

            buf = obj->allocator->Allocate(allocSize);
            if (buf != NULL) {
                unsigned int i;
                for (i = 0; i < allocSize / 2; i++) {
                    ((unsigned short*)buf)[i] = fillValue;
                }
                CleanInvalidateCacheRange(buf, allocSize);
                LoadToTexturePalette(buf, scaledSize, allocSize);
            }
        }
    }

    MemoryUnmapTexturePalette();
    _Z30UnlockStagedTextureVRAMCopyingv();
}

#endif
