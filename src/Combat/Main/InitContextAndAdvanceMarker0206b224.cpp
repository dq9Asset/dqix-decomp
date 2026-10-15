#include <globaldefs.h>
#include "Resource/MessageSystem.h"

#if defined(jpn)
#define func_0206b224 func_0206cba0
enum { kInitialPad = 0x18, kBufferSize = 0x140 };
#else
enum { kInitialPad = 0x4c, kBufferSize = 0x280 };
#endif

#include "std_library_functions.h"

extern int StringLength_020d2ff0(const char* s);

// USA: func_0206b224  (semantic: InitContextAndAdvanceMarker0206b224)
extern "C" ARM void func_0206b224(MessageSystem* obj) {
    func_0206b104(obj);
    memset(obj->firstLineBuffer, 0, kBufferSize);
    memset(obj->secondLineBuffer, 0, kBufferSize);

#if defined(jpn)
    int skip = 1;
    unsigned short* base = obj->tokenCursor;
#else
    int skip = 1;
    char* base = obj->tokenCursor;
    unsigned char nextByte = base[1];
    if (nextByte == 0xff) {
        skip = 2;
    }
#endif
    obj->tokenStart = base + skip;
    obj->tokenCursor = base + skip;

    func_0206aa28(obj);
#if !defined(jpn)
    func_0206b974(obj, true, static_cast<char*>(obj->secondLineBuffer), obj->formatBuffer->text, 0xe3, 0, true, 1);
    int len = StringLength_020d2ff0(obj->formatBuffer->text);
    memcpy(obj->secondLineBuffer, obj->formatBuffer->text, len);
#endif
}
