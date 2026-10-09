#if defined(jpn)
#include <globaldefs.h>

struct Cont0205d1e0;
struct Cont0205d274;
struct Obj0205d2bc;
struct Entry_0205d6a0;

extern "C" void func_0205e510(struct Cont0205d1e0*);
extern "C" void func_0205e5a4(struct Cont0205d274*);
extern "C" void func_0205e5ec(struct Obj0205d2bc*);
extern "C" void func_0205e9b4(struct Entry_0205d6a0*, int);
extern "C" void func_ov000_02175f08(void* obj);

struct Entry021817b8 {
    char pad0[0x24];
    unsigned char flags0x24;
    char pad1[0x4c - 0x25];
    int field0x4c;
    char pad2[0x488 - 0x50];
};

// JPN: func_ov000_021817b8  (semantic: ResetCombatState_021817b8)
extern "C" ARM void func_ov000_021817b8(char* obj) {
    int idx;
    func_0205e510((struct Cont0205d1e0*)(obj + 0x188));
    func_0205e5a4((struct Cont0205d274*)(obj + 0x188));
    func_0205e5ec((struct Obj0205d2bc*)(obj + 0x188));
    func_0205e9b4((struct Entry_0205d6a0*)(obj + 0x188), 1);
    for (idx = 0; idx < 4; idx++) {
        signed char e = *(signed char*)(obj + idx + 0x6c);
        struct Entry021817b8* entry = (struct Entry021817b8*)(obj + 0x958) + e;
        if (entry->flags0x24 & 0x2) {
            entry->flags0x24 |= 0x4;
            *(int*)(obj + 0x17c) = entry->field0x4c;
        }
    }
    *(unsigned short*)(obj + 0x1f00 + 0xaa) &= ~0x8;
    *(int*)(obj + 0x914) = 0;
    *(int*)(obj + 0x910) = 0;
    func_ov000_02175f08(obj);
}

#endif
