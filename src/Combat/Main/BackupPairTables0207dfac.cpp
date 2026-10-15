#include <globaldefs.h>
#include "Resource/PairTableEncoder.h"

void BackupPairTableToBuffer_020bb700(int* out);
void ReadGlobalPair020bb910(int* dst);

// USA: func_0207dfac
ARM void BackupPairTables0207dfac(Foo0207df50* obj) {
    BackupPairTableToBuffer_020bb700(obj->savedTable.values);
    ReadGlobalPair020bb910(obj->savedPair.values);
}
