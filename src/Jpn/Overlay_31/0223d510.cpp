#if defined(jpn)
#include <globaldefs.h>

// JPN: func_ov031_0223d510
extern "C" ARM void func_ov031_0223d510(int side, int channel, unsigned short value, int enable) {
    switch (channel) {
    case 0: {
        if (side == 1) {
            unsigned v = *(volatile unsigned short*)0x4001048;
            v = (v & ~0x3f) | value;
            if (enable) v |= 0x20;
            *(volatile unsigned short*)0x4001048 = v;
        } else {
            unsigned v = *(volatile unsigned short*)0x4000048;
            v = (v & ~0x3f) | value;
            if (enable) v |= 0x20;
            *(volatile unsigned short*)0x4000048 = v;
        }
        break;
    }
    case 1: {
        if (side == 1) {
            unsigned v = *(volatile unsigned short*)0x4001048;
            v = (v & ~0x3f00) | (value << 8);
            if (enable) v |= 0x2000;
            *(volatile unsigned short*)0x4001048 = v;
        } else {
            unsigned v = *(volatile unsigned short*)0x4000048;
            v = (v & ~0x3f00) | (value << 8);
            if (enable) v |= 0x2000;
            *(volatile unsigned short*)0x4000048 = v;
        }
        break;
    }
    case 2: {
        if (side == 1) {
            unsigned v = *(volatile unsigned short*)0x400104a;
            v = (v & ~0x3f00) | (value << 8);
            if (enable) v |= 0x2000;
            *(volatile unsigned short*)0x400104a = v;
        } else {
            unsigned v = *(volatile unsigned short*)0x400004a;
            v = (v & ~0x3f00) | (value << 8);
            if (enable) v |= 0x2000;
            *(volatile unsigned short*)0x400004a = v;
        }
        break;
    }
    case 3: {
        if (side == 1) {
            unsigned v = *(volatile unsigned short*)0x400104a;
            v = (v & ~0x3f) | value;
            if (enable) v |= 0x20;
            *(volatile unsigned short*)0x400104a = v;
        } else {
            unsigned v = *(volatile unsigned short*)0x400004a;
            v = (v & ~0x3f) | value;
            if (enable) v |= 0x20;
            *(volatile unsigned short*)0x400004a = v;
        }
        break;
    }
    }
}

#endif
