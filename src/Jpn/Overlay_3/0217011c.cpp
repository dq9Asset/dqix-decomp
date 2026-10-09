#if defined(jpn)
#include <globaldefs.h>

extern "C" void* func_02012dac(void);

struct Elem020985ec {
    unsigned char pad0[0x10];
    unsigned int key;
    unsigned char pad1[0xd4];
};

// JPN: func_ov003_0217011c
extern "C" ARM void func_ov003_0217011c(unsigned char* self) {
    struct Elem020985ec* arr = (struct Elem020985ec*)((char*)func_02012dac() + 0x860);
    int count = *(int*)(*(char**)(self + 0x170) + 0x1000 + 0xb38);

    int i;
    for (i = 0; i < 0x1e; i++) {
        *(int*)(self + i * 4 + 0xf4) = 0;
    }

    int n;
    int j = 0;
    for (n = 0; n < 0x1e; n++) {
        struct Elem020985ec* e = &arr[n];
        if ((e->key >> 2) != 0) {
            *(struct Elem020985ec**)(self + j * 4 + 0xf4) = e;
            j++;
        }
    }

    int divRaw = (count - 1) / 8 + 1;
    self[4] = divRaw;
    if (self[0] > self[4]) self[0] = self[4];

    if (self[0] == self[4]) {
        int mod = count % 8;
        if (mod != 0) {
            self[5] = (unsigned char)mod;
            return;
        }
    }
    self[5] = 8;
}

#endif
