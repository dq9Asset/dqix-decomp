#pragma once

// Existing twelve-byte name descriptor. Bit30 and bit31 have distinct producers.
struct ItemNameTextFlags {
    unsigned int field0 : 6;
    unsigned int field6 : 6;
    unsigned int field12 : 6;
    unsigned int field18 : 6;
    unsigned int field24 : 2;
    unsigned int field26 : 1;
    unsigned int field27 : 1;
    unsigned int field28 : 1;
    unsigned int reserved29 : 1;
    unsigned int field30 : 1;
    unsigned int field31 : 1;
};

struct ItemNameText {
    char* first;
    char* second;
    union {
        int flags;
        ItemNameTextFlags bits;
    };
};

char* AddResultIfField0Set020e46d8(char*, ItemNameText*);
char* AddResultIfField4Set020e4798(char*, ItemNameText*);
char* ResolveField8Entry6BitPlus100(char*, ItemNameText*);
char* ResolveField8Entry6BitPlus200(char*, ItemNameText*);
char* ResolveField8Entry6BitPlus300(char*, ItemNameText*);
char* UpdateObjectFromStateFlags(char*, ItemNameText*);
extern "C" char* func_020e462c(char*, const char*, const char*, const ItemNameText*);
extern "C" void func_020e4b34(ItemNameText*, char*, char*, unsigned int,
    unsigned char, unsigned char, unsigned char, unsigned char,
    unsigned char, unsigned char, unsigned char, unsigned char);
extern "C" void func_020e4f18(ItemNameText*, ItemNameText*, int);
extern "C" char* func_020e4958(char**, ItemNameText*, int, int, int, int);

extern "C" int func_02067f9c(ItemNameText*, const char*, int);
extern "C" int func_02067fec(ItemNameText*, const char*, int);
