#include <globaldefs.h>
#include "Resource/MessageSystem.h"

#if !defined(jpn)
const char* FindUnescapedAngleBracket_020424ac(const char*);
int IsPrefixMatch020d857c(const char*, const char*);
int StringLength_020d2ff0(const char*);
extern "C" int func_02005a94(const char*);
struct Tag0206831c {
    const char* name;
    void (*expand)(const char*, char**, MessageSystem*, int);
};
extern Tag0206831c data_020e7e5c[];
// USA: func_0206831c
extern "C" ARM void func_0206831c(MessageSystem* context, const char* input, char* destination) {
    char* output;
    if (!input || !destination) return;
    output = destination;
    while (1) {
        if (!*input) break;
        if (*input == '<') {
            const char* end = FindUnescapedAngleBracket_020424ac(input);
            if (end) {
                int found = 0;
                Tag0206831c* tag = data_020e7e5c;
                const char* name = input + 1;
                while (tag->name) {
                    if (IsPrefixMatch020d857c(name, tag->name)) {
                        if (tag->expand) {
                            int index = 0;
                            int length = StringLength_020d2ff0(tag->name);
                            signed char digit = name[length];
                            if (digit >= '1' && digit <= '9') index = func_02005a94(name + length) - 1;
                            tag->expand(name, &output, context, index);
                        }
                        input = end + 1;
                        found = 1;
                        break;
                    }
                    tag++;
                }
                if (found) continue;
            }
        }
        *output = *input++;
        output++;
    }
    *output = *input;
}

#endif
