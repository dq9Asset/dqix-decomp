#include <globaldefs.h>

#if defined(jpn)
#include "std_library_functions.h"

extern const char data_020f001f[];
extern const char data_020f0021[];
extern const char data_020f0023[];

// JPN: func_02042798
extern "C" ARM unsigned int func_02042798(const char* text, unsigned int width, unsigned int fontWidth) {
    const char* openingMarker = data_020f001f;
    const char* opening = strstr(text, openingMarker);
    char buffer[32];
    char* output = buffer;
    memset(output, 0, sizeof(buffer));
    if (opening != NULL) {
        do {
            if (text != opening) {
                unsigned int count = opening - text;
                memcpy(output, text, count);
                text += count;
                output += count;
            }
            text++;
            const char* separator = strstr(text, data_020f0021);
            if (separator == NULL) break;
            unsigned int count = separator - text;
            memcpy(output, text, count);
            text += count;
            output += count;
            const char* closing = strstr(text, data_020f0023);
            if (closing == NULL) break;
            unsigned int skipped = closing + 1 - text;
            text += skipped;
            opening = strstr(text, openingMarker);
        } while (opening != NULL);
        memcpy(output, text, strlen(text));
        return (width - fontWidth * strlen(buffer) / 2) / 2;
    }
    return (width - fontWidth * strlen(text) / 2) / 2;
}
#endif
