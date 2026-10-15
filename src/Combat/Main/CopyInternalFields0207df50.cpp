#include <globaldefs.h>
#include "Resource/PairTableEncoder.h"

// USA: func_0207df50
ARM void CopyInternalFields0207df50(struct Foo0207df50 *p) {
    p->savedTable = p->liveTable;
    p->savedPair = p->livePair;
}
