#if defined(jpn)
#include <globaldefs.h>

struct Data0217d3e8 {
    void* field8;
    int field0;
    int field4;
};
extern Data0217d3e8 data_ov000_02185394;
extern unsigned short data_02114ad0;
extern char data_02114af4;

extern "C" void func_ov000_021769f0(void* obj);
extern "C" ARM int func_020121c0(unsigned short* obj, int mask);
extern "C" void func_ov000_02176a80(void* obj);
extern "C" void func_ov000_0217bee0(void* obj, int a, int b);
extern "C" void func_ov000_02178418(void* obj, int zero, int val, int arg1, int arg2, int one);

// JPN: func_ov000_0217d3e8
extern "C" ARM int func_ov000_0217d3e8(char* obj) {
    func_ov000_021769f0(data_ov000_02185394.field8);
    int t = func_020121c0(&data_02114ad0, 0x802);
    if (t != 0 || *((unsigned char*)&data_02114af4 + 0x55) != 0) {
        func_ov000_02176a80(data_ov000_02185394.field8);
        char* sub = obj + 8;
        signed char idx1 = *(volatile signed char*)(sub + 0x10);
        *(unsigned char*)(sub + idx1 + 8) = 0;
        *(signed char*)(sub + 0x10) = *(volatile signed char*)(sub + 0x10) - 1;
        func_ov000_0217bee0(obj, data_ov000_02185394.field4, data_ov000_02185394.field0);
        func_ov000_02178418(data_ov000_02185394.field8, (int)obj, *(signed char*)(obj + *(volatile signed char*)(obj + 0x18) + 0x10), data_ov000_02185394.field4, data_ov000_02185394.field0, 0);
    }
    return -1;
}

#endif
