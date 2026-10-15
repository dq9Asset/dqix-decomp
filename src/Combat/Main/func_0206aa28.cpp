#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include <std_library_functions.h>

#if defined(jpn)
typedef unsigned short MessageCharacter;
#else
typedef char MessageCharacter;
#endif

#if defined(jpn)
extern "C" int func_02069430(void*, unsigned short);
extern "C" int func_02069408(void*, unsigned short);
extern "C" void func_0206c794(MessageSystem*);
#else
int IsHighByteFF0206ac6c(void*, void*);
int Func0206abf8(void*, void*);
bool IsCommandInRange02067a9c(void*, void*);
extern "C" void func_0206ad74(MessageSystem*);
#endif

// USA: func_0206aa28
extern "C" ARM void func_0206aa28(MessageSystem* context) {
#if !defined(jpn)
    context->field7c = 0;
#endif
    context->tokenCount = 0;
    context->producedLength = 0;
    context->lineStart = 0;
    context->tokenIndex = 0;
    MessageCharacter* cursor = context->tokenStart;
#if defined(jpn)
    MessageCharacter* output = context->secondLineBuffer;
#else
    MessageCharacter* output = static_cast<MessageCharacter*>(context->secondLineBuffer);
#endif
    bool seenGlyph = false;
#if defined(jpn)
    while (cursor != 0) {
        *output = *cursor;
        ++output;
        context->producedLength++;
        if (context->tokenLength < (unsigned int)(cursor - static_cast<MessageCharacter*>(context->textBuffer))) {
            context->active = 0;
            break;
        }
        if (func_02069430(context, *cursor)) {
            if (*cursor == 0xff1a || *cursor == 0xff1b) seenGlyph = 1;
            if (func_02069408(context, *cursor)) {
                if (!seenGlyph) {
                    context->producedLength--;
                    context->tokenStart = ++cursor;
                    --output;
                    continue;
                }
                context->tokenCursor = cursor;
                break;
            }
            unsigned short command = *cursor;
            if ((command & 0xffe0) == 0xffe0) {
                command = (unsigned short)(command ^ 0xffe0) + 0xffd0;
                cursor = func_0206c730(context, command, static_cast<MessageCharacter*>(context->textBuffer));
                if (!cursor) {
                    unsigned char saved = context->b19cc;
                    ReinitController02043204(context);
                    func_02043124(context);
                    context->b19cc = saved;
                    break;
                }
            }
        } else {
            seenGlyph = 1;
        }
        ++cursor;
    }
    func_0206c794(context);
#else
    for (;;) {
        if (!*cursor) break;
        int commandBytes = 0;
        if (IsHighByteFF0206ac6c(context, cursor)) {
            int words = Func0206abf8(context, cursor) + 1;
            commandBytes = words * 2;
            memcpy(output, cursor, commandBytes);
            output += words * 2;
            context->producedLength += words * 2;
        }
        if (context->tokenLength < (unsigned int)(cursor - static_cast<MessageCharacter*>(context->textBuffer))) {
            context->active = 0;
            break;
        }
        if (IsHighByteFF0206ac6c(context, cursor)) {
            if (IsCommandInRange02067a9c(context, cursor)) {
                if (seenGlyph) {
                    context->tokenCursor = cursor;
                    break;
                }
                unsigned char saved = context->b19cc;
                ReinitController02043204(context);
                func_02043124(context);
                context->b19cc = saved;
                break;
            }
            unsigned short command;
            memcpy(&command, cursor, 2);
            cursor += commandBytes;
            if ((command & 0xffe0) == 0xffe0) {
                command = (unsigned short)(command ^ 0xffe0) + 0xffd0;
                cursor = func_0206ac94(context, command, static_cast<char*>(context->textBuffer));
                if (!cursor) {
                    unsigned char saved = context->b19cc;
                    ReinitController02043204(context);
                    func_02043124(context);
                    context->b19cc = saved;
                    break;
                }
            }
        } else {
            seenGlyph = 1;
            int size = 1;
            FontCharacter* entry = FindEntryByKey0204254c(cursor, context->b19dc);
            if (entry) size = entry->byteLength;
            memcpy(output, cursor, size);
            output += size;
            context->producedLength++;
            cursor += size;
        }
    }
    func_0206ad74(context);
#endif
}
