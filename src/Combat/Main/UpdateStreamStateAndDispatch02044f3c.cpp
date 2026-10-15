#include <globaldefs.h>
#include "Resource/MessageSystem.h"

#if !defined(jpn)
extern "C" void func_02044d0c();
void PrepareEncodeStreamBuffer0204394c(Foo0207df50* encoder);

// USA: func_02044f3c
extern "C" ARM void func_02044f3c(MessageSystem* message, const char* text, int flag3) {
    message->b19bd = 1;
    RunStageSequence02067e98(message, text);
    if (message->b19cc == 0 && flag3 == 1) {
        message->b19ae = 0;
        message->b19af = 0;
        message->b19cd = 1;
        message->stream40 = 0;
        func_02044d0c();
    }
    message->b19cc = 0;
    message->b19ce = 0;
    if (flag3 == 1) {
        message->b19cc = 1;
    } else if (flag3 == 1) {
        message->b19ce = 1;
    }
    if (message->b19cc != 0) {
        message->b19cc = 1;
        message->b19ae = 0;
        message->b19af = 0;
        message->b19cd = 1;
        message->stream40 = 0;
    }
    if (message->b19ce != 0) {
        message->stream44 = 0;
        PrepareEncodeStreamBuffer0204394c(message->encoder);
    }
    message->cursor30 = -1;
    message->cursor31 = -1;
}
#endif
