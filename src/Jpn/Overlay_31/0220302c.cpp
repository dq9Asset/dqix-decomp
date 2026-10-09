#if defined(jpn)
#include <globaldefs.h>

extern "C" ARM int func_ov031_02200e80(void*, unsigned int, void*, unsigned int);
extern "C" ARM int func_ov031_02202ff0(int, int);
extern "C" void func_ov031_02202a3c(int, int, int);
extern "C" void func_ov031_02202b14(int, int, int);
extern "C" void func_ov031_02202c0c(int, int, int);
extern "C" void func_ov031_02202f24(int, int, int);
extern "C" int func_ov031_0220278c(int, int, int, int);

struct Buf0220284c { unsigned char pad[0xc]; unsigned char byte0xc; unsigned char byte0xd; };

// JPN: func_ov031_0220302c
extern "C" ARM void func_ov031_0220302c(void* c, Buf0220284c* buf, int len) {
    if (func_ov031_02200e80(buf, len, c, 6)) return;

    int v = buf->byte0xc & 0xf0;
    len -= v / 4;
    int code = buf->byte0xd & 0x17;

    if (code <= 0x10) {
        if (code >= 0x10) goto handlerA;
        if (code > 0x2) goto fallback;
        if (code < 0x1) goto fallback;
        if (code == 0x1) goto case1;
        if (code == 0x2) goto case2;
        goto fallback;
    } else {
        if (code > 0x12) goto fallback;
        if (code < 0x11) goto fallback;
        if (code == 0x11) goto handlerA;
        if (code == 0x12) goto case0x12;
        goto fallback;
    }

case2:
    if (buf->byte0xd & 0x28) return;
    func_ov031_02202a3c((int)c, (int)buf, len);
    return;

case0x12:
    if (buf->byte0xd & 0x28) return;
    func_ov031_02202b14((int)c, (int)buf, len);
    return;

handlerA:
    func_ov031_02202c0c((int)c, (int)buf, len);
    return;

case1:
    func_ov031_02202f24((int)c, (int)buf, len);
    return;

fallback:
    if (buf->byte0xd & 0x4) {
        func_ov031_02202ff0((int)c, (int)buf);
    } else {
        func_ov031_0220278c((int)c, (int)buf, len, 0);
    }
}

#endif
