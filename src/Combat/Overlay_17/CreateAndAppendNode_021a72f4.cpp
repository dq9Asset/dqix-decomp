#include <globaldefs.h>
#include "Resource/GameResources.h"

void InitObj_021a7328(char* obj);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021a72f4  (semantic: CreateAndAppendNode_021a72f4)
extern "C" ARM void func_ov017_021a72f4(void* unused, int val) {
    GameResources* resources = func_ov017_0218b5b0();
    TailList020469b4* list = (TailList020469b4*)resources->unknown_ptr_array_36fc[0];
    char* node = (char*)resources->unknown_ptr_array_3afc[38];
    InitObj_021a7328(node);
    *(int*)(node + 0xc) = val;
    AppendNodeToTail(list, (TailNode020469b4*)node);
}
