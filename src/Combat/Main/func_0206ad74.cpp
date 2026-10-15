#include <globaldefs.h>
#include "std_library_functions.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_02069408(void*, unsigned short);
extern "C" int func_02069430(void*, unsigned short);
extern "C" void func_0206cb14(void*, int, unsigned short);
extern "C" void __clear(void*, int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern const char data_020f07ce[];
extern const char data_020f0aeb[];

// JPN: func_0206c794
extern "C" ARM void func_0206c794(void* context) {
    MessageSystem* self = static_cast<MessageSystem*>(context);
    unsigned short caption[16];
    unsigned char length = 0;
    __clear(caption, sizeof(caption));
    unsigned short* cursor = static_cast<unsigned short*>(self->secondLineBuffer);
    int changed = 0;
    // This position uses -1 as a sentinel; access its shared halfword as signed.
    self->h1944 = 0;
    unsigned char previousStatus = self->b19c2;
    for (;;) {
        if (func_02069408(self, *cursor)) {
            length = 0;
            reinterpret_cast<short&>(self->h1944) = -1;
            self->lineGlyphCount = 0;
            self->b19c4 = 0;
            changed = 1;
            break;
        }
        if (!func_02069430(self, *cursor)) {
            if (func_02001aec(cursor, data_020f07ce, 2) == 0) {
                self->b19c2 = 0;
                break;
            }
            caption[length] = *cursor;
            length = (unsigned char)(length + 1) & 15;
        }
        reinterpret_cast<short&>(self->h1944)++;
        cursor++;
    }
    cursor++;
    for (;;) {
        if (func_02069408(self, *cursor)) break;
        if (!func_02069430(self, *cursor)) {
            if (func_02001aec(cursor, data_020f0aeb, 2) == 0) {
                length = 0;
                reinterpret_cast<short&>(self->h1944) = -1;
                self->lineGlyphCount = 0;
                self->b19c4 = 0;
                self->b19c2 = previousStatus;
                changed = 1;
                break;
            }
            if (func_02001aec(cursor, data_020f07ce, 2) == 0) break;
        }
        cursor++;
    }
    if (!self->b19c2 && length) {
        unsigned short slot;
        for (unsigned char i = 0; i < self->lineGlyphCount; i++) {
            slot = self->lineGlyphSlots[i];
            if (!func_02069430(self, slot)) {
                MessageGlyphSlot* glyph = &self->glyphs[slot];
                if (glyph->bitmapIndex >= 0 &&
                    *reinterpret_cast<unsigned short*>(glyph->encodedCharacter) != caption[i]) {
                    changed = 1;
                    break;
                }
            }
        }
    }
    if (changed) {
        for (unsigned char i = 0; i < self->lineGlyphCount; i++)
            func_0206cb14(self, 10, self->lineGlyphSlots[i]);
        memset(self->lineGlyphSlots, 0xff01, sizeof(self->lineGlyphSlots));
        self->b19c3 = 0;
    } else if (self->lineGlyphCount) {
        self->tokenCount = (short)self->h1944;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x40) = (short)self->h1944;
        self->tokenIndex = (short)self->h1944;
        return;
    }
    self->lineGlyphCount = 0;
}
#else

struct Entry0204254c { int value; signed char width; signed char advance : 6; signed char field5 : 2; unsigned char field6[2]; };
Entry0204254c* FindEntryByKey0204254c(int, int);
int GetWordFromTable02042648(int);
struct CombatSlots0206b198;
void DecrementSlotRef0206b198(CombatSlots0206b198*, unsigned short);
extern char data_020f08dc[];
extern char data_020f0979[];
extern char data_020f097c[];
extern "C" void __clear(void*, int);
struct Caption0206ad74 {
    unsigned char field0[0x50];
    char* text;
    unsigned char field54[0x74-0x54];
    int start;
    int end;
    unsigned char field7c[8];
    int specialStart;
    int specialEnd;
    unsigned char field8c[0x912-0x8c];
    unsigned char mode;
    unsigned char field913[0x934-0x913];
    short boxWidth;
    short boxHeight;
    unsigned char field938[0x1882-0x938];
    unsigned short slots[64];
    char caption[64];
    unsigned short count;
    short width;
    short specialLength;
    unsigned char field1948[0x19c2-0x1948];
    unsigned char status;
    unsigned char changed;
    unsigned char field19c4[0x19dc-0x19c4];
    unsigned char font;
};

// USA: func_0206ad74
extern "C" ARM void func_0206ad74(Caption0206ad74* self) {
    int defaultWidth;
    int length = 0;
    self->specialStart = 0;
    self->specialEnd = 0;
    self->width = 0;
    self->count = 0;
    self->specialLength = 0;
    unsigned char previousStatus = self->status;
    int changed = 1;
    int prefixCount = 0;
    char caption[64];
    __clear(caption, sizeof(caption));
    unsigned char fontWidth;
    char* cursor;
    char* text = self->text;
    char* start = strstr(text, data_020f08dc);
    char* middle = strstr(text, data_020f0979);
    char* alternate = strstr(text, data_020f097c);
    fontWidth = GetWordFromTable02042648(self->font);
    if (start) {
        for (;;) {
            if (text == start) break;
            unsigned short code;
            memcpy(&code, text, 2);
            prefixCount++;
            if ((code & 0xff00) == 0xff00) text++;
            text++;
        }
        char* selected = start + 2;
        char* finish = strstr(selected, data_020f08dc);
        if (finish) {
            length = finish - selected;
            memcpy(caption, selected, length);
            changed = 0;
            self->status = changed;
            cursor = caption;
            for (;;) {
                defaultWidth = fontWidth + 1;
                if (!*cursor) break;
                Entry0204254c* entry = FindEntryByKey0204254c((int)cursor, self->font);
                if (entry) {
                    self->count++;
                    int width = entry->width;
                    int advance = entry->advance;
                    self->width += width + 1;
                    cursor += advance;
                } else {
                    self->count++;
                    cursor++;
                    self->width += defaultWidth;
                }
            }
            self->specialLength = finish - start;
            self->specialLength += 3;
            self->specialLength += prefixCount - 2;
            self->mode = 4;
            short padding = 8 - (self->width & 7);
            self->boxWidth = self->width + 18 + padding;
            self->boxHeight = 22;
        } else self->status = previousStatus;
    } else {
        if (middle || alternate) self->mode = 3;
        else self->specialLength = -1;
    }
    if (!self->status && length) changed = strcmp(self->caption, caption);
    if (changed) {
        for (int i = 0; i < self->count; i++) DecrementSlotRef0206b198((CombatSlots0206b198*)self, self->slots[i]);
        memset(self->slots, 0xff01, sizeof(self->slots));
        memset(self->caption, 0, sizeof(self->caption));
        memcpy(self->caption, caption, length);
        self->changed = 0;
        if (self->count) {
            self->specialStart = self->specialLength;
            self->specialEnd = self->count + prefixCount + 3;
        }
    } else if (self->count) {
        self->specialStart = self->specialLength;
        self->specialEnd = self->count + prefixCount + 3;
        self->start = self->count + prefixCount + 3;
        self->end = self->count + prefixCount + 3;
        self->count++;
        return;
    }
    self->count = 0;
}

#endif
