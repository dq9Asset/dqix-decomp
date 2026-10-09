#if defined(jpn)
#include <globaldefs.h>

struct WindowBounds {
    unsigned short x1;
    unsigned short y1;
    unsigned short x2;
    unsigned short y2;
};

// JPN: func_ov031_0223d3f8
// Sets a hardware display window used by the Wi-Fi interface.
// Engine selector 1 addresses the sub engine; window 0 selects WIN0, otherwise WIN1.
extern "C" ARM void SetWifiDisplayWindowBounds(int displayEngine, int windowIndex, const WindowBounds* bounds) {
    if (displayEngine == 1) {
        if (windowIndex == 0) {
            int x1 = bounds->x1;
            int y1 = bounds->y1;
            int x2 = bounds->x2;
            int y2 = bounds->y2;
            *(volatile unsigned short*)0x04001040 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04001044 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
        } else {
            int x1 = bounds->x1;
            int y1 = bounds->y1;
            int x2 = bounds->x2;
            int y2 = bounds->y2;
            *(volatile unsigned short*)0x04001042 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04001046 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
        }
    } else {
        if (windowIndex == 0) {
            int x1 = bounds->x1;
            int y1 = bounds->y1;
            int x2 = bounds->x2;
            int y2 = bounds->y2;
            *(volatile unsigned short*)0x04000040 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04000044 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
        } else {
            int x1 = bounds->x1;
            int y1 = bounds->y1;
            int x2 = bounds->x2;
            int y2 = bounds->y2;
            *(volatile unsigned short*)0x04000042 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04000046 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
        }
    }
}

#endif
