#if defined(jpn)
#include <globaldefs.h>

extern "C" unsigned char* func_ov031_022047bc(void* buf, int n, int* out);
extern "C" ARM void* func_ov031_02204948(int value, unsigned int end, void* dst, unsigned int start);
extern "C" int func_ov031_02204264(int param0, int param1);

extern unsigned char data_ov031_0224dad6[];

struct StateBlock0224c980_02204260 {
    unsigned char pad0[0x20];
    unsigned int field20;
    unsigned char pad1[0x34 - 0x24];
    unsigned int field34;
};
extern StateBlock0224c980_02204260 data_ov031_0224d580;

// JPN: func_ov031_02204a40
extern "C" ARM int func_ov031_02204a40(int flag) {
    int outVal;
    unsigned char* buf = data_ov031_0224dad6;
    unsigned char* ip = func_ov031_022047bc(buf, 3, &outVal);
    if (flag == 0) {
        ip[0] = 0x32;
        ip[1] = 4;
        ip[2] = (unsigned char)((unsigned short)(data_ov031_0224d580.field34 >> 16) >> 8);
        ip[3] = (unsigned char)(data_ov031_0224d580.field34 >> 16);
        ip[4] = (unsigned char)((unsigned short)data_ov031_0224d580.field34 >> 8);
        ip[5] = (unsigned char)data_ov031_0224d580.field34;
        ip[6] = 0x36;
        ip[7] = 4;
        ip[8] = (unsigned char)((unsigned short)(data_ov031_0224d580.field20 >> 16) >> 8);
        ip[9] = (unsigned char)(data_ov031_0224d580.field20 >> 16);
        ip[0xa] = (unsigned char)((unsigned short)data_ov031_0224d580.field20 >> 8);
        ip[0xb] = (unsigned char)data_ov031_0224d580.field20;
        ip += 0xc;
    }
    ip[0] = 0xff;
    unsigned char* dst = (unsigned char*)func_ov031_02204948(0, 0x12c, ip + 1, (unsigned int)((ip + 1) - buf));
    func_ov031_02204264((int)buf, (int)(dst - buf));
    return outVal;
}

#endif
