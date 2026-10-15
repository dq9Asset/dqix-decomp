#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_020421b0
ARM unsigned char* GetTableEntry020421b0(int idx) {
    return data_02107800.glyphAssets + (idx << 5);
}
