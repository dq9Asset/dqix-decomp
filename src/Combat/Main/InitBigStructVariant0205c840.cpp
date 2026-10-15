#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if !defined(jpn)
extern "C" void func_020462d0(MessageSystem*, unsigned short*, int);

// USA: func_0205c840
ARM void InitBigStructVariant0205c840(MessageChoicePanel* obj) {
    MessageSystem* base = GetGlobalField0x1c020421a0();
    base->drawEnabled = 0;

    InitSubstruct0205c73c(&obj->setup);
    ForwardInitChannelPair0205c564(&obj->channels);
    ResetFoo02042fcc(&obj->bounds);

    obj->state = 0;

    if (obj->choiceCount != 0) {
        MessageSystem* g = GetGlobalField0x1c020421a0();
        for (int i = 0; i < obj->choiceCount; i++) {
            unsigned short idx = obj->offsets[i];
            func_020462d0(g, obj->text + idx, 0x100);
        }
    }

    memset(obj->text, 0, sizeof(obj->text));
    memset(obj->offsets, 0, sizeof(obj->offsets));

    obj->textLength = 0;
    obj->choiceCount = 0;
    obj->showBounds = 0;
    obj->enabled = 0;
}

#endif
