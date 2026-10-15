#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"

#include "Resource/PairTableEncoder.h"

#if defined(jpn)
#define PrepareEncodeStreamBuffer0204394c func_02044104
extern "C" ARM void func_02044104(Foo0207df50* obj);
enum { kStagingOffset = 0x700 };
#else
enum { kStagingOffset = 0 };
#endif

// USA: func_0204394c
ARM void PrepareEncodeStreamBuffer0204394c(Foo0207df50* obj) {
    void* buf = AllocateVRAMStagingMemory(0x3000);
    if (buf == NULL) {
        return;
    }

    int textureByteOffset = (obj->textureAllocationKey & 0xffff) * 8;
    memset(buf, 0, 0x3000);
    StageMemoryToVRAM(VRAMSubregion_TextureImage, buf, textureByteOffset + kStagingOffset, 0x3000, true, false);
    FreeVRAMStagingMemory(buf);
}
