#include <globaldefs.h>
#include "Resource/MessageSystem.h"
void ResetFoo02042fcc(Foo02042fcc*);

// USA: func_0205c790
ARM void InitBigStruct0205c790(MessageChoicePanel* obj) {
    InitSubstruct0205c73c(&obj->setup);
    InitChannelPair0205c53c(&obj->channels);
    ResetFoo02042fcc(&obj->bounds);

    obj->state = 0;
    obj->columnSpacing = 0x34;
    obj->rowSpacing = 0x10;
    obj->fielddc = 0;

    memset(obj->bufferE0, 0, 0x10);
    memset(obj->bufferF0, 0, 0x10);
    memset(obj->buffer100, 0, 0x10);
    memset(obj->buffer110, 0, 0x10);
    memset(obj->text, 0, sizeof(obj->text));
    memset(obj->offsets, 0, sizeof(obj->offsets));

    obj->textLength = 0;
    obj->choiceCount = 0;
    obj->showBounds = 0;
    obj->enabled = 0;
}
