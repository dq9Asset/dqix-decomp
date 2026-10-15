#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"

// USA: func_02046380  (semantic: InitLargeStruct_02046380)
extern "C" ARM void func_02046380(MessageSystem* obj) {
#if defined(jpn)
    obj->formatterCombatantId = -1;
    memset(obj->fixedTextBuffers[0], 0, 0x40);
    memset(obj->fixedTextBuffers[1], 0, 0x40);
    memset(obj->fixedTextBuffers[2], 0, 0x40);
    memset(obj->fixedTextBuffers[3], 0, 0x40);
    memset(obj->fixedTextBuffers[4], 0, 0x40);
    memset(obj->indexedNames, 0, 0x400);
    memset(obj->indexedValues, 0, 0x40);
    memset(obj->indexedNumberPaddingModes, 0, 0x10);
    memset(obj->indexedNumberWidths, 0, 0x10);
    obj->field77c = 0;
    obj->field7d1 = 0;
    obj->field7c0 = 0;
    obj->field238 = 0;
#else
    obj->cursor30 = -1;
    obj->cursor31 = -1;
    obj->formatterCombatantId = -1;
    memset(obj->fixedTextBuffers[0], 0, 0xc0);
    memset(obj->fixedTextBuffers[3], 0, 0x40);
    memset(obj->fixedTextBuffers[4], 0, 0x40);
    memset(obj->fixedTextBuffers[5], 0, 0x40);
    memset(obj->fixedTextBuffers[6], 0, 0x40);
    memset(obj->indexedNames, 0, 0x400);
    memset(obj->indexedValues, 0, 0x40);
    memset(obj->indexedNumberPaddingModes, 0, 0x10);
    memset(obj->indexedNumberWidths, 0, 0x10);

    obj->field77c = 0;
    obj->field7d1 = 0;
    obj->field7c0 = 0;
    obj->field238 = 0;

    for (int i = 0; i < 2; i++) {
        obj->actorNames[i] = NULL;
        obj->actionNames[i] = NULL;
        obj->targetNames[i] = NULL;
        obj->itemNames[i] = NULL;
        obj->monsterNames[i] = NULL;
    }

    obj->nameDescriptor28 = NULL;
    obj->field2c = 0;
    obj->flag19d5 = 0;
    obj->flag19d6 = 0;
    obj->flag19d7 = 0;
    obj->flag19d8 = 0;
#endif
}
