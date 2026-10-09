#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov000_021809e8(void* obj);
extern "C" void* func_ov000_02162a84(void* obj, int id);
struct Struct02170fd0;
extern "C" void func_ov000_02172a08(struct Struct02170fd0* obj, int b);
extern "C" void func_ov000_02176620(void* obj);
extern "C" void func_ov000_0217bc00(void* obj);

// JPN: func_ov000_02180958
extern "C" ARM int func_ov000_02180958(void* objRaw) {
    char* obj = (char*)objRaw;
    int n = func_ov000_021809e8(obj);
    int valid = (n >= 0 && n <= 3) ? 1 : 0;
    if (valid) {
        struct Struct02170fd0* entry = (struct Struct02170fd0*)func_ov000_02162a84(obj, n);
        if (entry != 0) {
            *(int*)(obj + 0x17c) = *(int*)((char*)entry + 0x4c);
            func_ov000_02172a08(entry, 0);
            *(int*)(obj + 0x910) = 0;
            *(int*)(obj + 0x914) = 0;
            *(int*)(obj + 0x918) = 0;
            *(int*)(obj + 0x91c) = 0;
            unsigned short field72 = *(unsigned short*)(obj + 0x1f00 + 0xaa);
            field72 = field72 & ~0x38;
            *(unsigned short*)(obj + 0x1f00 + 0xaa) = field72;
            func_ov000_02176620(obj);
            func_ov000_0217bc00(obj);
            return 0;
        }
    }
    return 1;
}

#endif
