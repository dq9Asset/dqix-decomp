#if defined(jpn)
#include <globaldefs.h>

struct S02170460 {
    char pad0[0x24];
    unsigned char flags;
    char pad1[0x4c - 0x25];
    int field4c;
    char pad2[0x488 - 0x50];
};

struct Obj021763ec {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x93c - 0x70];
    int phase;
    int waveX;
    int waveY;
    char pad2[0x958 - 0x948];
    struct S02170460 entries[1];
};

extern "C" void func_ov000_02171f54(struct S02170460* obj, int count);
extern "C" void func_ov000_02176218(struct Obj021763ec* obj, int cid);

extern const int data_ov000_02184494[];
extern const int data_ov000_021844a4[];

// JPN: func_ov000_021763ec
extern "C" ARM void func_ov000_021763ec(struct Obj021763ec* obj, int count) {
    struct S02170460* entry;
    int i;
    for (i = 0; i < 4; i++) {
        entry = &obj->entries[obj->order[i]];
        int cid = entry->field4c;
        int valid = (cid >= 0 && cid <= 3) ? 1 : 0;
        if (!valid) continue;
        func_ov000_02171f54(entry, count);
        if (entry->flags & 8) {
            func_ov000_02176218(obj, cid);
        }
    }

    obj->phase += count;
    obj->phase &= 0xf;
    int slot = obj->phase >> 2;
    obj->waveX = data_ov000_02184494[slot];
    obj->waveY = data_ov000_021844a4[slot];
}

#endif
