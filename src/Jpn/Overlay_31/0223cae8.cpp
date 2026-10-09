#if defined(jpn)
#include <globaldefs.h>

struct HalfwordReader020b0e48 {
    unsigned int words[2];
};

struct StreamGlobals_0223c308 {
    HalfwordReader020b0e48 readers[2];
    unsigned char slots[0x660];
    void* f670;
    void* f674[2];
};

extern "C" void* func_ov031_0223d72c(int size, int align);
extern "C" int func_ov031_0223c6cc(int count, int array, int stride);
extern "C" int func_ov031_02227d28(void);
extern "C" void* func_ov031_0223bdfc(int id, int a, int b);
extern "C" void func_020b2914(HalfwordReader020b0e48* reader, void* data);

extern StreamGlobals_0223c308* data_ov031_02291938;
extern int data_ov031_0224d170[];
extern int data_ov031_0224d178[];

// JPN: func_ov031_0223cae8
extern "C" ARM void func_ov031_0223cae8(void) {
    StreamGlobals_0223c308* globals = (StreamGlobals_0223c308*)func_ov031_0223d72c(0x680, 4);

    data_ov031_02291938 = globals;
    data_ov031_02291938->f670 = (void*)func_ov031_0223c6cc(0x20, (int)globals->slots, 0x30);

    switch (func_ov031_02227d28()) {
    case 6: {
        int i = 0;
        int offset = 0;
        do {
            data_ov031_02291938->f674[i] = func_ov031_0223bdfc(data_ov031_0224d170[i], 0, 4);
            func_020b2914((HalfwordReader020b0e48*)((char*)data_ov031_02291938 + offset),
                               data_ov031_02291938->f674[i]);
            i++;
            offset += 8;
        } while (i < 2);
        break;
    }
    default: {
        int offset;
        int i = 0;
        offset = 0;
        do {
            data_ov031_02291938->f674[i] = func_ov031_0223bdfc(data_ov031_0224d178[i], 0, 4);
            func_020b2914((HalfwordReader020b0e48*)((char*)data_ov031_02291938 + offset),
                               data_ov031_02291938->f674[i]);
            i++;
            offset += 8;
        } while (i < 2);
        break;
    }
    }
}

#endif
