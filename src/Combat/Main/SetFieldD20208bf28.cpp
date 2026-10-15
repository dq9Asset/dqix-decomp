#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Filesystem/BackgroundLoader.h"



// USA: func_0208bf28
ARM void SetFieldD20208bf28(MessageControlOwner* obj, int value, unsigned char b) {
    if (value < 0) return;
    obj->value = value;
    obj->field_dd = b;
    if (obj->handle >= 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->RemoveTask(obj->handle);
        obj->handle = -1;
    }
    obj->flags |= 0x20;
    obj->field_d6 = 0;
}
