#include <globaldefs.h>

struct Struct_0205c570;
int GetGlobalField0x1c020421a0(void);
int GetActiveScaledSum0205c570(struct Struct_0205c570* s);
void SetField0x1e20_02042b10(void* obj, void* value);
void EmitScaledField0x440_0202f404(void* obj, int a, int b);
void InitSelfPointer_02042b1c(unsigned char* base);
int CheckGlobalObjState2AndInit0205cde8(unsigned char* p);
extern "C" void func_02045f3c(void* ctx, void* ptr, int x, int y, int color, int a, int b, int flag, int c, int d);

struct Container0205a3d0;
struct Entry0205a3d0 {
    char pad0[4];
    unsigned short f4;
    unsigned short f6;
    char pad8[0xd];
    unsigned char f15;
};
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);
struct Entry0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);
extern "C" void func_0205ae8c(void* obj);

static inline int GetCursorColumn(unsigned char* obj) { return *(int*)(obj + 0x88); }
static inline int GetCursorRow(unsigned char* obj) { return *(int*)(obj + 0x8c); }

// USA: func_0205c96c
extern "C" ARM void func_0205c96c(unsigned char* obj, int flag) {
    unsigned char* ctx;
    int cursor;
    int end;
    int sum;
    int color;
    int x;
    int y;
    int top;
    int i;
    int perRow;
    int column;
    int row;
    void* list;
    struct Container0205a3d0* entries;
    unsigned short key;
    struct Entry0205a3d0* entry;

    if (obj[0x233] == 0 || obj[0x232] == 0) {
        return;
    }

    ctx = (unsigned char*)GetGlobalField0x1c020421a0();
    cursor = *(int*)(obj + 0x50);
    sum = GetActiveScaledSum0205c570((struct Struct_0205c570*)(obj + 0x1c));
    color = 0x7fff;
    if (obj[0x234] == 0) {
        color = 0x3def;
    }

    if (flag == 0) {
        *(short*)(obj + 0xcc) = color;
        SetField0x1e20_02042b10(ctx, obj + 0xb4);
        EmitScaledField0x440_0202f404(ctx + 0x19e0, 1, 1);
        InitSelfPointer_02042b1c(ctx);
    }

    if (CheckGlobalObjState2AndInit0205cde8(obj) == 0) {
        return;
    }

    ctx[0x19b0] = 1;

    perRow = *(int*)(obj + 0x7c);
    i = perRow * *(int*)(obj + 0x84);
    x = *(short*)(obj + 0xb4) + 0xc;
    y = *(short*)(obj + 0xb6) + 8;
    end = i + perRow;
    top = y;

    for (; i < end; i++) {
        int c = color;
        if (i == cursor && cursor == sum) {
            c = 0xf0a;
        }
        func_02045f3c(ctx, (unsigned short*)(obj + 0x120) + *(unsigned short*)(obj + 0x220 + i * 2), x, y, c, 0xc, 0x14, flag, 1, 0x11);
        y += *(int*)(obj + 0xd8);
    }

    if ((obj[0xb0] | obj[0xb1]) == 0) {
        return;
    }

    column = GetCursorColumn(obj);
    row = GetCursorRow(obj);
    x = column * *(int*)(obj + 0xd4) + (x - 0x10);
    y = row * *(int*)(obj + 0xd8) + (top - 2);
    list = *(void**)(ctx + 0x2d8);
    entries = *(struct Container0205a3d0**)(ctx + 0x2e0);
    key = *(unsigned short*)(ctx + 0x2e4);
    if (list == NULL || entries == NULL) {
        return;
    }

    SetEntryFlag2ByKey0205a370(entries, key);
    entry = FindEntryByHalfword0205a3d0(entries, key);
    if (entry != NULL) {
        entry->f15 |= 8;
    }
    entry = FindEntryByHalfword0205a3d0(entries, key);
    if (entry != NULL) {
        entry->f4 = x;
        entry->f6 = y;
    }
    func_0205ae8c(list);
}
