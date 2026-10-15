#include <globaldefs.h>

#include "Resource/MessageSystem.h"

struct Obj0205eaa0;

#if defined(jpn)
extern "C" void func_0205dba0(MessageChoicePanel*);
#define InitBigStructVariant0205c840 func_0205dba0
#endif
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern char data_02108760;

// JPN: func_0206917c
// USA: func_020678bc  (semantic: DispatchStateChange_020678bc)
ARM void MessageSystem::DispatchStateChange(int state) {
    int idx = this->tokenIndex;
    unsigned short* table = this->firstLineBuffer;
    unsigned short value = table[idx];
    int isFF06 = (value == 0xff06);
    int isFF07 = (value == 0xff07);

    switch (state) {
    case 0:
        func_0206b104(this);
        if (!isFF06) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        }
#if defined(jpn)
        func_0206cbe8(this, 0xff14, this->tokenCursor);
#else
        InitOrReinitContext0206b2c8(this, 0xff14, this->tokenCursor);
#endif
        InitBigStructVariant0205c840(&this->choicePanel);
        this->b19cd = 1;
        this->stream40 = 0;
        return;
    case 1:
        if (!isFF06 && !isFF07) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        }
    case -2:
        this->w94c[2] = 1;
        func_0206b104(this);
#if defined(jpn)
        func_0206cbe8(this, 0xff15, this->tokenCursor);
#else
        InitOrReinitContext0206b2c8(this, 0xff15, this->tokenCursor);
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
