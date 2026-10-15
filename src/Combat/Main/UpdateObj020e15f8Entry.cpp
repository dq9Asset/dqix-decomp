#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/MessageFrame.h"



extern "C" int func_020420e8(const char*, int);
#if defined(jpn)
extern "C" void func_0205b234(GlyphDestination0205b234*, short, short, const char*, unsigned char, unsigned char);
#else
extern "C" int func_0205b234(GlyphDestination0205b234*, short, short, const char*, unsigned char, unsigned char);
#endif

// USA: func_020e2310
ARM void UpdateObj020e15f8Entry_020e2310(MessageFrame* obj, int idx, int a2, int a3, const char* text, unsigned char a5, unsigned char a6)
{
    if (idx >= 0 && idx < 3) {
        #if defined(jpn)
        int ret = strlen(text);
        int advance = a5;
        int height = a5;
#else
        int ret = func_020420e8(text, a6);
        int advance = 1;
        int height = 0xc;
#endif
        StoreFourShorts(&obj->rectangles[idx], a2, a3, a2 + ret * advance, a3 + height);
    }
    if (static_cast<signed char>(obj->count) <= idx) {
        obj->count = idx + 1;
    }
    func_0205b234(obj->panel->object, a2, a3, text, a5, a6);
}
