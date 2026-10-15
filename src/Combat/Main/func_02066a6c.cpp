#include <globaldefs.h>

#include "Resource/MessageSystem.h"

void GetField440XY_02066cc0(MessageSlotController* controller, short* x, short* y);
void EmitScaledField0x440_0202f404(MessageSlotController* controller, int x, int y);
int GetWordFromTable02042648(int index);
void SetIntIntShortAt0xc_02066ce0(MessageGlyphSlot* slot, int x, int y, short depth);
extern "C" void func_020417b0(MessageGlyphSlot* slot, int color, Rect02042c54* clip, int alpha);

#if !defined(jpn)

// USA: func_02066a6c
extern "C" ARM void func_02066a6c(MessageSystem* obj, int absolute) {
    if (!obj->b19c4) return;
    MessageSlotController* holder = &obj->controller;
    int count;
    unsigned short* text;
    MessageGlyphSlot* glyph;
    int i;
    int spacing;
    count = 0;
    text = NULL;
    if (obj->b19c3) {
        text = obj->lineGlyphSlots;
        count = obj->lineGlyphCount & 255;
    }
    if (text) {
        int offsetX, offsetY;
        short x, y;
        LoadStateBytePair0206b804(obj, &offsetX, &offsetY);
        GetField440XY_02066cc0(holder, &x, &y);
        y -= 19;
        holder->currentBounds = &obj->foo930;
        if (holder->currentBounds) {
            holder->currentBounds->field10 = 4096;
            holder->currentBounds->field14 = 4096;
        }
        if (holder->currentBounds) holder->currentBounds->state = 2;
        if (absolute) SetSubstructXY02042c24(holder, x, y);
        else {
            SetSubstructXY02042c24(holder, (short)(x + offsetX), (short)(y + offsetY));
            EmitScaledField0x440_0202f404(holder, 1, 0);
        }
        short remainder = 8 - (obj->captionWidth & 7);
        x += (remainder + 18) >> 1;
        y += 5;
        unsigned char fontWidth = GetWordFromTable02042648(obj->b19dc);
        for (i = 0; i < count; i++) {
            spacing = fontWidth + 1;
            unsigned short code = text[i];
            if ((code & 0xff00) == 0xff00) {
                if (code == 0xff01) break;
                if (code == 0xff19) { x += spacing; continue; }
            }
            glyph = &obj->glyphs[code];
            if (absolute) func_020654b8(obj, obj->textContext, glyph, x, y, 15);
            else {
                SetIntIntShortAt0xc_02066ce0(glyph, x, y, 0);
                func_020417b0(glyph, obj->textColor, 0, 31);
            }
            if (glyph->character) x += glyph->character->width + 1;
        }
    }
    holder->currentBounds = &obj->primaryBounds;
}

#endif
