#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_02001a08(void* a, void* b, int n);

struct Elem0206f6ac {
    unsigned char d[3];
    unsigned char f3[4];
    unsigned short v8[4];
    unsigned char f10[4];
    unsigned short v14[4];
};

struct Obj0206f6ac {
    struct Elem0206f6ac a[5];
    char name1[0x42];
    char pad0[0x255];
    char name2[0xf];
    char flag332;
    char pad1;
    struct Elem0206f6ac b[5];
    char name3[0x42];
    char pad2[2];
    int f404;
    int f408;
    char name4[0xf];
};

// JPN: func_0206f6ac
extern "C" ARM int func_0206f6ac(struct Obj0206f6ac* s) {
    int flag = 0;
    int i;

    if (s->f404 != 0 || s->f408 != 0) {
        for (i = 0; i < 5; i++) {
            struct Elem0206f6ac* ea = &s->a[i];
            struct Elem0206f6ac* eb = &s->b[i];
            unsigned int va = ea->d[0] * 10000 + ea->d[1] * 100 + ea->d[2];
            unsigned int vb = eb->d[0] * 10000 + eb->d[1] * 100 + eb->d[2];

            if (va > vb) {
                continue;
            }
            if (flag == 0 && func_02001a08(ea, eb, sizeof(struct Elem0206f6ac)) != 0) {
                flag = 1;
            }
            ea->d[0] = eb->d[0];
            ea->d[1] = eb->d[1];
            ea->d[2] = eb->d[2];
            {
                const unsigned char* p = eb->f3;
                int n = 4;
                unsigned char* d = ea->f3;
                do { *d = *p++; d++; } while (--n);
            }
            {
                const unsigned short* p = eb->v8;
                int n = 4;
                unsigned short* d = ea->v8;
                do { *d = *p++; d++; } while (--n);
            }
            {
                const unsigned char* p = eb->f10;
                int n = 4;
                unsigned char* d = ea->f10;
                do { *d = *p++; d++; } while (--n);
            }
            {
                const unsigned short* p = eb->v14;
                int n = 4;
                unsigned short* d = ea->v14;
                do { *d = *p++; d++; } while (--n);
            }
        }

        if (flag == 0) {
            if (func_02001a08(s->name1, s->name3, 0x42) != 0) {
                flag = s->f404;
            }
        }
        memcpy(s->name1, s->name3, 0x42);

        if (flag == 0) {
            if (func_02001a08(s->name2, s->name4, 0xf) != 0) {
                flag = 1;
            }
        }
        memcpy(s->name2, s->name4, 0xf);

        s->f404 = 0;
        s->f408 = 0;
    }
    return flag;
}

#endif
