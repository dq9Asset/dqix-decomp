#include <globaldefs.h>

struct Wnd0204e1c8 {
    char pad0[8];
    unsigned char* buf;
    char padC[0xa8 - 0xc];
    short cols;
    short rows;
};

// USA: func_0204e1c8
extern "C" ARM void func_0204e1c8(Wnd0204e1c8* wnd, unsigned char* src, short x, short y, short w, short h, unsigned char hiMask, unsigned char loMask) {
    int dotX;
    unsigned char pix;
    short px;
    short ty;
    short j;
    short i;
    if (src == NULL) {
        return;
    }
    short cols = wnd->cols;
    short rows = wnd->rows;
    for (j = 0; j < h; j++) {
        short dy = y & 7;
        short oy = dy << 2;
        ty = y >> 3;
        bool inY = ty >= 0 && ty < rows;
        ty *= wnd->cols;
        px = x;
        for (i = 0; i < w; i++) {
            dotX = px;
            short tx = dotX >> 3;
            bool inX = tx >= 0 && tx < cols;
            short tile = ty + tx;
            bool draw = inX | inY;
            short off = tile * 32;
            off += (short)(dotX & 7) >> 1;
            off += oy;
            pix = wnd->buf[off];
            if (x & 1) {
                if (i & 1) {
                    if (draw) {
                        unsigned char v = *src & hiMask;
                        if (v) {
                            v >>= 4;
                            pix &= 0xf0;
                            pix |= v;
                        }
                        wnd->buf[off] = pix;
                    }
                    src++;
                } else {
                    if (draw) {
                        unsigned char v = *src & loMask;
                        if (v) {
                            v <<= 4;
                            pix &= 0x0f;
                            pix |= v;
                        }
                        wnd->buf[off] = pix;
                    }
                }
            } else {
                if (i & 1) {
                    if (draw) {
                        unsigned char v = *src & hiMask;
                        if (v) {
                            pix &= 0x0f;
                            pix |= v;
                        }
                        wnd->buf[off] = pix;
                    }
                    src++;
                } else {
                    if (draw) {
                        unsigned char v = *src & loMask;
                        if (v) {
                            pix &= 0xf0;
                            pix |= v;
                        }
                        wnd->buf[off] = pix;
                    }
                }
            }
            px++;
        }
        y++;
    }
}
