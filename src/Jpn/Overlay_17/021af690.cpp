#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov017_0218c1d0(void);
extern "C" void* func_0202a9d0(void);
extern "C" int func_0202b4b0(void* arr, void* buf);
struct ElementArray0202bad4;
struct Element0202bad4;
extern "C" int func_0202b694(void* obj);
extern "C" struct Element0202bad4* func_0202b684(struct ElementArray0202bad4* base, int index);
extern "C" int func_02001a08(void* a, void* b, int n);
struct FlagWord020466f4;
extern "C" void func_02047514(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void* func_020d8608(void);
extern "C" int* func_0209402c(void);
extern "C" void func_02094308(void* obj);
extern "C" void func_02094950(int*, short, short, signed char);
extern "C" void func_0203aef8(unsigned int* obj, unsigned int mask);
extern "C" void func_020dc9a4(int a, int b, int c, int d);
extern "C" void func_02047504(unsigned int* p, unsigned int mask);

// JPN: func_ov017_021af690
extern "C" ARM unsigned char func_ov017_021af690(void* self) {
    unsigned int* flags = (unsigned int*)func_ov017_0218c1d0();
    void* arr = func_0202a9d0();
    int status = func_0202b4b0(arr, (char*)self + 9);
    int i;
    for (i = 0; i < 6; i++);

    if (status >= 0) {
        int count = func_0202b694(arr);
        int j;
        for (j = 0; j < count; j++) {
            struct Element0202bad4* el = func_0202b684((struct ElementArray0202bad4*)arr, j);
            if (el != NULL) {
                int k;
                for (k = 0; k < 6; k++);
                func_02001a08((char*)el + 4, (char*)self + 9, 6);
            }
        }
    }

    if (status < 0) {
        func_02047514((struct FlagWord020466f4*)func_020d8608(), 0x8020);
        int* g = func_0209402c();
        func_02094308(g);
        func_02094950(g, 4, -1, 0);
        return 3;
    }

    func_0203aef8(flags, 0x40);
    *(short*)((char*)self + 0x12) = 0;
    func_020dc9a4(1, 1, 0, 1);
    func_02047504((unsigned int*)func_020d8608(), 0x800000);
    return 1;
}

#endif
