#include "globaldefs.h"

#if defined(jpn)
enum { WindowOffset = 0xe20, ModeOffset = 0x1a80, HeightPreset = 22, PositionPreset = 14, PositionMode = 12, PositionX = 14, LongAnimationPreset = 41 };
#define data_ov002_0216cb48 data_ov002_0216d150
#else
enum { WindowOffset = 0xec8, ModeOffset = 0x1bb8, HeightPreset = 21, PositionPreset = 13, PositionMode = 11, PositionX = 17, LongAnimationPreset = 38 };
#endif

struct Overlay2LayoutPreset {
    unsigned char id, width, height;
    signed char x, y;
    unsigned char extra0, extra1;
};
struct Overlay2LayoutParameters {
    unsigned char unknown00[0xa0];
    short x, y, inputX, inputY;
    short width, height, extra0, extra1;
    unsigned char unknownB0, preset, unknownB2[3], active, unknownB6, frames;
    inline void setSize(short a, short b) { width = a; height = b; }
    inline void setPosition(short a, short b) { x = a; y = b; }
    inline void setExtra(short a, short b) { extra0 = a; extra1 = b; }
};
struct Overlay2LayoutState {
    unsigned char unknown00[WindowOffset];
    Overlay2LayoutParameters parameters;
    unsigned char unknownAfterParameters[ModeOffset - WindowOffset - sizeof(Overlay2LayoutParameters)];
    int mode;
};
extern "C" const Overlay2LayoutPreset data_ov002_0216cb48[];
extern "C" void func_ov002_02156080(void*, short*, short*);

// USA: func_ov002_0215be00
// JPN: func_ov002_0215cf30
extern "C" ARM void func_ov002_0215be00(Overlay2LayoutState* state, int id, short inputX, short inputY) {
    for (int i = 0; data_ov002_0216cb48[i].id != 255; ++i) {
        const Overlay2LayoutPreset* preset = &data_ov002_0216cb48[i];
        if (preset->id != id) continue;
        Overlay2LayoutParameters* parameters = &state->parameters;
        parameters->preset = preset->id;
        parameters->inputX = inputX;
        parameters->inputY = inputY;
        parameters->setSize(preset->width, preset->height);
        parameters->setPosition(preset->x, preset->y);
        parameters->setExtra(preset->extra0, preset->extra1);
        parameters->active = 1;
        if (preset->id == HeightPreset) {
            short entries[9], height;
            short displacement = 0;
            func_ov002_02156080(state, entries, &height);
            if (height < 8) {
                displacement = (8 - height) * 2;
            } else {
                parameters->setSize(preset->width, preset->height + 1);
            }
            if (displacement < 0) displacement = 0;
            parameters->setPosition(preset->x, preset->y - displacement);
        }
        if (preset->id == PositionPreset && state->mode == PositionMode) {
            parameters->x = PositionX;
            parameters->y = 16;
        }
        int frames = 10;
        if (id == LongAnimationPreset) frames = 12;
        parameters->frames = frames;
        break;
    }
}

#if defined(jpn)
#undef data_ov002_0216cb48
#endif
