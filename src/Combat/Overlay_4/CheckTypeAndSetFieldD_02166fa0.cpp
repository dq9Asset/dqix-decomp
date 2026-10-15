#include <globaldefs.h>
#include "Resource/MessageSystem.h"

namespace {
struct MessageChildNode { char prefix[0x34]; MessageControlOwner child; };
}

extern "C" int func_ov004_021666bc(void* a1, int* out);
void* CheckTypeAndReturnNode_02165e70_02165e70(void* a, int key);

// USA: func_ov004_02166fa0  (semantic: CheckTypeAndSetFieldD_02166fa0)
extern "C" ARM int func_ov004_02166fa0(void* a1) {
    int local;
    int key = func_ov004_021666bc(a1, &local);
    unsigned char b = *(unsigned char*)&local;

    void* node = CheckTypeAndReturnNode_02165e70_02165e70(a1, 7);
    if (node) {
        SetFieldD20208bf28(&static_cast<MessageChildNode*>(node)->child, key, b);
    }
    return 0;
}
