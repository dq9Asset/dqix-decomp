#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/MessageSystem.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"

// JPN: func_0206cbe8
extern "C" ARM void func_0206cbe8(MessageSystem* context, unsigned short token, unsigned short* cursor) {
    MessageSystem* self = context;
    unsigned short* found = func_0206c730(context, token, cursor);
    if (found == NULL) {
        ReinitController02043204(context);
        func_02043124(context);
        return;
    }
    func_0206b104(context);
    memset(self->firstLineBuffer, 0, 0x140);
    memset(self->secondLineBuffer, 0, 0x140);
    self->tokenCursor = found;
    self->tokenStart = found;
    func_0206aa28(context);
    self->mode = 5;
}
#else

int StringLength_020d2ff0(const char* s);

// USA: func_0206b2c8
ARM void InitOrReinitContext0206b2c8(MessageSystem* obj, unsigned short token, char* cursor) {
    char* r = func_0206ac94(obj, token, cursor);
    if (r == NULL) {
        ReinitController02043204(obj);
        func_02043124(obj);
        return;
    }

    func_0206b104(obj);
    memset(obj->firstLineBuffer, 0, 0x280);
    memset(obj->secondLineBuffer, 0, 0x280);
    obj->tokenCursor = r;
    obj->tokenStart = r;
    obj->mode = 5;
    func_0206aa28(obj);
    func_0206b974(obj, true, static_cast<char*>(obj->secondLineBuffer), obj->formatBuffer->text, 0xe3, 0, true, 1);
    int len = StringLength_020d2ff0((const char*)obj->formatBuffer->text);
    memcpy(obj->secondLineBuffer, obj->formatBuffer->text, len);
}

#endif
