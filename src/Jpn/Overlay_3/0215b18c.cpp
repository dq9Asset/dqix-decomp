#if defined(jpn)
#include <globaldefs.h>

extern "C" void* func_02042940(void);
extern "C" void* func_020d8608(void);
extern "C" void* func_0202a9d0(void);
extern "C" void func_ov003_0215a778(void*, int, int);
extern "C" void func_ov003_0215a73c(void*, void*);
extern "C" void func_0205f1c8(void*, int, int);
extern "C" int func_0202b388(void*);
extern "C" int func_0202c0cc(void*);
extern "C" void* func_020e2070(void*, int);
extern "C" int func_ov003_0215d230(void*, int);
extern "C" int func_02046450(void*);
extern "C" void* func_0205ff20(void);
extern "C" int func_02065c9c(void*, int, void*);
extern "C" void func_020708dc(void*);
extern "C" void func_02047504(void*, unsigned int);
extern "C" void func_ov017_021d1594(int, int, int, int);
extern "C" void func_ov017_021d1490(int, int, int);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void func_0209e5a8(void*, int);
extern "C" int func_020bdb70(int);
extern "C" void func_020abaf4(void*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv(void);
extern "C" int func_020ac914(void*, void*, int, int);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv(void);
extern "C" void func_0209e574(void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" int _ZN16BackgroundLoader17GetNumQueuedTasksEv(void);
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void);
extern "C" void func_02047298(void*);
extern "C" void func_02047418(void*, int, void*);
extern "C" void func_020426a8(void*, void*);
extern "C" void func_02047514(void*, unsigned int);
extern "C" void func_0205e9b4(void*, int);
extern "C" void* memset(void*, int, unsigned int);

extern int data_021098ac;
extern int data_0211fb64;

// JPN: func_ov003_0215b18c
extern "C" ARM void func_ov003_0215b18c(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)func_02042940();
    void* dp = func_020d8608();
    void* f = func_0202a9d0();
    char buf[0x34];

    if (*(int*)(g + 0x870) == 3) {
        *(unsigned char*)(g + 0x1000 + 0x7de) = 0;
    }

    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            if (*(unsigned char*)(s + 0x59d) != 0) return;
            memset(*(void**)(s + 0x7c), 0, 0x800);
            func_ov003_0215a778(self, 0x3e8, 0x64);
            func_ov003_0215a73c(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x5b3) = 5;
            *(unsigned char*)(s + 0x580) = 2;
            return;
        }
        func_0205f1c8(s + 0xf4, 0, 1);
        func_0205f1c8(s + 0xf4, 1, 1);
        func_0205f1c8(s + 0xf4, 2, 1);
        int key = 0x3f2;
        if (func_0202b388(f) && func_0202c0cc(f)) {
            key += 8;
        }
        func_ov003_0215a73c(self, func_020e2070(s + 0x64, key));
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 1) {
        if (*(int*)(g + 0x870) != 3) return;
        int r = func_ov003_0215d230(self, 0);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            memset(*(void**)(s + 0x7c), 0, 0x800);
            func_ov003_0215a778(self, 0x3f4, 0x3f5);
            func_ov003_0215a73c(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x580) = 4;
        } else if (r == 0) {
            *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
        }
        func_0205f1c8(s + 0xf4, 0, 1);
        func_0205f1c8(s + 0xf4, 1, 1);
        func_0205f1c8(s + 0xf4, 2, 1);
    }

    if (state == 2) {
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            if (*(int*)(g + 0x868) == 0) {
                *(unsigned char*)(s + 0x588) = 0xb;
                *(unsigned char*)(s + 0x580) = 0;
                return;
            }
            unsigned char prev = *(unsigned char*)(s + 0x5b3);
            int cur = *(int*)(g + 0x870);
            unsigned char low = cur;
            int ok = 1;
            if (prev == 6 && low == 5) {
                if (func_02046450(g) == 0) ok = 0;
            }
            *(unsigned char*)(s + 0x5b3) = (unsigned char)*(int*)(g + 0x870);
            if (ok) return;
        }
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
        if (func_02065c9c(func_0205ff20(), 0xc, buf)) {
            func_020708dc(buf);
        }
        if (*(unsigned char*)(s + 0x5b4) == 0) {
            func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x64));
        }
        func_02047504(dp, 0x80);
        *(int*)(s + 0x598) = 0xf;
        if (func_0202b388(f)) {
            func_ov017_021d1594(-1, 1, 1, 2);
            func_ov017_021d1490(-1, 1, 0);
        }
        *(unsigned char*)(s + 0x580) = 0x64;
    }

    if (state == 0x64) {
        if (func_0202b388(f)) {
            signed char* p = (signed char*)_ZN9GameState11GetInstanceEv() + 0x3280;
            p += 0x4000;
            for (int i = 0; i < 3; i++, p += 10) {
                if (p[6] >= 4) {
                    if (((unsigned char*)p)[7] != 0 || ((unsigned char*)p)[8] != 0) return;
                    if (p[9] >= 0) return;
                }
            }
        }
        func_0209e5a8(&data_021098ac, 0x3c);
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 2;
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 0x65) {
        if (*(int*)(g + 0x870) != 3) return;
        if (func_020bdb70(0x3c) == 0) return;
        if (*(int*)(g + 0x870) == 3) {
            *(unsigned char*)(g + 0x1000 + 0x7de) = 0;
        }
        if (*(unsigned char*)(s + 0x59c) == 0) {
            *(unsigned char*)(s + 0x59c) = 1;
        }
        func_020abaf4(s + 0x1b8 + 0x400);
        *(unsigned char*)(s + 0x580) = 0x66;
    }

    if (state == 0x66) {
        int flags = 1;
        if (func_0202c0cc(f)) flags |= 0x14;
        _ZN16BackgroundLoader13AddLockGlobalEv();
        _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
        if (func_020ac914(s + 0x1b8 + 0x400, &data_0211fb64, flags, 0) == 1) {
            *(unsigned char*)(s + 0x580) = 3;
        }
        _ZN16BackgroundLoader16RemoveLockGlobalEv();
    }

    if (state == 3) {
        if (*(int*)(g + 0x870) == 3) {
            *(unsigned char*)(g + 0x1000 + 0x7de) = 0;
        }
        func_0209e574(&data_021098ac);
        _ZN16BackgroundLoader11GetInstanceEv();
        if (_ZN16BackgroundLoader17GetNumQueuedTasksEv() > 0) return;
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) & ~2;
        memset(*(void**)(s + 0x7c), 0, 0x800);
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            _ZN9GameState11GetInstanceEv();
            unsigned char* obj = (unsigned char*)_ZN9GameState20GetUnknownGameObjectEv();
            func_02047298(g);
            func_02047418(g, 0, *(void**)(obj + 0x134));
            func_020426a8(*(void**)(s + 0x7c),
                func_020e2070(s + 0x64, 0x3f3));
        } else {
            func_ov003_0215a778(self, 0x3f3, 0x3f5);
        }
        func_ov003_0215a73c(self, *(void**)(s + 0x7c));
        func_02047514(dp, 0x80);
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) & ~0x10;
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            *(unsigned char*)(s + 0x580) = 7;
            return;
        }
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 4) {
        if (*(int*)(g + 0x870) != 3) return;
        int r = func_ov003_0215d230(self, 0);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            if (*(unsigned char*)(s + 0x59c) == 0) {
                func_0205f1c8(s + 0xf4, 0, 1);
                func_0205f1c8(s + 0xf4, 1, 1);
                func_0205f1c8(s + 0xf4, 2, 1);
                func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x3f7));
                *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
                return;
            }
            if (func_0202b388(f)) {
                func_0205f1c8(s + 0xf4, 0, 1);
                func_0205f1c8(s + 0xf4, 1, 1);
                func_0205f1c8(s + 0xf4, 2, 1);
                func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x3f9));
                *(unsigned char*)(s + 0x580) = 6;
                return;
            }
            func_0205e9b4(s + 0xf4, 1);
            func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        } else if (r == 0) {
            func_0205e9b4(s + 0xf4, 1);
            func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x442));
            *(unsigned char*)(s + 0x580) = 7;
        }
    }

    if (state == 5) {
        if (*(int*)(g + 0x870) != 3) return;
        int r = func_ov003_0215d230(self, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            func_0205f1c8(s + 0xf4, 0, 1);
            func_0205f1c8(s + 0xf4, 1, 1);
            func_0205f1c8(s + 0xf4, 2, 1);
            func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x3f8));
            *(unsigned char*)(s + 0x580) = 1;
            return;
        } else if (r == 0) {
            if (func_0202b388(f)) {
                func_0205f1c8(s + 0xf4, 0, 1);
                func_0205f1c8(s + 0xf4, 1, 1);
                func_0205f1c8(s + 0xf4, 2, 1);
                func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x3f9));
                *(unsigned char*)(s + 0x580) = 6;
                return;
            }
            func_0205e9b4(s + 0xf4, 1);
            func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        }
    }

    if (state == 6) {
        if (*(int*)(g + 0x870) != 3) return;
        int r = func_ov003_0215d230(self, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            func_0205e9b4(s + 0xf4, 1);
            func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x442));
            *(unsigned char*)(s + 0x580) = 7;
            return;
        } else if (r == 0) {
            func_0205e9b4(s + 0xf4, 1);
            func_ov003_0215a73c(self, func_020e2070(s + 0x64, 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        }
    }

    if (state == 7) {
        if (*(int*)(g + 0x868) == 0) {
            *(unsigned char*)(s + 0x588) = 0xb;
            *(unsigned char*)(s + 0x580) = 0;
        }
    }
}

#endif
