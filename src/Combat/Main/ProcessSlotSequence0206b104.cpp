#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if defined(jpn)
extern "C" int func_02069430(void*, unsigned short);
extern "C" int func_02069444(void*, unsigned short);
extern "C" int func_020694a0(void*, unsigned short);
#endif

ARM bool IsHighByteFF02044494(void* obj, void* src);
int Dispatch02044420(void* obj, void* src);

// USA: func_0206b104  (semantic: ProcessSlotSequence0206b104)
extern "C" ARM void func_0206b104(MessageSystem* obj) {
#if defined(jpn)
    if ((obj->tokenStart == 0) | (obj->tokenCursor == 0)) return;
#else
    if (obj->tokenStart == 0 || obj->tokenCursor == 0) return;
#endif
    if (obj->tokenCount == 0) return;
    unsigned short* p;
#if defined(jpn)
    unsigned int i = obj->lineStart;
#else
    unsigned int i = obj->slotReleaseIndex;
#endif
    for (; i < obj->tokenCount; i++) {
        p = obj->firstLineBuffer + i;
#if defined(jpn)
        if (func_02069430(obj, *p)) {
#else
        if (IsHighByteFF02044494(obj, p)) {
#endif
#if defined(jpn)
            i += func_02069444(obj, *p);
#else
            i += Dispatch02044420(obj, p);
#endif
        } else {
#if defined(jpn)
            func_0206cb14(obj, 12, *p);
            func_0206cb14(obj, 6, *p);
#else
            DecrementSlotRef0206b198(obj, *p);
#endif
        }
    }
    obj->tokenCount = 0;
    obj->producedLength = 0;
    obj->lineStart = 0;
    obj->tokenIndex = 0;
}
