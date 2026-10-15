#include <globaldefs.h>

extern unsigned char* data_ov031_02290c98;
extern "C" void* VectorizedInvertedMemcpy(void* dst, void* src, int n);
extern "C" int func_02005a94(const char* text);

#pragma optimize_for_size off
// USA: func_ov031_0222dd70  (semantic: CheckAndFormatEntry_0222dd70)
extern "C" ARM int func_ov031_0222dd70(int cmpVal) {
    unsigned char idx = data_ov031_02290c98[0x14];
    unsigned char* entry = data_ov031_02290c98 + 8 + idx * 3;
    unsigned char c = *entry;
    if (c != 0 && c != 0x20) return 1;

    char buf[4];
    VectorizedInvertedMemcpy(entry, buf, 3);
    buf[3] = 0;
    int i = 0;
    unsigned char* p = (unsigned char*)buf;
    do {
        if (*p != 0) break;
        i++;
        *p++ = 0x20;
    } while (i < 3);

    int n = func_02005a94(buf);
    return n >= cmpVal ? 1 : 0;
}
