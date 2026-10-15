#include <globaldefs.h>
#include "Resource/MessageFrame.h"

extern char data_02114e54;
extern unsigned short data_02114e30;

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);

// USA: func_020e2918
ARM int GetField0x15UnlessInactive_020e2918(EntryManager020e2490* manager) {
    if (*(unsigned char*)(&data_02114e54 + 0x55) != 0
        || TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x1)
        || TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x400)
        || TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x200))
    {
        return manager->byte15;
    }
    return -1;
}
