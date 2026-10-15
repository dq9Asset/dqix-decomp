#include <globaldefs.h>
#include "Resource/PairTableEncoder.h"

void BackupPairTableToBuffer_020bb700(int* out);
void ReadGlobalPair020bb910(int* dst);
extern "C" int func_020bb588(unsigned int size, int a, int b);
extern "C" int func_020bb7cc(unsigned int size, int a, int b);

// USA: func_0207de48  (semantic: InitializeTextureAndPaletteAllocationState0207de48)
extern "C" ARM void func_0207de48(Foo0207df50* obj, int a, int b) {
    BackupPairTableToBuffer_020bb700(obj->liveTable.values);
    obj->savedTable = obj->liveTable;
    ReadGlobalPair020bb910(obj->livePair.values);
    int remaining = a;
    obj->savedPair = obj->livePair;
    obj->textureAllocationKey = 0;

    while (remaining > 0) {
        if (remaining > 0x20000) {
            obj->textureAllocationKey = func_020bb588(0x20000, 0, 0);
            remaining -= 0x20000;
        } else {
            obj->textureAllocationKey = func_020bb588(remaining, 0, 0);
            remaining = 0;
        }
    }
    if (a != 0 && obj->textureAllocationKey == 0) a = 0;

    obj->paletteAllocationKey = 0;
    if (b != 0) {
        obj->paletteAllocationKey = func_020bb7cc(b, 0, 0);
    }
    if (b != 0 && obj->paletteAllocationKey == 0) b = 0;

    obj->textureBytes = a;
    obj->paletteBytes = b;
}
