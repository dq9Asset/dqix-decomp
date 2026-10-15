#include <globaldefs.h>

struct Wnd0204e038 {
    char pad0[8];
    unsigned char* buf;
    char padC[0xa8 - 0xc];
    short cols;
    short rows;
};

// USA: func_0204e038
extern "C" ARM void func_0204e038(Wnd0204e038* wnd, unsigned char* bits, short x, short y, short w, short h, unsigned char hiColor, unsigned char loColor) {
    short tx;
    short ty;
    unsigned char bit;
    short j;
    short i;
    if (bits == NULL) {
        return;
    }
    short cols = wnd->cols;
    short rows = wnd->rows;
    bit = 0;
    for (j = 0; j < h; j++) {
        short py = y + j;
        short oy = (py & 7) << 2;
        ty = py >> 3;
        bool inY = ty >= 0 && ty < rows;
        ty *= wnd->cols;
        for (i = 0; i < w; i++) {
            if (inY && (*bits & (1 << bit))) {
                int px = (short)(x + i);
                int dx = px & 7;
                tx = px >> 3;
                bool inX = tx >= 0 && tx < cols;
                bool draw = inX | inY;
                if (draw) {
                    short off = oy + (tx + ty) * 32 + (dx >> 1);
                    unsigned char* buf = wnd->buf;
                    if (px & 1) {
                        buf[off] &= 0x0f;
                        buf[off] |= hiColor;
                    } else {
                        buf[off] &= 0xf0;
                        buf[off] |= loColor;
                    }
                }
            }
            bit++;
            if (bit >= 8) {
                bit = 0;
                bits++;
            }
        }
    }
}
