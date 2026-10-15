#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void* p);
struct GameState;
extern int GetFieldAt0x150_02053c6c(unsigned char* obj);
void ClearField00209a804(int* field);
struct Ctx0209a810 { void* field0; };
void SetupAndRunBufferedScript0209a810(Ctx0209a810* ctx, void* value);
void SetField38IfState8_0215e49c(void*, int, int);
int CheckAfterTwoCalls_0215e460(void);
extern "C" void func_ov004_0215e574(void* a, int key, int c, int d, int e);
void SetNodeFieldsAndMaybeNotify_0215f6f4(void* a, short v1, short v2, int flag);

struct TagNode02161514 {
    char pad0[0xc];
    unsigned char field0xc;
};
extern "C" TagNode02161514* func_ov004_0215e47c(void* a, int key);

class FNode02161514 {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1c();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2c();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3c();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4c();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5c();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6c();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7c();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8c();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9c();
    virtual void vfa0(); virtual void vfa4(); virtual void vfa8(); virtual void vfac();
    virtual void vfb0(); virtual void vfb4(); virtual void vfb8(); virtual void vfbc();
    virtual void vfc0(); virtual void vfc4(); virtual void vfc8(); virtual void vfcc();
    virtual void vfd0(); virtual void vfd4();
    virtual void SetState(int arg);
};
extern "C" FNode02161514* func_ov023_021f6880(void* obj, int key);

struct Entry02161514 {
    unsigned short id;
    unsigned short level;
};
struct Buf02161514 {
    char pad[0x10c];
    Entry02161514 rows[13][20];
    int counts[13];
};

struct Selection02161514 {
    unsigned char unknown0[2];
    unsigned char equippedCategory;
#if defined(jpn)
    unsigned char unknown3;
    signed char itemCount;
    unsigned char unknown5;
#else
    unsigned char unknown3[3];
    signed char itemCount;
#endif
    unsigned char state;
    unsigned char selectedCategory;
#if !defined(jpn)
    unsigned char unknown9[2];
#endif
    signed char categoryDelta;
#if defined(jpn)
    unsigned char unknown9[0x1c - 9];
#else
    unsigned char unknownc[0x1c - 0xc];
#endif
    int combatant;
};
extern Selection02161514 data_ov004_021707e8;
extern int data_ov004_02170854[];
#if defined(jpn)
extern unsigned char data_ov004_02170568[];
extern unsigned char data_ov004_021710b0[];
#else
extern unsigned char data_ov004_0216fde8[];
#endif
extern unsigned char data_ov004_02170838[];
extern unsigned char data_ov004_02170820[];

// JPN: func_ov004_02161514 (02161ea4)
// USA: func_ov004_02161514
extern "C" ARM int func_ov004_02161514(void* a) {
    Ctx0209a810 ctx;
    Buf02161514 buf;
    void* obj;
    int showAll;
    unsigned char flag;
    int t;
    unsigned char* field;
    unsigned int limit;
    int count;
    Entry02161514* rows;
    unsigned char cnt;
    int i;
    int j;
    unsigned char k;
    int same;
    FNode02161514* node;

    data_ov004_021707e8.state = 0x65;
    obj = func_ov011_021849c8(a);
    showAll = 0;
    flag = 0;
    if (data_ov004_021707e8.equippedCategory != data_ov004_02170854[data_ov004_021707e8.selectedCategory]) flag = 1;

#if defined(jpn)
    if (data_ov004_021707e8.itemCount == 0) {
        func_ov004_0215e47c(a, 3)->field0xc &= ~4;
    } else {
        func_ov004_0215e47c(a, 3)->field0xc |= 4;
    }
#else
    func_ov004_0215e47c(a, 3)->field0xc |= 4;
#endif

    t = data_ov004_02170854[data_ov004_021707e8.selectedCategory];
    if (t != 1 && t != 4 && t != 7) {
        unsigned char* combatant = (unsigned char*)GetCombatantWithFlag0x100_0200ff1c((GameState*)(void*)GameState::GetInstance(), data_ov004_021707e8.combatant);
        if (!combatant) return 0;
        field = (unsigned char*)GetFieldAt0x150_02053c6c(combatant);
        if (!field) return 0;
        limit = *(unsigned short*)(field + data_ov004_02170854[data_ov004_021707e8.selectedCategory] * 2 + 0x16c);
        ClearField00209a804((int*)&ctx);
        SetupAndRunBufferedScript0209a810(&ctx, &buf);
        count = buf.counts[data_ov004_02170854[data_ov004_021707e8.selectedCategory]];
        rows = buf.rows[data_ov004_02170854[data_ov004_021707e8.selectedCategory]];
        cnt = 0;

        for (i = 0xc; i < 0x30; i++) SetField38IfState8_0215e49c(a, i, 0x3a);
        SetField38IfState8_0215e49c(a, 0x31, 0x3a);
        SetField38IfState8_0215e49c(a, 0x32, 0x3a);
        SetField38IfState8_0215e49c(a, 0xc, 0x3b);
        SetField38IfState8_0215e49c(a, 0xd, 1);
        if (CheckAfterTwoCalls_0215e460()) {
            SetField38IfState8_0215e49c(a, 0xe, 4);
        } else {
            SetField38IfState8_0215e49c(a, 0xe, data_ov004_02170854[data_ov004_021707e8.selectedCategory] + 4);
        }

        if (data_ov004_021707e8.equippedCategory != data_ov004_02170854[data_ov004_021707e8.selectedCategory]) {
            for (k = 0; k < 3; k++) {
                node = func_ov023_021f6880(obj, k + 0xc);
                if (node) node->SetState(3);
            }
            node = func_ov023_021f6880(obj, 0x64);
            if (node) node->SetState(3);
        } else {
            for (k = 0; k < 3; k++) {
                node = func_ov023_021f6880(obj, k + 0xc);
                if (node) node->SetState(0xf);
            }
            node = func_ov023_021f6880(obj, 0x64);
            if (node) node->SetState(0xf);
        }

        for (i = 0; i < count; i++) {
            unsigned short id = rows[i].id;
            unsigned short level = rows[i].level;
            if (level != 0 && level <= limit) {
                int st;
                SetField38IfState8_0215e49c(a, cnt + 0xf, id + 0x3f);
                st = 0xf;
                if (data_ov004_021707e8.equippedCategory != data_ov004_02170854[data_ov004_021707e8.selectedCategory]) st = 3;
                node = func_ov023_021f6880(obj, cnt + 0xf);
                if (node) node->SetState(st);
                cnt++;
            }
        }

        if (cnt == 0) {
            showAll = 1;
            for (j = 0xc; j < 0x30; j++) SetField38IfState8_0215e49c(a, j, 0x3a);
            SetField38IfState8_0215e49c(a, 0x31, 0x1e1);
            SetField38IfState8_0215e49c(a, 0x32, 0x1e3);
#if !defined(jpn)
            func_ov004_0215e574(a, 0x31, 0xff, 0, 0);
#endif
#if !defined(jpn)
            func_ov004_0215e574(a, 0x32, 0xff, 0, 0);
#endif
            SetField38IfState8_0215e49c(a, 0xc, 0x3b);
            SetField38IfState8_0215e49c(a, 0xd, 1);
            if (CheckAfterTwoCalls_0215e460()) {
                SetField38IfState8_0215e49c(a, 0xe, 4);
            } else {
                SetField38IfState8_0215e49c(a, 0xe, data_ov004_02170854[data_ov004_021707e8.selectedCategory] + 4);
            }
            same = 1;
            if (data_ov004_021707e8.equippedCategory != data_ov004_02170854[data_ov004_021707e8.selectedCategory]) same = 0;
            for (int i = 0; i < 5; i++) {
#if defined(jpn)
                node = func_ov023_021f6880(obj, data_ov004_02170568[i]);
#else
                node = func_ov023_021f6880(obj, data_ov004_0216fde8[i]);
#endif
                if (node) {
                    if (same) node->SetState(0xf);
                    else node->SetState(3);
                }
            }
        }
    } else {
        int st;
        showAll = 1;
        for (j = 0xc; j < 0x30; j++) SetField38IfState8_0215e49c(a, j, 0x3a);
        SetField38IfState8_0215e49c(a, 0x31, 0x1e1);
        SetField38IfState8_0215e49c(a, 0x32, 0x1e3);
#if !defined(jpn)
        func_ov004_0215e574(a, 0x31, 0xff, 0, 0);
#endif
#if !defined(jpn)
        func_ov004_0215e574(a, 0x32, 0xff, 0, 0);
#endif
        SetField38IfState8_0215e49c(a, 0xc, 0x3b);
        SetField38IfState8_0215e49c(a, 0xd, 1);
        if (CheckAfterTwoCalls_0215e460()) {
            SetField38IfState8_0215e49c(a, 0xe, 4);
        } else {
            SetField38IfState8_0215e49c(a, 0xe, data_ov004_02170854[data_ov004_021707e8.selectedCategory] + 4);
        }
        same = 1;
        if (data_ov004_021707e8.equippedCategory != data_ov004_02170854[data_ov004_021707e8.selectedCategory]) same = 0;
        for (int i = 0; i < 5; i++) {
#if defined(jpn)
            node = func_ov023_021f6880(obj, data_ov004_02170568[i]);
#else
            node = func_ov023_021f6880(obj, data_ov004_0216fde8[i]);
#endif
            if (node) {
                if (same) node->SetState(0xf);
                else node->SetState(3);
            }
        }
        st = 0xf;
        if (!same) st = 3;
        node = func_ov023_021f6880(obj, 0x64);
        if (node) node->SetState(st);
        if (data_ov004_021707e8.itemCount == 0) {
            TagNode02161514* tag = func_ov004_0215e47c(a, 3);
            if (tag) tag->field0xc &= ~4;
        }
    }

#if !defined(jpn)
    if (showAll) {
        unsigned char n = 0;
        int m;
        for (m = 1; m < 0xd; m++) {
            if (data_ov004_02170838[m]) n++;
            if (n > 1) break;
        }
        if (n <= 1) func_ov004_0215e47c(a, 3)->field0xc &= ~4;
    }

#endif

    {
        int d;
#if defined(jpn)
        data_ov004_021707e8.categoryDelta = data_ov004_021710b0[data_ov004_02170854[data_ov004_021707e8.selectedCategory] - 1];
        d = data_ov004_021707e8.categoryDelta - data_ov004_021710b0[data_ov004_021707e8.equippedCategory - 1];
#else
        data_ov004_021707e8.categoryDelta = data_ov004_02170820[data_ov004_02170854[data_ov004_021707e8.selectedCategory] - 1];
        d = data_ov004_021707e8.categoryDelta - data_ov004_02170820[data_ov004_021707e8.equippedCategory - 1];
#endif
        if (d < 0) d += data_ov004_021707e8.itemCount;
        data_ov004_021707e8.categoryDelta = d;
    }
    SetNodeFieldsAndMaybeNotify_0215f6f4(a, data_ov004_021707e8.categoryDelta, data_ov004_021707e8.itemCount, flag);
    return 0;
}
