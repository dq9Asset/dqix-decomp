#include <globaldefs.h>

struct List021db314 {
    char pad0[2];
    short limit;
    void* head;
};

struct Entry021db314 {
    char pad0[1];
    unsigned char flag1;
    char pad2[2];
    void* target;
};

extern "C" int func_02005a94(const char* text);
int ParseCodeLetter_021db564(char* str);

// USA: func_ov023_021db314  (semantic: ParseCodeEntriesIntoArray_021db314)
extern "C" ARM void func_ov023_021db314(void* obj, short* out, short* outCount) {
    struct List021db314* list = *(struct List021db314**)((char*)obj + 0x8);
    struct Entry021db314* entry = (struct Entry021db314*)list->head;
    short count = 0;
    short limit = list->limit;

    int i;
    for (i = 0; i < limit; i++, entry = (struct Entry021db314*)((char*)entry + 8)) {
        if (entry->flag1 != 0 && entry->target != NULL) {
            char* ptr = static_cast<char*>(entry->target);

            if (*ptr == 'f') {
                out[count] = (short)func_02005a94(ptr + 5);
                count++;
            } else if (*ptr >= 'A' && *ptr <= 'Z') {
                unsigned short v = (unsigned short)ParseCodeLetter_021db564(ptr);
                if (v != 0) {
                    out[count] = v;
                    count++;
                }
            }
        }
    }

    *outCount = count;
}
