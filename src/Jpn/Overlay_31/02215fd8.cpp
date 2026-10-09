#if defined(jpn)
#include <globaldefs.h>

struct CipherKeys_022157f8 {
    signed char* post;
    int unused4;
    signed char* pre;
};

extern "C" void func_ov031_02216344(void* obj, unsigned char* buf, int a, int b);

extern unsigned char data_ov031_02246c77[0x18];
extern CipherKeys_022157f8 data_ov031_0224a6d4;

// JPN: func_ov031_02215fd8
extern "C" ARM void func_ov031_02215fd8(void* obj, unsigned char* buf) {
    unsigned char order[0x18];

    {
        int pairs = 0xc;
        unsigned char* dst = order;
        const unsigned char* src = data_ov031_02246c77;
        do {
            unsigned char lo = src[0];
            unsigned char hi = src[1];
            src += 2;
            dst[0] = lo;
            dst[1] = hi;
            dst += 2;
        } while (--pairs != 0);
    }

    func_ov031_02216344(obj, buf, 0x20, 0x18);

    {
        int i = 0;
        do {
            buf[i] = buf[i] ^ data_ov031_0224a6d4.pre[i];
            i++;
        } while (i < 0x18);
    }

    {
        unsigned char home = 0;
        unsigned char slot = 0;
        unsigned char v = 0;
        int i = 0;
        do {
            home = (unsigned char)i;
            slot = home;
            v = buf[i];
            if (order[home] != 0xff) {
                do {
                    unsigned char next = order[slot];
                    unsigned char t = buf[next];
                    buf[order[home]] = v;
                    order[slot] = 0xff;
                    home = next;
                    slot = next;
                    v = t;
                } while (order[slot] != 0xff);
            }
            i++;
        } while (i < 0x18);
    }

    {
        int i = 0;
        do {
            buf[i] = buf[i] ^ data_ov031_0224a6d4.post[i];
            i++;
        } while (i < 0x18);
    }
}

#endif
