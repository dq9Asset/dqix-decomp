#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Filesystem/FileIO.h"
#include "System/Memory.h"
#include "std_library_functions.h"

void ReleaseBattleBuffers020a39d8(SafeAllocator* alloc);
extern "C" void func_020c9be0(void);

#if defined(jpn)
extern const char data_020f1bf4[];
#else
extern const char data_020f1a9c[];
extern const char data_020f1ab0[];
#endif

enum { kLanguageOffsets = offsetof(GameResources, pTMapLanguageOffsets) };

// JPN: func_020a55a0
// USA: func_020a3844  (semantic: LoadTreasureMapLanguageBuffers_020a3844)
extern "C" ARM int func_020a3844(SafeAllocator* alloc) {
    GameState* battleStruct = GameState::GetInstance();
    int base = ((int)func_ov017_0218b5b0());
    unsigned char* word = battleStruct->GetTreasureMapLanguageData();
    if (word != 0 || *(void**)(base + kLanguageOffsets) != 0) {
        ReleaseBattleBuffers020a39d8(alloc);
    }

    unsigned char* buf = (unsigned char*)alloc->Allocate(0x2000);
    unsigned char* buf2 = (unsigned char*)alloc->Allocate(0x44);
    *(unsigned char**)(base + kLanguageOffsets) = buf2;

    unsigned int fileSize = 0;
#if defined(jpn)
    if (!LoadFileIntoMemory(data_020f1bf4, buf, &fileSize))
        return 0;
#else
    BackgroundLoader::AddLockGlobal();
    void* extracted = ExtractFileFromGP2(data_020f1a9c, data_020f1ab0, &fileSize);
    memcpy(buf, extracted, fileSize);
    if (fileSize > 0x2000) {
        func_020c9be0();
    }
#endif

    unsigned int srcOff = 0;
    unsigned int count = 0;
    VectorizedInvertedMemcpy(buf, &count, 4);
    srcOff += 4;

    for (unsigned int i = 0; i < count; i++) {
        unsigned char* base4000 = (unsigned char*)base + 0x4000;
        VectorizedInvertedMemcpy(buf + srcOff, *(unsigned char**)(base4000 + kLanguageOffsets - 0x4000) + i * 4, 4);
        srcOff += 4;
    }

#if !defined(jpn)
    BackgroundLoader::RemoveLockGlobal();
#endif
    battleStruct->SetTreasureMapLanguageDataPtr(buf);
    return 1;
}
