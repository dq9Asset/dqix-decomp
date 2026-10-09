#if defined(jpn)
#include <globaldefs.h>

struct Container020e0310;
extern "C" int func_02042294(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int func_02042530(char* dst, int cursor);
extern "C" int func_020e2070(struct Container020e0310* c, int key);
extern "C" int func_020421fc(char* dst, int n, const char* name);
extern "C" int func_020426a8(char* dst, const char* src);

// JPN: func_ov003_02169864  (semantic: AppendEntryNamesWithSeparator_02169864)
extern "C" ARM void func_ov003_02169864(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(base + 0x4e9);
    if (flag) {
        func_02042294(dst, cursor, 8, 5, 5, 5);
    }
    func_02042530(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(base + 0x64);
    int i = 0;
    while (i < 3) {
        int name = func_020e2070(c, (short)i);
        func_020421fc(dst, i, (const char*)name);
        if (i != 2) {
            int sep = func_020e2070(c, 0x64);
            func_020426a8(dst, (const char*)sep);
        }
        i++;
    }
}

#endif
