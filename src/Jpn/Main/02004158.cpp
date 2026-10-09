#if defined(jpn)
#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// JPN: func_02004158
extern "C" ARM char* strstr(const char* hay, const char* needle) {
    unsigned char first;
    if (needle == 0 || (first = *(const unsigned char*)needle) == 0) {
        return (char*)hay;
    }

    unsigned char h = *(const unsigned char*)hay;
    char* p = (char*)hay + 1;
    if (h != 0) {
        do {
        if (h == first) {
            const unsigned char* q = (const unsigned char*)p;
            const unsigned char* n = (const unsigned char*)needle + 1;
            unsigned char nc;
            unsigned char hc;
            do {
                nc = *n++;
                hc = *q++;
            } while (hc == nc && hc != 0);
            if (nc == 0) {
                return p - 1;
            }
        }
            h = *(const unsigned char*)p++;
        } while (h != 0);
    }
    return 0;
}


#endif
