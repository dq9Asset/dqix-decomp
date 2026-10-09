#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* func_0202a9d0(void);
struct List0202fe68;
struct List0202fec8;
extern "C" void __clear(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
extern "C" ARM unsigned short func_0209de38(struct HalfwordArray* src, struct HalfwordArray* dst);
struct func_0206ffb4Struct;
extern "C" void func_0206ffb4(struct func_0206ffb4Struct* obj);
struct StreamHeader;
extern "C" void func_0206ffd4(void* a, void* b, struct StreamHeader* c, int d, void* e, short f);
extern "C" void func_ov017_021b5bfc(void* obj);

extern char data_ov017_021d82f8;

struct Obj021b5348 {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
};

struct Sub021b5348 {
    char pad0[0x304];
    unsigned char field308;
};

// JPN: func_ov017_021b58fc
extern "C" ARM void func_ov017_021b58fc(struct Obj021b5348* obj) {
    void* subEarly;
    GameState::GetInstance();
    int list = (int)BackgroundLoader::GetInstance();
    func_0202a9d0();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    subEarly = obj->sub;
    if (((BackgroundLoader*)((struct List0202fe68*)list))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            char* sub = (char*)obj->sub;
            unsigned short buf[12];
            __clear(buf, 0x18);
            short signedCount = (short)func_0209de38((struct HalfwordArray*)(sub + 0x40), (struct HalfwordArray*)buf);
            func_0206ffb4((struct func_0206ffb4Struct*)((char*)subEarly + 0x300));
            void* ptrB = *(void**)((char*)obj->sub + 0x10);
            func_0206ffd4((char*)subEarly + 0x300, ptrB, (struct StreamHeader*)out1, (short)out2, buf, signedCount);
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(obj->key));
    obj->key = -1;
    int zero = 0;
    if (((struct Sub021b5348*)subEarly)->field308 > zero) {
        obj->key = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&data_ov017_021d82f8), (SafeAllocator*)(0));
        obj->field10 = 8;
    } else {
        func_ov017_021b5bfc(obj);
    }
}

#endif
