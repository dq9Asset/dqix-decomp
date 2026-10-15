#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/MessageRenderResources.h"

// USA: func_0205a444
ARM void InitStruct0205a444(LoadTable* obj) {
    memset(&obj->resource00, 0, sizeof(obj->resource00));
    memset(&obj->resource24, 0, sizeof(obj->resource24));
    obj->mappingMode = 0;
    obj->records = 0;
    obj->field44 = 0;
    obj->capacity = 0;
    obj->recordCount = 0;
    obj->entryCount = 0;
    obj->animationEntries = 0;
    obj->subScreen = 1;
}
