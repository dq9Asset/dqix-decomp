#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_020121c0(unsigned short* obj, int mask);
extern "C" int func_0205ec90(int);
extern "C" void func_ov000_02177664(void* obj);
extern "C" void func_ov000_0217bee0(void* obj, int a, int b);
extern "C" void func_ov000_02178418(int a, void* obj, int c, int d, int e, int f);

extern unsigned short data_02114ad0;
extern int data_ov000_02185394[3];

// JPN: func_ov000_0217d310
extern "C" ARM int func_ov000_0217d310(void* objRaw, int arg1, int arg2) {
    char* obj = (char*)objRaw;
    int flags = func_020121c0(&data_02114ad0, 0x601);
    flags |= func_020121c0(&data_02114ad0, 0x802);
    int c = (func_0205ec90(*(int*)(obj + 0x38)) == 2) ? 1 : 0;
    if ((flags | c) != 0) {
        *(unsigned char*)(obj + 0x484) = 0;
        func_ov000_02177664(obj);
        signed char idx = *(signed char*)(obj + 0x18);
        *(unsigned char*)(obj + idx + 0x10) = 0;
        idx = *(signed char*)(obj + 0x18);
        *(unsigned char*)(obj + 0x18) = idx - 1;
        func_ov000_0217bee0(obj, arg1, arg2);
        signed char idx2 = *(signed char*)(obj + 0x18);
        signed char p2 = *(signed char*)(obj + idx2 + 0x10);
        func_ov000_02178418(data_ov000_02185394[0], obj, p2, data_ov000_02185394[2], data_ov000_02185394[1], 0);
    }
    return -1;
}

#endif
