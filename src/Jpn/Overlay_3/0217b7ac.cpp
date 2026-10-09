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

struct ServiceEnemyPreview {
    SafeAllocator* allocator;
    char unknown4[0x88 - 4];
    void* model;
};

struct PreviewTextureResource {
    char unknown0[0x2c];
    int paletteOffsetUnits;
    char unknown30[0x30 - 0x30];
    unsigned short paletteSizeUnits;
};

// JPN: func_ov003_0217b7ac
// Replaces the enemy preview's texture palette with a single colour.
// The palette offset and byte length remain in the TEX0 format's eight-byte units until upload.
extern "C" ARM void FillServiceEnemyPreviewPalette(ServiceEnemyPreview* preview, unsigned short paletteColor) {
    GameState::GetInstance();
    _Z28LockStagedTextureVRAMCopyingv();
    MemoryMapTexturePalette();

    void* previewModel = preview->model;
    if (previewModel != NULL) {
        PreviewTextureResource* textureResource = (PreviewTextureResource*)_ZN7Model3D7GetTEX0Ev(previewModel);
        if (textureResource != NULL) {
            int uploadOffsetUnits = textureResource->paletteOffsetUnits;
            if (_ZNK8Object3D23GetTexturePaletteOffsetEv((unsigned char*)preview + 0x80)) {
                uploadOffsetUnits = _ZNK8Object3D23GetTexturePaletteOffsetEv((unsigned char*)preview + 0x80);
            }

            void* paletteData;
            unsigned int paletteByteCount = (unsigned int)textureResource->paletteSizeUnits << 3;
            int paletteByteOffset = (unsigned short)uploadOffsetUnits << 3;

            paletteData = preview->allocator->Allocate(paletteByteCount);
            if (paletteData != NULL) {
                unsigned int colorIndex;
                for (colorIndex = 0; colorIndex < paletteByteCount / 2; colorIndex++) {
                    ((unsigned short*)paletteData)[colorIndex] = paletteColor;
                }
                CleanInvalidateCacheRange(paletteData, paletteByteCount);
                LoadToTexturePalette(paletteData, paletteByteOffset, paletteByteCount);
            }
        }
    }

    MemoryUnmapTexturePalette();
    _Z30UnlockStagedTextureVRAMCopyingv();
}

#endif
