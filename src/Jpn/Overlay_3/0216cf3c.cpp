#if defined(jpn)
#include <globaldefs.h>

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
extern "C" void func_0205e510(Cont0205d1e0*);
extern "C" void func_0205e558(Cont0205d228*);
extern "C" void func_0205ed9c(void*, int, int, int);
extern "C" void func_0205e5a4(Cont0205d274*);
extern "C" void func_ov003_0216d400(void* obj);
extern "C" void func_ov003_0216d688(void* obj);
extern "C" void func_ov003_0216d794(void* obj);
extern "C" void func_ov003_0216faac(void* obj);
extern "C" void func_ov003_0215dd38(void* obj);
extern "C" void func_ov003_02173080(unsigned char* obj);

// JPN: func_ov003_0216cf3c
extern "C" ARM void func_ov003_0216cf3c(void* p) {
    char* obj = (char*)p;
    if (*(void**)(obj + 0x1000 + 0x150) != 0) {
        short f6 = *(short*)(obj + 6);
        if (f6 == 0 || f6 == 1 || *(short*)(obj + 4) == 2) {
            func_0205e510((Cont0205d1e0*)*(void**)(obj + 0x1000 + 0x150));
            func_0205e558((Cont0205d228*)*(void**)(obj + 0x1000 + 0x150));
            func_0205ed9c(*(void**)(obj + 0x1000 + 0x150), 2, 1, 1);
            func_0205e5a4((Cont0205d274*)*(void**)(obj + 0x1000 + 0x150));
        }
    }
    func_ov003_0216d400(obj);
    func_ov003_0216d688(obj);
    func_ov003_0216d794(obj);

    short f4 = *(short*)(obj + 4);
    if (f4 == 4) {
        func_ov003_0216faac(obj + 0x428);
        return;
    }
    if (f4 == 3) {
        if (*(short*)(obj + 6) == 1) {
            func_ov003_0215dd38(obj + 0x14);
        }
        return;
    }
    if (f4 == 5 && *(short*)(obj + 6) == 6) {
        func_ov003_02173080((unsigned char*)(obj + 0xda0));
    }
}

#endif
