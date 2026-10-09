#if defined(jpn)
#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// JPN: func_02003e44
// Vectorised when dst and src share the same alignment: for a word x,
// (x + 0xfefefeff) & ~x & 0x80808080 is zero exactly when every byte of x is
// non-zero, so a whole word can be copied at a time until a terminator appears.
extern "C" ARM char* strcpy(char* dst, const char* src) {
    char* d = dst;
    unsigned int sa = (unsigned int)src & 3;
    unsigned int da = (unsigned int)dst & 3;

    if (da == sa) {
        if (sa != 0) {
            unsigned char c = *(const unsigned char*)src;
            *dst = c;
            if (c == 0) {
                return dst;
            }
            unsigned int k = 3 - sa;
            if (k != 0) {
                do {
                    c = *(const unsigned char*)++src;
                    *++d = c;
                    if (c == 0) {
                        return dst;
                    }
                } while (--k);
            }
            d++;
            src++;
        }
        unsigned int w = *(const unsigned int*)src;
        if (((w + 0xfefefeffu) & ~w & 0x80808080u) == 0) {
            d -= 4;
            unsigned int t;
            unsigned int nw;
            for (;;) {
                d += 4;
                *(unsigned int*)d = w;
                src += 4;
                w = *(const unsigned int*)src;
                t = w + 0xfefefeffu;
                nw = ~w;
                t &= nw;
                if ((t & 0x80808080u) != 0) {
                    break;
                }
            }
            d += 4;
        }
    }

    unsigned char c = *(const unsigned char*)src;
    *d = c;
    if (c != 0) {
        do {
            c = *(const unsigned char*)++src;
            *++d = c;
        } while (c != 0);
    }
    return dst;
}


#endif
