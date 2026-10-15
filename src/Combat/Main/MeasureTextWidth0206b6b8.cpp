#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if defined(jpn)


// JPN: func_0206cf44
extern "C" ARM void func_0206cf44(MessageSystem* obj) {
    unsigned short* p = obj->tokenStart;
    unsigned short* end = obj->tokenCursor;
    int count = 0;
    while (p != end) {
        unsigned short token = *p;
        if (token == 0xff01 || token == 0xff0c || token == 0xff0d) break;
        if (token == 0xff18) count++;
        p++;
    }
    int glyphWidth = obj->w1864;
    int width = (count - 1) * glyphWidth + 12;
    int x = (0xc0 - width) >> 1;
    int left = x - 0x10;
    int right = 0xc0 - left;
    func_02043270(obj, 2, left, 0xfc, right);
}
#else
#include "std_library_functions.h"

// USA: func_0206b6b8
ARM void MeasureTextWidth0206b6b8(MessageSystem* obj) {
    char* p = obj->secondLineBuffer;
    int count = 0;

    for (;;) {
        if (static_cast<unsigned char>(*p) == 0) break;

        unsigned short ch2, ch;
        memcpy(&ch, p, 2);
        if ((ch & 0xff00) == 0xff00) {
            memcpy(&ch2, p, 2);
            if (ch2 == 0xff01 || ch2 == 0xff0c || ch2 == 0xff0d) break;
            if (ch2 == 0xff18) count++;
            p += 2;
        } else {
            int tableIdx = obj->b19dc;
            int advance = 1;
            FontCharacter* e = FindEntryByKey0204254c(p, tableIdx);
            if (e) advance = e->byteLength;
            p += advance;
        }
    }

    int glyphWidth = obj->w1864;
    int a = (count - 1) * glyphWidth + 8;
    a = (0xc0 - a) >> 1;
    int b = a - 0x10;
    int c = 0xc0 - b;
    func_02042b98(obj, 2, b, 0xfc, c);
}

#endif
