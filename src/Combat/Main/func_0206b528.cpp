#include <globaldefs.h>
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_0206cc50(void*, unsigned short*);
extern "C" int func_02069408(void*, unsigned short);
extern "C" int func_020694a0(void*, unsigned short);

// JPN: func_0206cdcc
extern "C" ARM void func_0206cdcc(void* context, int* outA, int* outB) {
    MessageSystem* self = static_cast<MessageSystem*>(context);
    unsigned short* buffer = static_cast<unsigned short*>(self->secondLineBuffer);
    int start = self->lineStart;
    int limit = self->tokenIndex;
    int center;
    int line;
    unsigned short* cursor = buffer + start;
    unsigned short* end = buffer + limit;
    center = self->w990;
    line = 0;
    outA[line] = center - (func_0206cc50(self, cursor) >> 1);
    outB[line] = 0;
    cursor++;
    line++;
    while (cursor != end) {
        if (func_02069408(self, *cursor)) return;
        if (func_020694a0(self, *cursor)) {
            cursor++;
            outA[line] = center - (func_0206cc50(self, cursor) >> 1);
            outB[line] = 0;
            line++;
        }
        cursor++;
    }
}
#else

extern "C" int func_0206b37c(void* obj, void* p);
int IsHighByteFF0206ac6c(void* obj, void* p);
bool IsCommandInRange02067a9c(void* obj, void* p);
int IsHalfwordInRange02067ad8(int unused, void* p);
int Func0206abf8(void* a, void* p);

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

struct Entry0204254c* FindEntryByKey0204254c(int key, int tableIdx);

// USA: func_0206b528
extern "C" ARM int func_0206b528(unsigned char* obj, int* outA, int* outB) {
    unsigned char* buf = *(unsigned char**)(obj + 0x50);
    int start = *(int*)(obj + 0x84);
    int base = *(int*)(obj + 0x990);
    int i;
    unsigned char* p = buf + start;

    outA[0] = base - (func_0206b37c(obj, p) >> 1);
    outB[0] = 0;
    i = 1;

    for (;;) {
        signed char c = *(signed char*)p;
        if (c == 0) return c;
        if (IsHighByteFF0206ac6c(obj, p)) {
            bool stop = IsCommandInRange02067a9c(obj, p);
            if (stop) return stop;
            if (IsHalfwordInRange02067ad8((int)obj, p)) {
                p += 2;
                outA[i] = base - (func_0206b37c(obj, p) >> 1);
                outB[i] = 0;
                i++;
            } else {
                p = (p + 2) + Func0206abf8(obj, p) * 2;
                goto again;
            }
        } else {
            int adv = 1;
            struct Entry0204254c* e = FindEntryByKey0204254c((int)p, (obj + 0x1000)[0x9dc]);
            if (e) adv = e->field5;
            p += adv;
        }
    again: ;
    }
}

#endif
