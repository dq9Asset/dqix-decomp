#if defined(jpn)
#include <globaldefs.h>

extern "C" ARM void func_ov031_02216e94(void);
extern "C" int func_ov031_02216b40(void);
extern "C" ARM void func_ov031_02212534(int, int, int, int, int);
extern "C" int func_ov031_022136c8(void);
extern "C" int func_ov031_0220dd20(void);

struct Entry02211e08 {
    int field0;
    unsigned short field4;
    unsigned short field6;
    unsigned char pad1[4];
    unsigned char fieldc;
    unsigned char pad2[3];
    int field10;
};
struct Glob0224e5b4_02211e08 { void* pad0; Entry02211e08* pField; };
extern Glob0224e5b4_02211e08 data_ov031_0224f1b4;

// JPN: func_ov031_022125e8
extern "C" ARM void func_ov031_022125e8(void) {
    if (data_ov031_0224f1b4.pField == 0) return;
    switch (data_ov031_0224f1b4.pField->field10) {
    case 1:
        data_ov031_0224f1b4.pField->field0 = 0;
        data_ov031_0224f1b4.pField->field10 = func_ov031_02216b40();
        return;
    case 2: {
        func_ov031_02216e94();
        char* c = (char*)data_ov031_0224f1b4.pField;
        func_ov031_02212534((int)(c + 0x14), (int)(c + 0x34), *(int*)(c + 0x54), (int)(c + 0x58), 8);
        data_ov031_0224f1b4.pField->field10 = 0;
        return;
    }
    case 3:
        func_ov031_02216e94();
        data_ov031_0224f1b4.pField->field0 = -1;
        data_ov031_0224f1b4.pField->fieldc = 1;
        return;
    case 4:
    case 5:
        return;
    default:
        break;
    }
    unsigned short f4 = data_ov031_0224f1b4.pField->field4;
    if (f4 == 2) {
        data_ov031_0224f1b4.pField->field0 = func_ov031_022136c8();
        return;
    }
    if (f4 != 4) return;
    if (data_ov031_0224f1b4.pField->field6 == 0) return;
    if (func_ov031_0220dd20() == 9) return;
    data_ov031_0224f1b4.pField->field6 = 0;
    data_ov031_0224f1b4.pField->field4 = 6;
}

#endif
