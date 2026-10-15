#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct TableA68;
struct StoreStruct;
struct Obj9b6c;
struct Obj02046574;
#if defined(jpn)
extern "C" void* func_ov004_02168f08(void* ctx, int value);
extern "C" void func_020474a8(void* a, int b, char* c, char* d);
#else
extern "C" void* func_ov023_021f6524(void* ctx, int value);
#endif
#if defined(jpn)
extern "C" struct TableA68* func_ov004_02169040(void* a, int key);
#else
extern "C" struct TableA68* func_ov004_02168b08(void* a, int key);
#endif
int GetGlobalField0x1c020421a0(void);
void* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void* func_0205ec34(void* obj);
extern "C" int func_ov023_021f9bc8(char* obj);
unsigned int GetTableEntry_021f9b6c(struct Obj9b6c* obj, unsigned int a, unsigned int b);
extern "C" void __clear(void* buf, int len);
extern "C" void func_02042764(const char* name, char* dest, int flag);
void* GetNodeIfType8_02168a6c(void* a, int id);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
extern "C" void func_02046380(void* global);
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
extern "C" void func_02046608(void* a, int b, char* c, char* d, int e, int f, int g);
char* FindSubstring_020d2f88(char* haystack, char* needle);
int LoadBattleBlock020ac4c0(void* dst);
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
#if defined(jpn)
extern "C" void* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#else
int DispatchNodeIfState6_021f6680(void* obj, int id);
#endif

struct Packed02169b4c {
    unsigned int w0A : 14;
    unsigned int w0B : 17;
    unsigned int w0C : 1;
    unsigned int w4A : 14;
    unsigned int w4B : 17;
    unsigned int w4C : 1;
    unsigned int w8A : 7;
    unsigned int w8B : 7;
    unsigned int w8C : 7;
    unsigned int w8D : 7;
    unsigned int w8E : 4;
    unsigned int wcA : 10;
    unsigned int wcB : 14;
    unsigned int wcC : 7;
    unsigned int wcD : 1;
    unsigned int w10A : 9;
    unsigned int w10B : 14;
    unsigned int w10C : 7;
    unsigned int w10D : 2;
    short f14;
    unsigned char f16 : 1;
};

struct Area02169b4c {
    char pad[6];
    char name[0xe];
    struct Packed02169b4c rec;
};

struct Blk02169b4c {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
    unsigned char f06;
    unsigned char f07;
    unsigned int f08 : 24;
    unsigned int f08hi : 8;
    unsigned int f0cA : 14;
    unsigned int f0cB : 14;
    unsigned int f0cC : 4;
    char rest[0xb0 - 0x10];
};

struct Ctx02169b4c {
#if defined(jpn)
    char pad[0x10];
#else
    char pad[0x190];
#endif
    char* f190;
    struct Packed02169b4c* f194;
    unsigned char f198;
    char pad199[3];
    char* f19c;
};

struct Grid02169b4c { char pad[0x5c]; short f5c; };
struct Triple02169b4c { int a, b, c; };

class Node02169b4c {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(struct Triple02169b4c* t);
    virtual struct Triple02169b4c Get();
    char pad4[8];
    unsigned char b0 : 3;
    unsigned char hidden : 1;
    char pad0d[0x20 - 0xd];
    char* text;
    char pad24[0x45 - 0x24];
    unsigned char f45a : 1;
    unsigned char mode : 6;
};

extern struct Ctx02169b4c* data_ov004_02171030;
extern char data_ov004_02170704[];

// JPN: func_ov004_02169b4c (0216a044)
// USA: func_ov004_02169b4c
extern "C" ARM int func_ov004_02169b4c(void* a) {
    char* areas = data_ov004_02171030->f190;
    if (!areas) return 0;

#if defined(jpn)
    struct Grid02169b4c* grid = static_cast<Grid02169b4c*>(func_ov004_02168f08(a, 0x64));
#else
    struct Grid02169b4c* grid = static_cast<Grid02169b4c*>(func_ov023_021f6524(a, 0x64));
#endif
#if defined(jpn)
    struct TableA68* tblA = func_ov004_02169040(a, 3);
#else
    struct TableA68* tblA = func_ov004_02168b08(a, 3);
#endif
    void* g = (void*)GetGlobalField0x1c020421a0();
    unsigned char* prot = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)GameState::GetInstance()->GetProtagonist());
    unsigned char* flags = (unsigned char*)func_0205ec34(prot);
#if defined(jpn)
    struct TableA68* tbl9 = func_ov004_02169040(a, 9);
#else
    struct TableA68* tbl9 = func_ov004_02168b08(a, 9);
#endif
#if defined(jpn)
    struct TableA68* tbl6 = func_ov004_02169040(a, 6);
#else
    struct TableA68* tbl6 = func_ov004_02168b08(a, 6);
#endif
#if defined(jpn)
    struct TableA68* tbl7 = func_ov004_02169040(a, 7);
#else
    struct TableA68* tbl7 = func_ov004_02168b08(a, 7);
#endif
    short f5c = grid->f5c;
    int areaIdx = func_ov023_021f9bc8((char*)grid);
    int idx = areaIdx + f5c * 8;
    if (!GetTableEntry_021f9b6c((struct Obj9b6c*)grid, (unsigned short)areaIdx, 0)) return 0;

    struct Area02169b4c* area = (struct Area02169b4c*)(areas + 4) + idx;
#if !defined(jpn)
    char buf[0x30];
    __clear(buf, 0x30);
#endif
    char* name;
    struct Packed02169b4c* rec;
    if (data_ov004_02171030->f198) {
        name = (char*)(prot + 0x3c);
        rec = data_ov004_02171030->f194;
    } else {
        rec = &area->rec;
#if defined(jpn)
        name = area->name;
#else
        func_02042764(area->name, buf, 1);
        name = buf;
#endif
    }

    char* out = data_ov004_02171030->f19c;
    memset(out, 0, 4);
    Node02169b4c* node;

#if defined(jpn)
    func_02046380(g);
    char* format = static_cast<char*>(FindEntryByKey_02072a68(tblA, 0x23));
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), 0, rec->w0A);
    SetByteInRange_020465f0(static_cast<unsigned char*>(g), 0, 4);
    SetByteAtIndex_020465d8(static_cast<unsigned char*>(g), 0, 1);
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), 1, rec->w8A);
    SetByteInRange_020465f0(static_cast<unsigned char*>(g), 1, 2);
    SetByteAtIndex_020465d8(static_cast<unsigned char*>(g), 1, 1);
    func_020474a8(g, 8, format, out);
    node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x190));
    node->text = out;
    out += strlen(out) + 1;

    func_02046380(g);
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), 0, rec->w4A);
    SetByteInRange_020465f0(static_cast<unsigned char*>(g), 0, 4);
    SetByteAtIndex_020465d8(static_cast<unsigned char*>(g), 0, 1);
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), 1, rec->w8B);
    SetByteInRange_020465f0(static_cast<unsigned char*>(g), 1, 2);
    SetByteAtIndex_020465d8(static_cast<unsigned char*>(g), 1, 1);
    func_020474a8(g, 8, static_cast<char*>(FindEntryByKey_02072a68(tblA, 0x23)), out);
    node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x191));
    node->text = out;
    out += strlen(out) + 1;

#else
    node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x190));
    node->mode = 2;
    sprintf(out, static_cast<char*>(FindEntryByKey_02072a68(tblA, 0x23)), rec->w0A);
    node->text = out;
    out += strlen(out) + 1;

    node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x1c2));
    node->mode = 2;
    sprintf(out, static_cast<char*>(FindEntryByKey_02072a68(tblA, 0x23)), rec->w8A);
    node->text = out;
    out += strlen(out) + 1;

    node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x191));
    node->mode = 2;
    sprintf(out, static_cast<char*>(FindEntryByKey_02072a68(tblA, 0x23)), rec->w4A);
    node->text = out;
    out += strlen(out) + 1;

    node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x1c3));
    node->mode = 2;
    sprintf(out, static_cast<char*>(FindEntryByKey_02072a68(tblA, 0x23)), rec->w8B);
    node->text = out;
    out += strlen(out) + 1;

#endif
    func_02046380(g);
    char* title;
    if (rec->f14 >= 700) {
        title = static_cast<char*>(FindEntryByKey_02072a68(tbl9, (short)(rec->f14 + 20000)));
    } else if (rec->f16) {
        title = static_cast<char*>(FindEntryByKey_02072a68(tbl7, rec->f14));
    } else {
        title = static_cast<char*>(FindEntryByKey_02072a68(tbl6, rec->f14));
    }
    SetIndexedName02046574((struct Obj02046574*)g, 0, title);
    SetIndexedName02046574((struct Obj02046574*)g, 1, name);
#if defined(jpn)
    func_020474a8(g, 0xa, static_cast<char*>(FindEntryByKey_02072a68(tblA, 0x22)), out);
#else
    func_02046608(g, 0xa, static_cast<char*>(FindEntryByKey_02072a68(tblA, 0x22)), out, 0xf0, 1, 0);
#endif

    node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x192));
    node->text = out;
#if !defined(jpn)
    struct Triple02169b4c t = node->Get();
    t.b = 0x7000;
    if (FindSubstring_020d2f88(out, data_ov004_02170704)) t.b = 0x2000;
    node->Apply(&t);
#endif
    out += strlen(out) + 1;

    func_02046380(g);
    unsigned char count = 0;
    unsigned char mask = 0;
    struct Blk02169b4c blk;
    LoadBattleBlock020ac4c0(&blk);
    mask |= 1;
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), count++, rec->w4B);
    if (TestBitInByteArray_0206dfb0((int)flags, flags + 0x8c, 0x1198)) {
        mask |= 2;
        StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), count++, rec->w0B);
    }
    mask |= 4;
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), count++, rec->wcA);
    if (blk.f08hi) {
        mask |= 8;
        StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), count++, rec->w10A);
    }
    if (blk.f0cB) {
        mask |= 0x10;
        StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), count++, rec->wcB);
    }
    if (TestBitInByteArray_0206dfb0((int)flags, flags + 0x8c, 0x1199)) {
        mask |= 0x20;
        StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), count++, rec->w10B);
    }

    unsigned char k = 0;
    int i;
    for (i = 0; i < 6; i++) {
        if (mask & (1 << i)) {
            SetByteInRange_020465f0(static_cast<unsigned char*>(g), k, 5);
            SetByteAtIndex_020465d8(static_cast<unsigned char*>(g), k, 1);
            strcpy(out, static_cast<char*>(FindEntryByKey_02072a68(tblA, (short)(i + 0x28))));
            int base = k * 3;
            node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, base + 0x1f4));
            if (!node) continue;
            node->text = out;
            out += strlen(out) + 1;
#if defined(jpn)
            func_020474a8(g, 8, static_cast<char*>(FindEntryByKey_02072a68(tblA, (short)(k + 0x14))), out);
#else
            func_02046608(g, 8, static_cast<char*>(FindEntryByKey_02072a68(tblA, (short)(k + 0x14))), out, 0x100, 0, 0);
#endif
            node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, base + 0x1f5));
            if (!node) continue;
            node->text = out;
            out += strlen(out) + 1;
            int key;
            if (i == 5) {
                key = 0x30;
            } else if ((i == 2) | (i == 3)) {
                key = 0x2f;
            } else {
                key = 0x2e;
            }
            strcpy(out, static_cast<char*>(FindEntryByKey_02072a68(tblA, key)));
            node = static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, base + 0x1f6));
            if (!node) continue;
            node->text = out;
            out += strlen(out) + 1;
            k++;
        }
    }
    for (int j = k; j < 6; j++) {
        int base = j * 3;
        (static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, base + 0x1f4)))->hidden = 1;
        (static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, base + 0x1f5)))->hidden = 1;
        (static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, base + 0x1f6)))->hidden = 1;
    }

    func_02046380(g);
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), 0, rec->w8C);
    SetByteInRange_020465f0(static_cast<unsigned char*>(g), 0, 3);
    SetByteAtIndex_020465d8(static_cast<unsigned char*>(g), 0, 1);
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), 1, rec->wcC);
    SetByteInRange_020465f0(static_cast<unsigned char*>(g), 1, 3);
    SetByteAtIndex_020465d8(static_cast<unsigned char*>(g), 1, 1);
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), 2, rec->w8D);
    SetByteInRange_020465f0(static_cast<unsigned char*>(g), 2, 3);
    SetByteAtIndex_020465d8(static_cast<unsigned char*>(g), 2, 1);
    StoreInArray0x8b0_020465c0(static_cast<StoreStruct*>(g), 3, rec->w10C);
    SetByteInRange_020465f0(static_cast<unsigned char*>(g), 3, 3);
    SetByteAtIndex_020465d8(static_cast<unsigned char*>(g), 3, 1);

    int rows = (mask & 2) ? 4 : 3;
    for (int r = 0; r < rows; r++) {
#if defined(jpn)
        func_020474a8(g, 8, static_cast<char*>(FindEntryByKey_02072a68(tblA, (short)(r + 0x1e))), out);
#else
        func_02046608(g, 8, static_cast<char*>(FindEntryByKey_02072a68(tblA, (short)(r + 0x1e))), out, 0x100, 0, 0);
#endif
        (static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, r * 2 + 6 + 0x200)))->text = out;
        out += strlen(out) + 1;
    }
    if (rows == 3) {
        (static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x19c)))->hidden = 1;
        (static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x20c)))->hidden = 1;
        (static_cast<Node02169b4c*>(GetNodeIfType8_02168a6c(a, 0x20d)))->hidden = 1;
    }

#if defined(jpn)
    {
        void* panel = func_ov004_02168fa4(a, 0x18);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x19);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x1c);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x1a);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x1d);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
    {
        void* panel = func_ov004_02168fa4(a, 0x1b);
        if (panel != 0) func_ov023_021f809c(panel, a);
    }
#else
    DispatchNodeIfState6_021f6680(a, 0x18);
    DispatchNodeIfState6_021f6680(a, 0x19);
    DispatchNodeIfState6_021f6680(a, 0x1c);
    DispatchNodeIfState6_021f6680(a, 0x1a);
    DispatchNodeIfState6_021f6680(a, 0x1d);
    DispatchNodeIfState6_021f6680(a, 0x1b);
#endif
    return 0;
}
