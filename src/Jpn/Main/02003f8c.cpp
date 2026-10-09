#if defined(jpn)
#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// JPN: func_02003f8c
// Vectorised like strcpy once both pointers share an alignment, but the word loop
// only tests (w + 0xfefefeff) & 0x80808080 without the & ~w term, so a byte whose
// value is >= 0x80 also looks like a terminator and drops back to the byte compare.
extern "C" ARM int strcmp(const char* lhs, const char* rhs) {
    unsigned int a;
    unsigned int b;
    int d;

    a = *(const unsigned char*)lhs;
    b = *(const unsigned char*)rhs;
    d = (int)a - (int)b;
    if (d != 0) {
        return d;
    }

    unsigned int la = (unsigned int)lhs & 3;
    unsigned int lb = (unsigned int)rhs & 3;
    if (lb == la) {
        if (la != 0) {
            if (a == 0) {
                return 0;
            }
            unsigned int k = 3 - la;
            if (k != 0) {
                do {
                    a = *(const unsigned char*)++lhs;
                    b = *(const unsigned char*)++rhs;
                    d = (int)a - (int)b;
                    if (d != 0) {
                        return d;
                    }
                    if (a == 0) {
                        return 0;
                    }
                } while (--k);
            }
            lhs++;
            rhs++;
        }

        a = *(const unsigned int*)lhs;
        unsigned int t = a + 0xfefefeffu;
        unsigned int nw = ~a;
        t &= nw;
        unsigned int v = *(const unsigned int*)rhs;
        if ((t & 0x80808080u) == 0) {
            if (a == v) {
                do {
                    lhs += 4;
                    rhs += 4;
                    a = *(const unsigned int*)lhs;
                    v = *(const unsigned int*)rhs;
                    t = a + 0xfefefeffu;
                    if ((t & 0x80808080u) != 0) {
                        goto reload;
                    }
                } while (a == v);
            }
            lhs -= 1;
            rhs -= 1;
            goto tail;
        }

    reload:
        a = *(const unsigned char*)lhs;
        b = *(const unsigned char*)rhs;
        d = (int)a - (int)b;
        if (d != 0) {
            return d;
        }
    }

tail:
    if (a == 0) {
        return 0;
    }
    do {
        a = *(const unsigned char*)++lhs;
        b = *(const unsigned char*)++rhs;
        d = (int)a - (int)b;
        if (d != 0) {
            return d;
        }
    } while (a != 0);
    return 0;
}


#endif
