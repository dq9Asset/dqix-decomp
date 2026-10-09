#if defined(jpn)
#include <globaldefs.h>

struct Entry02213894;
extern "C" void* func_ov031_02213bd8(unsigned int flags);
extern "C" int func_ov031_02213c90(void);
extern "C" void func_ov031_022152a8(unsigned short id);
extern "C" ARM int func_ov031_02214074(char* obj, int count, struct Entry02213894* arr);
extern "C" ARM int func_ov031_022140f0(char* obj, char* b);
extern "C" int func_ov031_02214180(int a, void* obj, int b, void* c);
extern "C" void func_ov031_02214300(int a, void* b);

// JPN: func_ov031_02213e74
extern "C" ARM void func_ov031_02213e74(char* obj) {
    int result = -1;
    unsigned char extra = 0;
    char* d = (char*)func_ov031_02213bd8(0x10);
    void* p2 = func_ov031_02213bd8(1);
    *((unsigned char*)p2 + 0xb) = 1;

    int state = func_ov031_02213c90();

    switch (state) {
    case 3: {
        unsigned short nameLen = *(unsigned short*)(obj + 0xa);
        extra = *(unsigned char*)(d + 0xd11);
        if (nameLen == 0 || *(unsigned char*)(obj + 0xc) == 0) {
            func_ov031_022152a8(*(unsigned short*)(obj + 0x36));
            goto tail;
        }
        if (nameLen == 1 && *(unsigned char*)(obj + 0xc) == 0x20) {
            func_ov031_022152a8(*(unsigned short*)(obj + 0x36));
            result = func_ov031_02214074(obj, *(unsigned char*)(d + 0xd10), (struct Entry02213894*)(d + 0x300));
        } else {
            result = func_ov031_02214074(obj, *(unsigned char*)(d + 0xd10), (struct Entry02213894*)(d + 0x300));
        }
        break;
    }
    case 4: {
        char* addr = d + *(unsigned char*)(d + 0xd0f) * 0xc0 + 0x400;
        unsigned short val = *(unsigned short*)(addr + 0xa6);
        extra = (unsigned char)(val - 1);
        result = func_ov031_022140f0(obj, d);
        if (result < 0) goto tail;
        *(unsigned char*)(d + 0x447 + *(unsigned char*)(d + 0xd0f) * 4) |= 0x80;
        goto tail;
    }
    case 5: {
        struct Entry02213894* arr = (struct Entry02213894*)(d + 0x300 + *(unsigned char*)(d + 0xd0f) * 0x24);
        extra = *(unsigned char*)(d + 0xd11);
        result = func_ov031_02214074(obj, 1, arr);
        if (result < 0) goto tail;
        unsigned char* bp = (unsigned char*)(d + 0x300 + *(unsigned char*)(d + 0xd0f) * 0x24);
        *bp = (*bp & ~0xf) | 1;
        break;
    }
    default:
        return;
    }

tail:
    if (result < 0) return;
    func_ov031_02214300(func_ov031_02214180(result, obj, extra, d), d);
}

#endif
