#include <globaldefs.h>

#if defined(jpn)
#define func_020678bc func_0206917c
enum { kIndex = 0x44, kBuffer = 0x18, kCursor = 0x24, kControls = 0x50, kFlag = 0x17fe, kStreamState = 0x0c, kValue = 0x824 };
#else
enum { kIndex = 0x78, kBuffer = 0x4c, kCursor = 0x58, kControls = 0x90, kFlag = 0x19cd, kStreamState = 0x40, kValue = 0x954 };
#endif

struct Obj0205eaa0;

extern "C" void func_0206b104(void* obj);
#if defined(jpn)
extern "C" void func_0206cbe8(void*, unsigned short, unsigned short*);
#else
struct Ctx0206b2c8;
void InitOrReinitContext0206b2c8(Ctx0206b2c8*, int, void*);
#endif
#if defined(jpn)
extern "C" void func_0205dba0(char*);
#define InitBigStructVariant0205c840 func_0205dba0
#else
void InitBigStructVariant0205c840(char* obj);
#endif
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern char data_02108760;

// JPN: func_0206917c
// USA: func_020678bc  (semantic: DispatchStateChange_020678bc)
extern "C" ARM void func_020678bc(char* self, int state) {
    int idx = *(int*)(self + kIndex);
    unsigned short* table = *(unsigned short**)(self + kBuffer);
    unsigned short value = table[idx];
    int isFF06 = (value == 0xff06);
    int isFF07 = (value == 0xff07);

    switch (state) {
    case 0:
        func_0206b104(self);
        if (!isFF06) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        }
#if defined(jpn)
        func_0206cbe8(self, 0xff14, *reinterpret_cast<unsigned short**>(self + kCursor));
#else
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff14, *(void**)(self + kCursor));
#endif
        InitBigStructVariant0205c840(self + kControls);
        *(unsigned char*)(self + kFlag) = 1;
        *(int*)(self + kStreamState) = 0;
        return;
    case 1:
        if (!isFF06 && !isFF07) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        }
    case -2:
        *(int*)(self + kValue) = 1;
        func_0206b104(self);
#if defined(jpn)
        func_0206cbe8(self, 0xff15, *reinterpret_cast<unsigned short**>(self + kCursor));
#else
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff15, *(void**)(self + kCursor));
#endif
        InitBigStructVariant0205c840(self + kControls);
        *(unsigned char*)(self + kFlag) = 1;
        *(int*)(self + kStreamState) = 0;
        return;
    default:
        return;
    }
}

#if defined(jpn)
#undef func_020678bc
#undef InitBigStructVariant0205c840
#endif
