#include <globaldefs.h>
#include "Resource/PairTableEncoder.h"

// USA: func_0207dfc8
ARM void CopyState0207dfc8(Foo0207df50* source, Foo0207df50* destination) {
    destination->liveTable = source->savedTable;
    destination->savedTable = source->savedTable;
    destination->textureBytes = source->textureBytes;
    destination->textureAllocationKey = source->textureAllocationKey;
    destination->livePair = source->savedPair;
    destination->savedPair = source->savedPair;
    destination->paletteBytes = source->paletteBytes;
    destination->paletteAllocationKey = source->paletteAllocationKey;
}
