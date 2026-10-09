#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_020cbeb8(int value, void* dst, int size);
extern "C" int func_ov031_02213a10(int mask, void* arg);
extern "C" int func_ov031_0221b5b4(int v);
extern "C" int func_ov031_0220d150(void* p, int size);
extern "C" void func_ov031_02213ab4(void);

struct Obj02212d40 {
    void* field0;
    void* field4;
    unsigned char field8;
    unsigned char field9;
    unsigned char fieldA;
    unsigned char fieldB;
};

struct GlobalCtx0224e5c4_02212d40 {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
};

extern GlobalCtx0224e5c4_02212d40 data_ov031_0224f1c4;

// JPN: func_ov031_02213520
extern "C" ARM int func_ov031_02213520(Obj02212d40* obj) {
    GlobalCtx0224e5c4_02212d40* g = &data_ov031_0224f1c4;
    void* alloc = (void*)((int (*)(int, int))obj->field0)(1, 0x24);
    g->fieldC = alloc;
    func_020cbeb8(0, alloc, 0x24);

    void* p = g->fieldC;
    *(void**)p = obj->field0;
    *(void**)((char*)p + 4) = obj->field4;
    *((unsigned char*)p + 9) = 1;
    *((unsigned char*)p + 0x16) = 1;
    *((unsigned char*)p + 8) = 1;

    g->field10 = (void*)func_ov031_02213a10(0x10, (void*)0xd18);
    g->field0  = (void*)func_ov031_02213a10(2, (void*)0x2300);
    g->field4  = (void*)func_ov031_02213a10(4, (void*)0x58);
    g->field8  = (void*)func_ov031_02213a10(8, (void*)0xc);

    func_020cbeb8(0, g->field10, 0xd18);
    func_020cbeb8(0, g->field0, 0x2300);
    func_020cbeb8(0, g->field4, 0x58);
    func_020cbeb8(0, g->field8, 0xc);

    unsigned char* big = (unsigned char*)g->field10;
    big[0xd0a] = obj->field8;
    big[0xd0b] = (big[0xd0b] & ~0x3) | (obj->field9 & 0x3);

    void* h = g->field8;
    *(void**)h = obj->field0;
    *(void**)((char*)h + 4) = obj->field4;
    *(int*)((char*)h + 8) = 0;

    big[0xd0c] = (big[0xd0c] & ~0xf) | (obj->fieldA & 0xf);
    big[0xd0c] = (big[0xd0c] & ~0x30) | ((obj->fieldB & 3) << 4);

    func_ov031_0221b5b4((int)big);

    int r = func_ov031_0220d150(g->field0, 0x2300);
    if (r == 1 || r > 4) {
        func_ov031_02213ab4();
        return 0;
    }
    return 1;
}

#endif
