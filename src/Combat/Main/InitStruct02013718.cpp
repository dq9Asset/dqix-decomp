#include <globaldefs.h>
#include "World/Zone3D.h"

extern "C" void func_020134e0(void* obj);

// USA: func_02013718
ARM void InitStruct02013718(Zone3D* zone, SafeAllocator* allocator, Foo0207df50* encoder) {
    func_020134e0(zone);
    zone->pAllocator_4c_ = allocator;
    zone->encoder = encoder;
    zone->textureImageMemory_ = 0;
    zone->texturePaletteMemory_ = 0;
    zone->unknown_474_ = 0;
    zone->unknown_82c_ = 0;
}
