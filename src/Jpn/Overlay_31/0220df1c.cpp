#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov031_0220dd50(int a);
extern "C" int func_ov031_0220e0d4(int a);
extern "C" unsigned short func_020d6644(void);
extern "C" void* VectorizedInvertedMemcpy(void* p0, void* p1, int n);

extern int data_ov031_0224f13c;
extern int data_ov031_02246ba4;
extern int data_ov031_02246bac;

// JPN: func_ov031_0220df1c
extern "C" ARM void func_ov031_0220df1c(void* a0, char* a1, int a2) {
    func_ov031_0220dd50(a2);

    *(int*)((char*)data_ov031_0224f13c + 0x2000 + 0x288) = (int)((char*)data_ov031_0224f13c + 0x1500);
    *(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x8c) = 0x400;

    int shiftAmt = func_ov031_0220e0d4(0);
    *(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x8e) = (unsigned short)((1 << shiftAmt) >> 1);

    unsigned short v68 = *(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x68);
    unsigned short v90 = v68 != 0 ? v68 : func_020d6644();
    *(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x90) = v90;

    *(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x98) = ((*(int*)((char*)data_ov031_0224f13c + 0x2000 + 0x264) & 0x300000) != 0x300000);

    if (a0 == 0) {
        VectorizedInvertedMemcpy(&data_ov031_02246ba4, (char*)data_ov031_0224f13c + 0x2200 + 0x92, 6);
    } else {
        VectorizedInvertedMemcpy(a0, (char*)data_ov031_0224f13c + 0x2200 + 0x92, 6);
    }

    if (a1 == 0 || a1 == (char*)&data_ov031_02246bac) {
        VectorizedInvertedMemcpy(&data_ov031_02246bac, (char*)data_ov031_0224f13c + 0x2000 + 0x29c, 0x20);
        *(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x9a) = 0;
    } else {
        VectorizedInvertedMemcpy(a1, (char*)data_ov031_0224f13c + 0x2000 + 0x29c, 0x20);
        int len = 0;
        unsigned char* p = (unsigned char*)a1;
        for (;;) {
            if (*p == 0) break;
            len++;
            p++;
            if (len >= 0x20) break;
        }
        *(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x9a) = len;
    }

    *(int*)((char*)data_ov031_0224f13c + 0x2000 + 0x284) = 0;
}

#endif
