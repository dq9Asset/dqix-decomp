#include <globaldefs.h>

#if defined(jpn)
#define func_020679d4 func_02069294
enum { kCursor = 0x24, kControls = 0x50, kFlag = 0x17fe, kStreamState = 0x0c, kValue = 0x824 };
#else
enum { kCursor = 0x58, kControls = 0x90, kFlag = 0x19cd, kStreamState = 0x40, kValue = 0x954 };
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

// JPN: func_02069294
// USA: func_020679d4  (semantic: HandleActorStateTransition_020679d4)
extern "C" ARM void func_020679d4(char* self, int state) {
    switch (state) {
    case 0:
        func_0206b104(self);
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
#if defined(jpn)
        func_0206cbe8(self, 0xff16, *reinterpret_cast<unsigned short**>(self + kCursor));
#else
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff16, *(void**)(self + kCursor));
#endif
        InitBigStructVariant0205c840(self + kControls);
        *(unsigned char*)(self + kFlag) = 1;
        *(int*)(self + kStreamState) = 0;
        return;
    case 1:
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
    case -2:
        *(int*)(self + kValue) = 1;
        func_0206b104(self);
#if defined(jpn)
        func_0206cbe8(self, 0xff17, *reinterpret_cast<unsigned short**>(self + kCursor));
#else
        InitOrReinitContext0206b2c8((Ctx0206b2c8*)self, 0xff17, *(void**)(self + kCursor));
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
#undef func_020679d4
#undef InitBigStructVariant0205c840
#endif
