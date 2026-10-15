#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"

void Fill3WordsWithFF_020b0318(int* p);
int ValidateResourceLookup0205a1f0(void* a, void* b, int c);
extern "C" void func_020b0594(int local, int zero, int tier, void* obj);
extern "C" void func_020b0368(int local, int val44, int tier, void* obj);


// USA: func_0205aaf8
ARM int ValidateAndDispatchResource(LoadTable* obj, void* param2, int param3) {
    int local;
    int tier;
    Fill3WordsWithFF_020b0318(obj->resource00.words);
    if (ValidateResourceLookup0205a1f0(&local, param2, param3) != 0) {
        return 1;
    }
    tier = (obj->subScreen == 0) ? 1 : 2;
    if (obj->mappingMode == 4) {
        func_020b0594(local, 0, tier, obj);
    } else {
        func_020b0368(local, obj->field44, tier, obj);
    }
    return 0;
}
