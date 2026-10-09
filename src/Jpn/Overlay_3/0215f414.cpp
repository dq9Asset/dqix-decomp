#if defined(jpn)
#include <globaldefs.h>

struct Container020e0310;
extern "C" int func_02042294(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int func_02042530(char* dst, int cursor);
extern "C" int func_020e2070(struct Container020e0310* c, int key);
extern "C" int func_020421fc(char* dst, int n, const char* name);
extern "C" int func_020426a8(char* dst, const char* src);

extern char data_ov003_0217e753;

// JPN: func_ov003_0215f414
extern "C" ARM void func_ov003_0215f414(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(base + 0x3d9);
    if (flag) {
        func_02042294(dst, cursor, 8, 5, 5, 5);
    }
    func_02042530(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(base + 0x7c);
    int i = 0;
    while (i < *(unsigned char*)(base + 0x3d8)) {
        unsigned char key = *(unsigned char*)(base + i + 0x3d5);
        int name = func_020e2070(c, key);
        func_020421fc(dst, i, (const char*)name);
        if (i != *(unsigned char*)(base + 0x3d8) - 1) {
            func_020426a8(dst, &data_ov003_0217e753);
        }
        i++;
    }
}

#endif
