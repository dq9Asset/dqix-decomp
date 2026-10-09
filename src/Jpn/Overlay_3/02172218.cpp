#if defined(jpn)
#include <globaldefs.h>

extern "C" void* func_ov017_0218c1d0(unsigned char* self);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void* p, int a, int b);
extern "C" int func_02012dac(void);
extern "C" void func_0209a280(void* obj, void* addr, int a, int b);

extern "C" int _Z32IsMainBrightnessTransitionActiveP13GameResources(int* p);
extern "C" void func_ov003_0216f460(char* obj);

// JPN: func_ov003_02172218  (semantic: UpdateCombatState_02172218)
extern "C" ARM void func_ov003_02172218(unsigned char* self) {
    int* p = (int*)func_ov017_0218c1d0(self);
    if (self[0xea] == 0) {
        _Z17SetMainBrightnessP13GameResourcesii(p, -16, 24);
        self[0xea] = 1;
        return;
    }
    if (self[0xea] != 1) {
        return;
    }
    if (_Z32IsMainBrightnessTransitionActiveP13GameResources(p) != 0) {
        return;
    }
    int r4 = func_02012dac();
    if (self[0xca] == 0) {
        func_ov003_0216f460((char*)r4 + 0x860);
        for (int i = 0; i < self[0xd1]; i++) {
            void* addr = (char*)*(int*)(self + 0xcc) + 0x35c + (unsigned char)i * 0xe8;
            func_0209a280((char*)r4 + 0x860, addr, 1, 0);
        }
        func_ov003_0216f460((char*)r4 + 0x860);
    }
    self[0xe8] = 6;
    self[0xea] = 0;
}

#endif
