#include <globaldefs.h>
#include "Resource/MessageSystem.h"

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24_02012a84(unsigned char*, int*, int*);
extern "C" int func_0205bd78(Struct_0205bbcc* p, int b, int c);


// USA: func_0205bc2c
ARM int UpdateActiveState0205bc2c(Struct_0205bbcc* obj, int) {
    int v1, v2;

    if (obj->base.count == 0) return 0;

    SelectCoordsByFlag0x24_02012a84(&data_02114e54, &v1, &v2);

    if ((&data_02114e54)[0x55] != 0 && obj->field4e == 0) {
        int prevField30;

        obj->field4e = 1;
        prevField30 = obj->selectedIndex;
        obj->selectedIndex = func_0205bd78(obj, v1, v2);
        if (obj->selectedIndex < 0) {
            obj->field4e = 0;
            return 0;
        }
        obj->field4c = 1;
        if (prevField30 != obj->selectedIndex) obj->field4c = 0;
        return 1;
    }

    obj->field4c = 0;
    obj->field4e = 0;
    return 0;
}
