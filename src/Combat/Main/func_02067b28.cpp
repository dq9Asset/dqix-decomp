#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"
#if !defined(jpn)
int FindMatchingEntryIndex(MessageSystem*, FontCharacter*);
extern "C" int func_020459b8(MessageSystem*, unsigned char, FontCharacter*, unsigned char);
extern "C" int func_02001aec(const void*, const void*, int);
extern char data_020f08dc[3];
// USA: func_02067b28
extern "C" ARM void func_02067b28(MessageSystem* state) {
    if (!state->tokenStart || !state->tokenCursor) return;
    if (state->producedLength <= state->tokenCount) return;
    while (state->tokenCount < state->producedLength) {
        char* source = state->secondLineBuffer + state->field7c;
        unsigned short* destination = state->firstLineBuffer + state->tokenCount;
        unsigned short token;
        memcpy(&token, source, 2);
        if (IsHighByteFF02044494(state, &token)) {
            *destination = token;
            state->field7c += 2;
            ++state->tokenCount;
            int length = Dispatch02044420(state, &token);
            memcpy(destination + 1, source + 2, length * 2);
            state->field7c += length * 2;
            state->tokenCount += length;
            continue;
        }
        if (!state->b19c2) {
            state->b19c4 = 1;
            if (state->h1946 <= 0) state->b19c4 = 0;
            if (!func_02001aec(source, data_020f08dc, 2)) {
                if (state->lineGlyphCount == 0) state->b19c4 = 0;
                else {
                    state->foo930.width = state->captionWidth + 18 + (short)(8 - (state->captionWidth & 7));
                    state->foo930.height = 22;
                    state->b19c2 = 1;
                }
                state->b19c3 = 1;
            }
        }
        FontCharacter* entry = FindEntryByKey0204254c(source, state->b19dc);
        int tableIndex = FindEntryIndexByKey020424e4(source, state->b19dc);
        if (entry && tableIndex >= 0) {
            int index = FindMatchingEntryIndex(state, entry);
            state->field7c += entry->byteLength;
            if (index < 0) {
                unsigned short inserted = func_020459b8(state, (unsigned char)tableIndex, entry, state->b19dc);
                if (!state->b19c2) state->lineGlyphSlots[state->lineGlyphCount] = inserted;
                *destination = inserted;
                ++state->tokenCount;
                state->allocatedGlyphCount = (state->allocatedGlyphCount + 1) & 0x7f;
                break;
            }
            unsigned short selected = index;
            if (!state->b19c2) {
                state->lineGlyphSlots[state->lineGlyphCount] = selected;
                ++state->lineGlyphCount;
                state->lineGlyphCount &= 0x3f;
            }
            *destination = selected;
            if (state->glyphReferences[selected] < 255) ++state->glyphReferences[selected];
        } else {
            signed char character = *source;
            if (!state->b19c2 && character == 32) {
                state->lineGlyphSlots[state->lineGlyphCount] = 0xff19;
                ++state->lineGlyphCount;
                state->lineGlyphCount &= 0x3f;
            }
            *destination = 0xff19;
            ++state->field7c;
        }
        ++state->tokenCount;
    }
    if (!state->b19c2) {
        ++state->lineGlyphCount;
        state->lineGlyphCount &= 0x3f;
    }
}

#endif
