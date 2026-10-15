#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Graphics/VRAMStaging.h"

struct State0204166c;
void Forward020416c0(struct State0204166c* s);



#if defined(jpn)
extern int data_0210773c;
extern int data_020e846c;
extern const char data_020efd90[];
#define data_021077fc data_0210773c
#define data_020e7af8 data_020e846c
extern "C" void func_02041bbc(MessageGlyphSlot*);
extern "C" int func_02043014(int, unsigned short*);
extern "C" void func_02046530(MessageSystem*, unsigned short*, int, int);
#else
extern int data_021077fc;
#endif
extern int data_020e7af8;

// USA: func_020432c4  (semantic: ResetCombatSlotsAndEncode020432c4)
extern "C" ARM void func_020432c4(MessageSystem* obj) {
    Foo0207df50* ptrField = obj->encoder;
    int i;

    if (ptrField != 0) {
        data_021077fc = (ptrField->paletteAllocationKey & 0xffff) << 3;
    }

    StageMemoryToVRAM(VRAMSubregion_TexturePalette, &data_020e7af8, data_021077fc, 0x20, true, true);

    for (i = 0; i < 0x80; i++) {
#if defined(jpn)
        func_02041bbc(&obj->glyphs[i]);
        obj->glyphReferences[i] = 0;
#else
        Forward020416c0(&obj->glyphs[i]);
        obj->glyphReferences[i] = 0;
#endif
    }

#if defined(jpn)
    if (obj->encoder) {
        obj->b195b = 0;
        unsigned short* entry = *(unsigned short**)(data_020efd90 + 0x64);
        for (int j = 0; j < 14; j++, entry++) {
            func_02046530(obj, entry, func_02043014(12, entry), 12);
            obj->glyphReferences[j] = 1;
        }
    }
#endif
    func_020439b0(obj, 0);
}
