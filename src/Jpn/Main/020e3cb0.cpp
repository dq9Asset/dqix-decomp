#if defined(jpn)
#include <globaldefs.h>

extern "C" ARM void* func_02042950(int idx);
extern "C" ARM void func_0205c830(void* mgr, void* entry, short x, short y, int w, int h);
extern "C" ARM void* __clear(void* dst, int count);

extern unsigned char data_020eea10;

// JPN: func_020e3cb0
extern "C" ARM void func_020e3cb0(void* obj) {
    void* ctx = *(void**)((char*)obj + 4);
    void* mgr = *(void**)((char*)ctx + 4);
    unsigned char width = ((unsigned char*)ctx)[0x3a];
    unsigned char height = ((unsigned char*)ctx)[0x3b];

    void* e1 = func_02042950(1);
    void* e6 = func_02042950(6);
    if (e1 != 0 && e6 != 0) {
        int x, i;
        int n = width - 9;
        for (x = 8, i = 0; i < n >> 3; x += 8, i++) {
            func_0205c830(mgr, e1, x, 0, 8, 0xf);
            func_0205c830(mgr, e6, x, (short)(height - 8), 8, 0xf);
        }
    }

    void* e3 = func_02042950(3);
    void* e4 = func_02042950(4);
    if (e3 != 0 && e4 != 0) {
        int y, j;
        int m = height - 9;
        for (y = 8, j = 0; j < m >> 3; y += 8, j++) {
            func_0205c830(mgr, e3, 0, y, 8, 0xf);
            func_0205c830(mgr, e4, (short)(width - 8), y, 8, 0xf);
        }
    }

    short xs[4];
    short ys[4];
    __clear(xs, 8);
    short cornerX = (short)(width - 8);
    xs[1] = cornerX;
    xs[3] = cornerX;
    __clear(ys, 8);
    short cornerY = (short)(height - 8);
    ys[2] = cornerY;
    ys[3] = cornerY;

    int k;
    for (k = 0; k < 4; k++) {
        int idx = (&data_020eea10)[k];
        void* entry = func_02042950(idx);
        if (entry != 0) {
            func_0205c830(mgr, entry, xs[k], ys[k], 8, 0xf);
        }
    }
}


#endif
