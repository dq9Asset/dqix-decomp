#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"
#include "std_library_functions.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
int StringLength_020d2ff0(const char*);

// JPN: func_0206c570
extern "C" ARM void func_0206c570(MessageSystem* p, const char* src) {
    if (src == NULL) return;
    {
        void* buffer = p->textBuffer;
        memcpy(buffer, src, (p->tokenLength = StringLength_020d2ff0(src)));
    }
    {
        unsigned short* buffer = static_cast<unsigned short*>(p->textBuffer);
        p->tokenCursor = buffer;
        p->tokenStart = buffer;
    }
    memset(p->firstLineBuffer, 0, 0x140);
    memset(p->secondLineBuffer, 0, 0x140);
    func_0206aa28(p);
}
#else

extern int StringLength_020d2ff0(const char* s);



// USA: func_0206a974
ARM void InitContextString0206a974(MessageSystem* p, const char* src, int boxWidth) {
    if (src == 0) return;
    {
        void* buf = p->textBuffer;
        memcpy(buf, src, (p->tokenLength = StringLength_020d2ff0(src)));
    }
    {
        char* buf2 = static_cast<char*>(p->textBuffer);
        p->tokenCursor = buf2;
        p->tokenStart = buf2;
    }
    memset(p->firstLineBuffer, 0, 0x280);
    memset(p->secondLineBuffer, 0, 0x280);
    func_0206aa28(p);
    func_0206b974(p, true, static_cast<char*>(p->secondLineBuffer), p->formatBuffer->text, boxWidth, 0, true, 1);
    {
        int len2 = StringLength_020d2ff0(p->formatBuffer->text);
        memcpy(p->secondLineBuffer, p->formatBuffer->text, len2);
    }
}

#endif
