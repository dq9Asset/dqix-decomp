#include <globaldefs.h>
#include "Resource/MessageFrame.h"

#if defined(jpn)
extern char data_020f2d2c[];
extern char data_020f2d31[];
enum { kFirstFont = 12, kFirstStyle = 9, kSecondFont = 12, kSecondStyle = 11 };
#else
enum { kFirstFont = 9, kFirstStyle = 1, kSecondFont = 11, kSecondStyle = 1 };
#endif

#if defined(jpn)
#define func_020e1cdc func_020e38d4
#endif
const char* CallFunc020e0434With02153694_020e51cc(int);
extern "C" int func_020420e8(const char*, int);
void FreeVRAMStagingMemory(const void*);
// USA: func_020e1cdc
extern "C" ARM int func_020e1cdc(MessageFrame* obj, int arg) {
    if (!obj->panel) return 1;
    obj->panel->x = 0xc2;
    obj->panel->y = 0x48;
    obj->panel->width = 0x3c;
    obj->panel->height = 0x2c;
#if !defined(jpn)
    const char* first = CallFunc020e0434With02153694_020e51cc(27);
    const char* second = CallFunc020e0434With02153694_020e51cc(28);
    int width = func_020420e8(first, 1);
    int otherWidth = func_020420e8(second, 1);
    if (width < otherWidth) width = otherWidth;
    int span = width + 24;
    obj->panel->x = 256 - (span + 2);
    obj->panel->width = span;
#endif
    func_020e1b2c(obj, arg);
    if (func_020e1f1c(obj)) {
        obj->count = 0;
        func_020e2110(obj);
#if defined(jpn)
        UpdateObj020e15f8Entry_020e2310(obj, 0, 12, 8, data_020f2d2c, kFirstFont, kFirstStyle);
        UpdateObj020e15f8Entry_020e2310(obj, 1, 12, 24, data_020f2d31, kSecondFont, kSecondStyle);
#else
        UpdateObj020e15f8Entry_020e2310(obj, 0, 12, 8, first, kFirstFont, kFirstStyle);
        UpdateObj020e15f8Entry_020e2310(obj, 1, 12, 24, second, kSecondFont, kSecondStyle);
#endif
        func_020e23f4(obj);
        if (obj->stagingBuffer) FreeVRAMStagingMemory(obj->stagingBuffer);
        return 0;
    }
    return 1;
}
