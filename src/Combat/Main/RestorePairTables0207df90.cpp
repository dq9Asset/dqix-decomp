#include <globaldefs.h>
#include "Resource/PairTableEncoder.h"

void RestorePairTableFromBuffer_020bb740(int* out);
void WriteGlobalPair020bb92c(int* src);

// USA: func_0207df90
ARM void RestorePairTables0207df90(Foo0207df50* obj) {
    RestorePairTableFromBuffer_020bb740(obj->savedTable.values);
    WriteGlobalPair020bb92c(obj->savedPair.values);
}
