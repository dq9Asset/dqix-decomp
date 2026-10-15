#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/MessageSystem.h"

#if !defined(jpn)

extern "C" const char* func_0206a3c0(MessageSystem* messages, const char* text);

const char* FindUnescapedAngleBracket_020424ac(const char* str);
int IsPrefixMatch020d857c(const char* a, const char* b);
int StringStartsWithCI020d85dc(const char* str, const char* prefix);
int StringLength_020d2ff0(const char* s);


extern struct TagEntry02069fec data_020e7f84[];

extern struct NameList02069fec data_020e7e74;
extern char data_020f091b[];
extern char data_020f092a[];
extern char data_020f092f[];
struct IdTable02069fec {
    char pad0[0x24];
    unsigned short ids[2];
};
extern struct IdTable02069fec data_020e7e04;

// USA: func_02069fec
extern "C" ARM void func_02069fec(MessageSystem* ctx, const char* text, char* outArg) {
    unsigned short endcode;
    const char* src;
    if (text == 0 || outArg == 0) return;
    char* out = outArg;
    src = func_0206a3c0(ctx, text);
    ctx->flag19d4 = 1;
    unsigned short depth = 0;

    for (;;) {
        signed char c = *src;
        if (c == 0) break;

        if ((c == '\\' && src[1] == 'n') || (c == '\r' && src[1] == '\n')) {
            unsigned short code = 0xff18;
            memcpy(out, &code, 2);
            src += 2;
            out += 2;
            continue;
        }
        if (c == '\n') {
            unsigned short code = 0xff18;
            memcpy(out, &code, 2);
            src += 1;
            out += 2;
            continue;
        }
        if (c == '<') {
            const char* close = FindUnescapedAngleBracket_020424ac(src);
            if (close != 0) {
                const char* arg = src + 1;
                int matched = 0;
                struct TagEntry02069fec* e = data_020e7f84;
                while (e->name != 0 && e->fn != 0) {
                    if (StringStartsWithCI020d85dc(arg, e->name)) {
                        int len = StringLength_020d2ff0(e->name);
                        int n = e->fn(&out, arg + len);
                        out += n;
                        src = close + 1;
                        matched = 1;
                        break;
                    }
                    e++;
                }
                if (matched) continue;

                {
                    struct NameList02069fec names = data_020e7e74;
                    const char** np = names.p;
                    while (*np != 0) {
                        if (IsPrefixMatch020d857c(src, *np)) {
                            while (*src != '>') { src++; }
                            src++;
                            break;
                        }
                        np++;
                    }
                }

                if (IsPrefixMatch020d857c(src, data_020f091b)) {
                    int r7 = 0xe;
                    int id = func_02005a94(src + 0xe);
                    while (src[r7] != '>') {
                        if (src[r7] == 0) return;
                        r7++;
                    }
                    ctx->levels[depth] = (unsigned char)id;
                    unsigned short code = depth + 0x4d + 0xff00;
                    memcpy(out, &code, 2);
                    src += r7 + 1;
                    out += 2;
                    depth = (unsigned short)(depth + 1) & 3;
                    continue;
                }
                if (IsPrefixMatch020d857c(src, data_020f092a)) {
                    int r7 = 4;
                    int val = func_02005a94(src + 4);
                    while (src[r7] != '>') {
                        if (src[r7] == 0) return;
                        r7++;
                    }
                    unsigned short code = val + 0x334 + 0xfc00;
                    memcpy(out, &code, 2);
                    src += r7 + 1;
                    out += 2;
                    continue;
                }
                if (IsPrefixMatch020d857c(src, data_020f092f)) {
                    int r7 = 4;
                    int val = func_02005a94(src + 4);
                    while (src[r7] != '>') {
                        if (src[r7] == 0) return;
                        r7++;
                    }
                    short ids[2];
                    ids[0] = data_020e7e04.ids[0];
                    ids[1] = data_020e7e04.ids[1];
                    unsigned short result = 0xff4b;
                    unsigned short k = 0;
                    while (ids[k] >= 0) {
                        if (val == ids[k]) {
                            result += k;
                            break;
                        }
                        k++;
                    }
                    unsigned short code = result;
                    memcpy(out, &code, 2);
                    src += r7 + 1;
                    out += 2;
                    continue;
                }
            }
        }
        *out = *src;
        src++;
        out++;
    }
    endcode = 0xff01;
    memcpy(out, &endcode, 2);
    out += 2;
    *out = 0;
}

#endif
