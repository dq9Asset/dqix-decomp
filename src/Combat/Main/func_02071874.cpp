#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    int value;
};

struct List02071cc8;
struct Elem02071cc8;
void AppendElementCapped02071cc8(struct List02071cc8*, struct Elem02071cc8*);

struct FieldC02071b38 {
    unsigned int lo10 : 10;
    unsigned int mid10 : 10;
    unsigned int hi8 : 8;
    unsigned int top4 : 4;
};

struct Field1002071b38 {
    unsigned int lo10 : 10;
    unsigned int mid10 : 10;
    unsigned int bit20 : 1;
    unsigned int bit21 : 1;
    unsigned int bit22 : 1;
    unsigned int hi8 : 8;
    unsigned int bit31 : 1;
};

struct FieldA02071b38 {
    unsigned short n0 : 4;
    unsigned short n1 : 4;
    unsigned short n2 : 4;
    unsigned short n3 : 4;
};

struct Struct02071b38 {
    short f0;
    short f2;
    short f4;
    short f6;
    short f8;
    FieldA02071b38 fa;
    FieldC02071b38 fc;
    Field1002071b38 f10;
    short f14;
    short f16;
    short f18;
    short f1a;
    int f1c;
};
extern "C" void func_02071b38(struct Struct02071b38* s);

struct Data02108d98 {
    unsigned short field0;
    unsigned short field2;
    short* field4;
    int field8;
    struct List02071cc8* fieldC;
};
extern struct Data02108d98 data_02108d98;

// USA: func_02071874
extern "C" ARM int func_02071874(struct Variant02030b0c* cur) {
    struct Struct02071b38 entry;
    short id = (short)((Script::Parameter*)(cur++))->ToInt();

    if (data_02108d98.field4 != 0) {
        int found = 0;
        unsigned short i;
        for (i = 0; i < data_02108d98.field0; i++) {
            if (data_02108d98.field4[i] == id) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 1;
        }
    }

    func_02071b38(&entry);
    entry.f0 = id;
    entry.f2 = (short)((Script::Parameter*)(cur++))->ToInt();
    if (cur->tag != 0) {
        entry.f4 = (short)((Script::Parameter*)(cur++))->ToInt();
    } else {
        entry.f4 = 0;
        cur++;
    }
    entry.fa.n0 = (unsigned short)((Script::Parameter*)(cur++))->ToInt();
    if (cur->tag != 0) {
        entry.f6 = (short)((Script::Parameter*)(cur++))->ToInt();
    } else {
        entry.f6 = 0;
        cur++;
    }
    entry.fa.n1 = (unsigned short)((Script::Parameter*)(cur++))->ToInt();
    if (cur->tag != 0) {
        entry.f8 = (short)((Script::Parameter*)(cur++))->ToInt();
    } else {
        entry.f8 = 0;
        cur++;
    }
    entry.fa.n2 = (unsigned short)((Script::Parameter*)(cur++))->ToInt();
    entry.fa.n3 = (unsigned short)((Script::Parameter*)(cur++))->ToInt();
    entry.fc.lo10 = ((Script::Parameter*)(cur++))->ToInt();
    entry.fc.mid10 = ((Script::Parameter*)(cur++))->ToInt();
    entry.f10.lo10 = ((Script::Parameter*)(cur++))->ToInt();
    entry.f10.mid10 = ((Script::Parameter*)(cur++))->ToInt();
    entry.f10.bit20 = ((Script::Parameter*)(cur++))->ToInt();
    entry.fc.hi8 = ((Script::Parameter*)(cur++))->ToInt();
    entry.f10.hi8 = ((Script::Parameter*)(cur++))->ToInt();
    entry.f14 = (short)((Script::Parameter*)(cur++))->ToInt();
    entry.f16 = (short)((Script::Parameter*)(cur++))->ToInt();
    entry.f18 = (short)((Script::Parameter*)(cur++))->ToInt();
    entry.f1a = (short)((Script::Parameter*)(cur++))->ToInt();

    AppendElementCapped02071cc8(data_02108d98.fieldC, (struct Elem02071cc8*)&entry);
    return 1;
}
