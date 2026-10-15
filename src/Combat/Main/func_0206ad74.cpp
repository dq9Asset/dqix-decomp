#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"
#include "std_library_functions.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_02069408(void*, unsigned short);
extern "C" int func_02069430(void*, unsigned short);
extern "C" void __clear(void*, int);
extern "C" int func_02001aec(const void*, const void*, int);
extern const char data_020f07ce[];
extern const char data_020f0aeb[];

// JPN: func_0206c794
extern "C" ARM void func_0206c794(MessageSystem* self) {
    unsigned short caption[16];
    unsigned char length = 0;
    __clear(caption, sizeof(caption));
    unsigned short* cursor = self->secondLineBuffer;
    int changed = 0;
    self->h1944 = 0;
    unsigned char previousStatus = self->b19c2;
    for (;;) {
        if (func_02069408(self, *cursor)) {
            length = 0;
            self->h1944 = -1;
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
        self->h1944++;
        cursor++;
    }
    cursor++;
    for (;;) {
        if (func_02069408(self, *cursor)) break;
        if (!func_02069430(self, *cursor)) {
            if (func_02001aec(cursor, data_020f0aeb, 2) == 0) {
                length = 0;
                self->h1944 = -1;
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
                    glyph->encodedCode != caption[i]) {
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
        self->lineStart = self->h1944;
        self->tokenIndex = (short)self->h1944;
        return;
    }
    self->lineGlyphCount = 0;
}
#else

int GetWordFromTable02042648(int);
extern char data_020f08dc[];
extern char data_020f0979[];
extern char data_020f097c[];
extern "C" void __clear(void*, int);

// USA: func_0206ad74
extern "C" ARM void func_0206ad74(MessageSystem* self) {
    int defaultWidth;
    int length = 0;
    self->captionStart = 0;
    self->slotReleaseIndex = 0;
    self->captionWidth = 0;
    self->lineGlyphCount = 0;
    self->h1946 = 0;
    unsigned char previousStatus = self->b19c2;
    int changed = 1;
    int prefixCount = 0;
    char caption[64];
    __clear(caption, sizeof(caption));
    unsigned char fontWidth;
    char* cursor;
    char* text = self->secondLineBuffer;
    char* start = strstr(text, data_020f08dc);
    char* middle = strstr(text, data_020f0979);
    char* alternate = strstr(text, data_020f097c);
    fontWidth = GetWordFromTable02042648(self->b19dc);
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
            self->b19c2 = changed;
            cursor = caption;
            for (;;) {
                defaultWidth = fontWidth + 1;
                if (!*cursor) break;
                FontCharacter* entry = FindEntryByKey0204254c(cursor, self->b19dc);
                if (entry) {
                    self->lineGlyphCount++;
                    int width = entry->width;
                    int advance = entry->byteLength;
                    self->captionWidth += width + 1;
                    cursor += advance;
                } else {
                    self->lineGlyphCount++;
                    cursor++;
                    self->captionWidth += defaultWidth;
                }
            }
            self->h1946 = finish - start;
            self->h1946 += 3;
            self->h1946 += prefixCount - 2;
            self->b912 = 4;
            short padding = 8 - (self->captionWidth & 7);
            self->foo930.width = self->captionWidth + 18 + padding;
            self->foo930.height = 22;
        } else self->b19c2 = previousStatus;
    } else {
        if (middle || alternate) self->b912 = 3;
        else self->h1946 = -1;
    }
    if (!self->b19c2 && length) changed = strcmp(self->captionText, caption);
    if (changed) {
        for (int i = 0; i < self->lineGlyphCount; i++) DecrementSlotRef0206b198(self, self->lineGlyphSlots[i]);
        memset(self->lineGlyphSlots, 0xff01, sizeof(self->lineGlyphSlots));
        memset(self->captionText, 0, sizeof(self->captionText));
        memcpy(self->captionText, caption, length);
        self->b19c3 = 0;
        if (self->lineGlyphCount) {
            self->captionStart = self->h1946;
            self->slotReleaseIndex = self->lineGlyphCount + prefixCount + 3;
        }
    } else if (self->lineGlyphCount) {
        self->captionStart = self->h1946;
        self->slotReleaseIndex = self->lineGlyphCount + prefixCount + 3;
        self->lineStart = self->lineGlyphCount + prefixCount + 3;
        self->tokenIndex = self->lineGlyphCount + prefixCount + 3;
        self->lineGlyphCount++;
        return;
    }
    self->lineGlyphCount = 0;
}

#endif
