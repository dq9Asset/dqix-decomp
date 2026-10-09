#if defined(jpn)
#include <globaldefs.h>

struct Obj0207fcb8;
extern "C" void func_020807f4(struct Obj0207fcb8* obj);
struct Obj0207fd00;
extern "C" void func_0208083c(struct Obj0207fd00* obj);
extern "C" void func_020809bc(void* obj, int a, int b, int c);
struct Cont0207fd44;
extern "C" void func_02080880(struct Cont0207fd44* obj);
extern "C" void func_ov003_02166ea4(void* obj);
struct Outer020e28dc;
extern "C" int func_020e447c(struct Outer020e28dc* o);
struct Struct020e2794;
extern "C" void func_020e4334(struct Struct020e2794* self, void* b);
extern "C" void func_ov003_02160554(void* obj);
struct Obj02167548;
extern "C" void func_ov003_02167428(struct Obj02167548* obj);
struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void func_0205b6e8(struct Container0205a3d0* c, int key);
extern "C" struct Elem0205a3d0* func_0205b76c(struct Container0205a3d0* c, int key);
struct Container0205a330;
extern "C" void func_0205b6a8(struct Container0205a330* c, int arg);
extern "C" void func_020e438c(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void func_0205c228(void*);

// JPN: func_ov003_021602e0  (semantic: RefreshCombatantState_021602e0)
extern "C" ARM void func_ov003_021602e0(char* obj) {
    if (*(unsigned char*)(obj + 0x2cb) == 0) return;

    void* sub = *(void**)(obj + 0x20c);
    if (sub != 0) {
        func_020807f4((struct Obj0207fcb8*)sub);
        func_0208083c((struct Obj0207fd00*)sub);
        func_020809bc(sub, 1, 2, 1);
        func_02080880((struct Cont0207fd44*)sub);
    }
    func_ov003_02166ea4(obj);

    if (*(void**)(obj + 0x278) != 0 && func_020e447c((struct Outer020e28dc*)*(void**)(obj + 0x278)) != 0) {
        func_020e4334((struct Struct020e2794*)*(void**)(obj + 0x278), obj + 0x21c);
    }
    func_ov003_02160554(obj);

    if (*(struct Obj02167548**)(obj + 0x200) != 0) {
        func_ov003_02167428(*(struct Obj02167548**)(obj + 0x200));
    }

    if (!(*(unsigned int*)(obj + 0x28c) & 0x2000000)) return;

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x274);
    func_0205b6e8(cont, 1);

    cont = *(struct Container0205a3d0**)(obj + 0x274);
    struct Elem0205a3d0* e = func_0205b76c(cont, 0);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }

    cont = *(struct Container0205a3d0**)(obj + 0x274);
    e = func_0205b76c(cont, 1);
    if (e != NULL) {
        *(unsigned char*)((char*)e + 0x15) |= 8;
    }

    cont = *(struct Container0205a3d0**)(obj + 0x274);
    int arg = *(int*)(obj + 0x288);
    func_0205b6a8((struct Container0205a330*)cont, arg);

    cont = *(struct Container0205a3d0**)(obj + 0x274);
    func_020e438c(cont, 1, 0xd7, 0x96);

    func_0205c228(obj + 0x21c);
}

#endif
