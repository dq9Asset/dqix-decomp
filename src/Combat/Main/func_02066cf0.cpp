#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"
#include "Resource/MessageSystem.h"
#include "Resource/MessageFrame.h"

void EmitScaledField0x440_0202f404(MessageSlotController* controller, int x, int y);
bool IsCommandInRange02067a9c(void* unused, void* token);
void MeasureTextWidth0206b6b8(MessageSystem* messages);
int GetWordFromTable02042648(int index);
int LookupKeyValue020425e4(int left, int right, int fontIndex);
void UpdateObj020e15f8Entry_020e2310(MessageFrame* frame, int index, int x, int y, const char* text, unsigned char color, unsigned char font);
void CallFunc0205c96cIfMode6AndFlag_02044530(MessageSystem* messages, int flag);
void Forward02044830(void* unused, int* x, int* y);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, int c, int d);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_02066a6c(MessageSystem* messages, int flag);
extern "C" void func_020e2110(MessageFrame* frame);
extern "C" void func_020675fc(MessageSystem* messages);
extern "C" void func_0204459c(MessageSystem* messages, int flag);
extern "C" void func_020653e4(int x, int y);

extern short data_020e7e54[];
extern short data_020e7e3c[];
extern int data_021077fc;

#if !defined(jpn)

// USA: func_02066cf0
extern "C" ARM void func_02066cf0(MessageSystem* obj, int flag) {
    MessageGlyphSlot* glyph;
    int x;
    int y;
    unsigned int pos;
    unsigned char width;

    if (obj->b19cc) return;

    int offsetX, offsetY;
    LoadStateBytePair0206b804(obj, &offsetX, &offsetY);

    if ((obj->active && obj->b19b1) || obj->compositeBoundsEnabled) {
        if (obj->compositeBoundsEnabled) {
            if (IsField440Empty_0205ce28(&obj->controller)) {
                SetupField440Type1(&obj->controller);
                UpdateTimedState0202f380(&obj->controller, 1);
            }
        }

        if (obj->active && obj->b19b1) {
            func_02066a6c(obj, flag);
        }

        short boxX, boxY;
        GetField440XY_02066cc0(&obj->controller, &boxX, &boxY);
        SetSubstructXY02042c24(&obj->controller, (short)(boxX + offsetX), (short)(boxY + offsetY));

        if (flag == 0) {
            if (obj->frame) {
                func_020e2110(obj->frame);
            } else {
                EmitScaledField0x440_0202f404(&obj->controller, 1, 1);
            }
        }

        SetSubstructXY02042c24(&obj->controller, boxX, boxY);
    }

    if (!obj->active) return;
    func_020675fc(obj);

    Rect02042c54* clip = 0;
    if (obj->clipEnabled == 1) {
        clip = &obj->textRectangle;
    }

    if (!obj->tokenStart || !obj->tokenCursor) return;
    if (!obj->tokenCount) return;

    CallFunc0205c96cIfMode6AndFlag_02044530(obj, flag);

    int lineX[16];
    int lineY[16];
    int line = 0;
    __clear(lineX, sizeof(lineX));
    __clear(lineY, sizeof(lineY));

    int blend = 0x1f;
    int alpha = 0x1f;
    if (obj->b195b & 4) {
        alpha = obj->w9b0 >> 16;
        if (flag != 0) {
            alpha &= 0x1f;
            if (alpha != 0) {
                blend = 0xf - (alpha >> 1);
            }
            ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04000050, 8, 1, alpha, blend);
        }
    }

    unsigned short ch;
    if (obj->b19c5) {
        ch = obj->firstLineBuffer[obj->tokenIndex];
        if (!IsCommandInRange02067a9c(obj, &ch)) return;
    }

    if (obj->b195b & 0x40) {
        MeasureTextWidth0206b6b8(obj);
    }

    if (obj->b19b8) {
        Forward02044830(obj, lineX, lineY);
        for (int i = 0; i < 0x10; i++) {
            lineY[i] = obj->popupPosition.y;
        }
    } else {
        for (int i = 0; i < 0x10; i++) {
            lineX[i] = obj->popupPosition.x + 0xc;
            lineY[i] = obj->popupPosition.y;
        }
    }

    unsigned char prevWidth;
    unsigned int end = obj->tokenIndex;
    pos = obj->lineStart;
    unsigned int minStart = obj->slotReleaseIndex;
    prevWidth = 0xff;
    if (pos < minStart) pos = minStart;

    unsigned char spacing = GetWordFromTable02042648(obj->b19dc);
    y = lineY[0] - obj->w1868;
    x = lineX[0];

    for (; pos < end; pos++) {
        ch = obj->firstLineBuffer[pos];

        if (IsHighByteFF02044494(obj, &ch)) {
            if (IsCommandInRange02067a9c(obj, &ch)) {
                break;
            }
            if (ch == 0xff18) {
                int lineHeight = obj->w1864;
                x = lineX[line + 1];
                line++;
                y += lineHeight;
                prevWidth = 0xff;
            } else if (ch == 0xff19) {
                x += spacing + 1;
                prevWidth = 0xff;
            }
            continue;
        }

        glyph = &obj->glyphs[ch];
        width = glyph->characterIndex;
        x += LookupKeyValue020425e4(prevWidth, width, obj->b19dc);
        prevWidth = width;

        if (flag != 0) {
            if (obj->stream40 <= pos) {
                func_020654b8(obj, obj->textContext, glyph, (short)x, (short)(y + 2), 0xf);
            }
        } else if (obj->b19ce) {
            if (obj->stream44 != obj->tokenIndex) {
                unsigned char* staging = static_cast<unsigned char*>(AllocateVRAMStagingMemory(0x3000));
                if (staging != 0) {
                    unsigned char j;
                    int vramOffset = (int)((obj->encoder->textureAllocationKey << 16) >> 13);
                    unsigned char table = obj->b19dc;
                    FontCharacter* metrics = glyph->character;

                    if (metrics) {
                        unsigned char effects = GetGlobalField0x1c020421a0()->b195b;
                        if (effects & 0x80) {
                            for (j = 0; j < 4; j++) {
                                func_02045864(data_020e7e54[j] + (short)x, data_020e7e3c[j] + (short)(y - 0x74),
                                              metrics, staging, 0x100, 0x60, 0xf, table);
                            }
                            func_02045864((short)x + 1, (short)(y - 0x74) + 1, metrics, staging, 0x100, 0x60, 0xf, table);
                        } else if (effects & 2) {
                            short sy = y - 0x74;
                            short sx = x;
                            func_02045864(sx + 1, sy + 1, metrics, staging, 0x100, 0x60, 0xf, table);
                            func_02045864(sx, sy, metrics, staging, 0x100, 0x60, 0xf, table);
                        } else {
                            func_02045864((short)x, (short)(y - 0x74), metrics, staging, 0x100, 0x60, 0xf, table);
                        }
                    }

                    StageMemoryToVRAM(VRAMSubregion_TextureImage, staging, vramOffset, 0x3000, true, false);
                    FreeVRAMStagingMemory(staging);
                }
            }
        } else if (obj->frame) {
            const char* text = GetField0OfSubstructAt0x18(glyph);
            UpdateObj020e15f8Entry_020e2310(obj->frame, 0, x, y - 0x74, text, 0xf, obj->b19dc);
        } else {
            SetIntIntShortAt0xc_02066ce0(glyph, x, y, 0);
            func_020417b0(glyph, obj->textColor, clip, alpha);
        }

        if (glyph->character) {
            x += glyph->character->width + 1;
        }
    }

    func_0204459c(obj, flag);
    obj->stream40 = end;

    if (!obj->b19ce) return;
    Foo0207df50* texture = obj->encoder;
    if (!texture) return;

    unsigned int texOffset = texture->textureAllocationKey << 16;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x04000470 = 0x74000;
    *(volatile unsigned int*)0x04000470 = 0x400000;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x04000470 = 0x80000;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0xfffff000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x040004c0 = 0x7fffffff;
    *(volatile unsigned int*)0x040004c4 = 0x4210;
    *(volatile unsigned int*)0x040004a8 = 0x6e500000u | (texOffset >> 16);
    *(volatile unsigned int*)0x040004ac = (unsigned int)data_021077fc >> 4;
    *(volatile unsigned int*)0x040004a4 = 0x3e1f00c0;

    *(volatile unsigned int*)0x0400046c = 0x100000;
    *(volatile unsigned int*)0x0400046c = 0x80000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = 0x7fff;

    int size = 0x80;
    float t = 0.0f;
    int scaledT = (int)(size * t);
    float comp = 1.0f - t;
    scaledT = scaledT << 12;
    func_020653e4(0, scaledT);

    unsigned int packed1 = ((unsigned int)(unsigned short)(int)(4096.0f * comp)) << 16;
    *(volatile unsigned int*)0x0400048c = packed1;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0x100000, scaledT);

    unsigned int packed2 = ((unsigned int)(unsigned short)(int)(4096.0f * comp)) << 16;
    packed2 |= 0x1000;
    *(volatile unsigned int*)0x0400048c = packed2;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0x100000, 0x80000);

    *(volatile unsigned int*)0x0400048c = 0x1000;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0, 0x80000);

    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
}

#endif
