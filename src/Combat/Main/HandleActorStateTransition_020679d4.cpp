#include <globaldefs.h>

#include "Resource/MessageSystem.h"

struct Obj0205eaa0;

#if defined(jpn)
extern "C" void func_0205dba0(MessageChoicePanel*);
#define InitBigStructVariant0205c840 func_0205dba0
#endif
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern char data_02108760;

// JPN: func_02069294
// USA: func_020679d4  (semantic: HandleActorStateTransition_020679d4)
ARM void MessageSystem::HandleActorStateTransition(int state) {
    switch (state) {
    case 0:
        func_0206b104(this);
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
#if defined(jpn)
        func_0206cbe8(this, 0xff16, this->tokenCursor);
#else
        InitOrReinitContext0206b2c8(this, 0xff16, this->tokenCursor);
#endif
        InitBigStructVariant0205c840(&this->choicePanel);
        this->b19cd = 1;
        this->stream40 = 0;
        return;
    case 1:
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
    case -2:
        this->w94c[2] = 1;
        func_0206b104(this);
#if defined(jpn)
        func_0206cbe8(this, 0xff17, this->tokenCursor);
#else
        InitOrReinitContext0206b2c8(this, 0xff17, this->tokenCursor);
#endif
        InitBigStructVariant0205c840(&this->choicePanel);
        this->b19cd = 1;
        this->stream40 = 0;
        return;
    default:
        return;
    }
}

#if defined(jpn)
#undef InitBigStructVariant0205c840
#endif
