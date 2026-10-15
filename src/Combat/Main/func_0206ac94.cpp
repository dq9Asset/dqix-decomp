#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/MessageSystem.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_02069430(void*, unsigned short);

// JPN: func_0206c730
extern "C" ARM unsigned short* func_0206c730(MessageSystem* obj, unsigned short token, unsigned short* cursor) {
    MessageSystem* self = obj;
    if (!cursor) return NULL;
    if (!func_02069430(obj, token)) return NULL;
    unsigned int count = 0;
    while (cursor) {
        if (*cursor == token) return cursor;
        count++;
        cursor++;
        if (self->tokenLength < count) break;
    }
    return NULL;
}
#else

extern bool IsHighByteFF02044494(void* obj, void* src);
extern int IsHighByteFF0206ac6c(void* base, void* src);
extern "C" int func_02001aec(const void* a, const void* b, int n);
extern int Func0206abf8(void* obj, void* src);

// USA: func_0206ac94
extern "C" ARM char* func_0206ac94(MessageSystem* obj, unsigned short buf, char* p) {
    unsigned int total;
    char* q = p;
    if (!q) {
        return 0;
    }
    if (!IsHighByteFF02044494(obj, &buf)) {
        return 0;
    }
    total = 0;
    for (;;) {
        unsigned char character = *q;
        if (character == 0) {
            break;
        }
        if (IsHighByteFF0206ac6c(obj, q)) {
            int step;
            if (!func_02001aec(&buf, q, 2)) {
                return q;
            }
            step = Func0206abf8(obj, q) * 2 + 2;
            q += step;
            total += step;
        } else {
            FontCharacter* e;
            int val = 1;
            e = FindEntryByKey0204254c(q, obj->b19dc);
            if (e) {
                val = e->byteLength;
            }
            q += val;
            total += val;
            if (obj->tokenLength >= total) {
                continue;
            }
            break;
        }
    }
    return 0;
}

#endif
