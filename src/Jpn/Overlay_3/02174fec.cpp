#if defined(jpn)
#include <globaldefs.h>

struct Obj2081;
struct Elem2081;
extern "C" Elem2081* func_020826e4(Obj2081* obj, int key);

extern "C" int func_0204d5fc(unsigned char* obj);

struct Outer020e28dc;
extern "C" int func_020e447c(struct Outer020e28dc* o);

extern "C" void func_020814c4(void* obj, int id, int id2, short* out1, short* out2);

struct Ctx020e263c;
extern "C" void func_020e41dc(struct Ctx020e263c* obj, int value);

struct WinObj020e28f0;
extern "C" void func_020e4490(struct WinObj020e28f0* obj, short a, short b);

extern "C" void func_0205c228(void* obj);

// JPN: func_ov003_02174fec  (semantic: UpdateEntryLookOffset_02174fec)
extern "C" ARM void func_ov003_02174fec(unsigned char* self) {
    if (*(void**)(self + 0xf74) == NULL) {
        return;
    }
    if (*(short*)(self + 0xf7a) < 0) {
        return;
    }
    Elem2081* elem = func_020826e4(*(Obj2081**)(self + 0x818), *(short*)(self + 0xf7a));
    if (elem == NULL) {
        return;
    }
    if (func_0204d5fc((unsigned char*)elem) == 0 || *(void**)(self + 0x0) == NULL) {
        return;
    }
    if (func_020e447c(*(Outer020e28dc**)(self + 0x0)) != 0) {
        return;
    }
    short valA, valB;
    func_020814c4(*(Obj2081**)(self + 0x818), *(short*)(self + 0xf7a), *(short*)*(void**)(self + 0xf74), &valA, &valB);
    func_020e41dc(*(Ctx020e263c**)(self + 0x0), *(int*)(self + 0xf5c));
    valA = valA - 0x10;
    valB = valB - 3;
    func_020e4490(*(WinObj020e28f0**)(self + 0x0), valA, valB);
    func_0205c228(self + 0x754);
}

#endif
