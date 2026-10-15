#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"
#include "Resource/MessageSystem.h"

#define REG_BG_SCROLL_020439b0 (*(volatile unsigned int*)0x04000018)
#define REG_DISPLAY_020439b0 (*(volatile unsigned int*)0x04000000)

void LoadStateBytePair0206b804(MessageSystem* obj, int* out1, int* out2);
#if defined(jpn)
#define ZeroFourHalfwords02044074 func_0204483c
extern "C"
#endif
void ZeroFourHalfwords02044074(struct Struct02044074* s);
#if defined(jpn)
#define func_02042b98 func_02043270
#define func_02043600 func_02043de0
#define func_020437bc func_02043f88
#endif
void SetFourHalfwords(struct Struct0204408c* s, short x, short y, short z, short w);
extern "C" void func_02043600(void* a, void* box);
#include "Resource/MessageUpdate.h"

extern "C" void func_020437bc(void* buf, void* box, int index);

#if defined(jpn)
#define PrepareEncodeStreamBuffer0204394c func_02044104
#endif

struct Entry020e2cc4;
void SetEntryEnabled020e2cc4(struct Entry020e2cc4* obj, int enabled);

struct Obj02041754;
void DisableField16Bit002041754(struct Obj02041754* obj);
void ClearBitInArray_02042af4(int unused, unsigned char* arr, int index);

struct Rect020e2d2c;
void SetRectFromPosAndSize(struct Rect020e2d2c* s, int a, int b, int c, int d);

struct Entry020e2c34;
void UpdateAndDrawEntry020e2c34(struct Entry020e2c34* obj);

struct Struct02044074 { unsigned short x, y, z, w; };
struct Struct0204408c { short x, y, z, w; };
union Rect020439b0 { Struct02044074 zero; Struct0204408c bounds; };

struct MapTables020439b0 { short otherMap[0x400]; short tiles[0x400]; };
// USA: func_020439b0
extern "C" ARM void func_020439b0(MessageSystem* self, int flag) {
    MessageSystem* controller = self;
    int dx, dy;
    Rect020439b0 mainBounds, targetBounds, otherBounds;

    if (controller->b19cc != 0) {
        LoadStateBytePair0206b804(self, &dx, &dy);
        func_02044c74(self, self->textContext);

        MessageTextContext* stream = self->textContext;
        unsigned char* streamValue = stream->stagingBuffer;
        if (streamValue != 0) {
            stream->stagingBuffer = streamValue;

            controller->b19cc = 0;
            func_02066cf0(self, 1);
            controller->b19cc = 1;
            if (controller->b19c0 != 0) {
                controller->stream40 = 0;
            }

            ZeroFourHalfwords02044074(&mainBounds.zero);
            ZeroFourHalfwords02044074(&targetBounds.zero);
            ZeroFourHalfwords02044074(&otherBounds.zero);

            if (controller->active != 0 && controller->b19b1 != 0) {
                goto prepareBounds;
            }
            if (self->compositeBoundsEnabled != 0) {
            prepareBounds:
                if (controller->b19b1 != 0) {
                    func_02042b98(self, 2, 0x74, 0xfc, 0x4a);
                    SetFourHalfwords(&mainBounds.bounds, dx + 2, dy + 0x74, 0xfc, 0x4a);
                    func_02043600(self->textContext, &mainBounds);
                    SetFourHalfwords(&mainBounds.bounds, 2, 0x74, 0xfc, 0x4a);

                }

                if (controller->b19c4 != 0 && controller->b19c3 != 0) {
                    MessageSlotController* holder = &self->controller;
                    holder->currentBounds = &self->foo930;
                    int cond = (holder->currentBounds != 0) ? (holder->currentBounds->state == 2) : 0;
                    if (cond) {
                        short sx, sy, sz, sw;
                        if (holder->currentBounds != 0) {
                            sx = holder->currentBounds->x;
                            sy = holder->currentBounds->y;
                        }
                        if (holder->currentBounds != 0) {
                            sz = holder->currentBounds->width;
                            sw = holder->currentBounds->height;
                        }
                        SetFourHalfwords(&targetBounds.bounds, sx + dx, sy + dy, sz, sw);
                        func_02043600(self->textContext, &targetBounds);
                        SetFourHalfwords(&targetBounds.bounds, sx, sy, sz, sw);
                    }
                    holder->currentBounds = &self->primaryBounds;
                }

                if (controller->mode == 6) {
                    if (self->choiceEnabled != 0 && self->choicePanel.showBounds != 0) {
                        SetFourHalfwords(&otherBounds.bounds, self->choicePanel.bounds.x, self->choicePanel.bounds.y,
                            self->choicePanel.bounds.width, self->choicePanel.bounds.height);
                        func_02043600(self->textContext, &otherBounds);
                    }
                }
            }

            MessageTextContext* updatedStream = self->textContext;
            if (updatedStream != 0) {
                short i;
                int base;
                unsigned char* val;
                short count;
                int step;
                short sx = updatedStream->x;
                short sy = updatedStream->y;
                short sw = updatedStream->width;
                count = updatedStream->count;
                base = (sx + (sy << 5)) << 5;
                val = updatedStream->stagingBuffer;
                i = 0;
                for (; i < count; i++) {
                    step = sw << 5;
                    StageMemoryToVRAM(VRAMSubregion_MainBG3Character, (const void*)val, base, step, 1, 0);
                    val += step;
                    base += 0x400;
                }
            }

            int oldX = controller->w94c[0];
            int oldY = controller->w94c[1];
            REG_BG_SCROLL_020439b0 = ((-oldX) & 0x1ff) | (((-oldY) << 16) & 0x1ff0000);
            controller->w94c[0] = dx;
            controller->w94c[1] = dy;

            if (controller->mode != 1 && controller->mode != 0) {
                memset(data_02107800.glyphPixels, 0, 0x800);

                if (controller->active != 0 && controller->b19b1 != 0) {
                    goto stageBounds;
                }
                if (self->compositeBoundsEnabled != 0) {
                stageBounds:
                    if (controller->b19b1 != 0) {
                        void* rbuf = data_02107800.glyphPixels;
                        func_020437bc(rbuf, &mainBounds, 0);
                        func_020437bc(rbuf, &targetBounds, 1);
                        func_020437bc(rbuf, &otherBounds, 2);
                        StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, rbuf, 0, 0x800, 1, 0);
                    }
                }

                if (controller->b19b1 == 0) {
                    StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, data_02107800.glyphPixels, 0, 0x800, 1, 0);
                }

                if (!(self->lineStart != controller->tokenIndex && controller->active != 0)) {
                    MapTables020439b0* buf = (MapTables020439b0*)data_02107800.glyphPixels;
                    unsigned short i;
                    for (i = 0; i < 0x100; i++) {
                        buf->tiles[i] = 0;
                    }
                    for (unsigned short tableIndex = 0x100; tableIndex < 0x300; tableIndex++) {
                        buf->tiles[tableIndex] = (short)tableIndex;
                    }
                    StageMemoryToVRAM(VRAMSubregion_MainBG3Screen, buf->tiles, 0, 0x800, 1, 0);
                }
            }

            REG_DISPLAY_020439b0 = (REG_DISPLAY_020439b0 & ~0x1f00) | 0x1d00;
        }

        FreeVRAMStagingMemory(self->textContext->stagingBuffer);

        if (controller->active == 0) {
            InitCombatSlots02043040(self);
            func_02043124(self);
            ResetControllerState020430b0(self);
        }
    }

    if ((
#if defined(jpn)
            controller->flags17ff.streamMode
#else
            controller->b19ce
#endif
        ) != 0 && controller->stream44 == 0) {
        PrepareEncodeStreamBuffer0204394c(controller->encoder);
    }
    {
        int i;
        for (i = 0; i < 2; i++) {
            SetEntryEnabled020e2cc4((Entry020e2cc4*)&controller->entries[i], 0);
        }
    }

    if (flag != 0 && controller->active == 0) return;
    {
        void* encoder = controller->encoder;
        if (encoder != 0) {
            MessageGlyphSlot* entry;
            int j;
            for (j = 0; j < 0x80; j++) {
                if (controller->glyphReferences[j] != 0) {
                    entry = &controller->glyphs[j];
                    if (entry->pendingUpload) {
                        if (controller->b19cc != 0 || (
#if defined(jpn)
            controller->flags17ff.streamMode
#else
            controller->b19ce
#endif
        ) != 0) {
                            entry->pendingUpload = 0;
                        } else {
                            RestorePairTables0207df90(controller->encoder);
                            DisableField16Bit002041754((Obj02041754*)entry);
                            BackupPairTables0207dfac(controller->encoder);
                        }
                        ClearBitInArray_02042af4((int)self, controller->bitmapAllocationBits, entry->bitmapIndex);
                    }
                }
            }
        }
    }

    if (self->primaryBounds.state >= 2) {
        SetRectFromPosAndSize((Rect020e2d2c*)&controller->entries[0], 4, 0x76, 0xf8, 0x46);
        if (self->showEntries != 0) {
            SetEntryEnabled020e2cc4((Entry020e2cc4*)&controller->entries[0], 1);
        }
    }

    if (self->choicePanel.bounds.state >= 2) {
        int left = self->choicePanel.bounds.x;
        int top = self->choicePanel.bounds.y;
        int right = self->choicePanel.bounds.width;
        int bottom = self->choicePanel.bounds.height;
        SetRectFromPosAndSize((Rect020e2d2c*)&controller->entries[1], left + 2, top + 2, right - 4, bottom - 4);
        if (self->showEntries != 0) {
            SetEntryEnabled020e2cc4((Entry020e2cc4*)&controller->entries[1], 1);
        }
    }

    int k;
    for (k = 0; k < 2; k++) {
        UpdateAndDrawEntry020e2c34((Entry020e2c34*)&controller->entries[k]);
    }
}
