#include <globaldefs.h>
#include "Combat/MapDisplay.h"

extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_020200c0(int index, Struct0205a198* record);

// USA: func_02020aa0
ARM void InitFourEntrySlots02020aa0(MapDisplay* obj) {
    char i;
    func_020dc7e8(6, -1);
    func_020dc7e8(7, -1);
    for (i = 0; i < 4; i++) {
        func_020200c0(i, &obj->records[0]);
    }
}
