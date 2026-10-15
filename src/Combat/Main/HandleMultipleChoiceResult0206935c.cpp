#include <globaldefs.h>

#if defined(jpn)
#include "Resource/MessageSystem.h"
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern char data_02108760;
extern "C" void func_0205dba0(MessageChoicePanel*);

// JPN: func_0206935c
ARM void MessageSystem::HandleMultipleChoiceResult(int result) {
    switch (result) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
        func_0206cbe8(this, 0xff56 + result, this->tokenCursor);
        break;
    case 6:
        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
    case -2:
        func_0206cbe8(this, 0xff5c, this->tokenCursor);
        break;
    default:
        return;
    }
    func_0205dba0(&this->choicePanel);
}
#endif
