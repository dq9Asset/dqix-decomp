#if defined(jpn)
#include <globaldefs.h>

struct Outer020e28dc;
extern "C" int func_020e447c(struct Outer020e28dc* o);

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xac];
    short fac;
    short fae;
    unsigned char padb0[0xc];
    short fbc;
    short fbe;
    unsigned char padc0[0x5];
    unsigned char flagsC5;
};
extern "C" struct Elem_0205d81c* func_0205ebd8(struct Struct_0205d81c* s);
extern "C" int func_0204d5fc(unsigned char* p);

struct Container0205a3d0;
struct Elem0205a3d0 {
    unsigned char pad0[0x15];
    unsigned char flags;
};
extern "C" struct Elem0205a3d0* func_0205b76c(struct Container0205a3d0* c, int key);
extern "C" void func_0205b6e8(struct Container0205a3d0* c, int key);
extern "C" void func_020e438c(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void func_0205b7c8(struct Container0205a3d0* c, int key, int val);

struct Container0205a330;
extern "C" void func_0205b6a8(struct Container0205a330* c, int arg);

extern "C" void func_0205c228(void* obj);

// JPN: func_ov003_0215d640
extern "C" ARM void func_ov003_0215d640(char* obj) {
	struct Elem0205a3d0* e;

	if (*(unsigned char*)(obj + 0x59f) & 1) {
		struct Outer020e28dc* choice = *(struct Outer020e28dc**)(obj + 0x570);
		if (choice != NULL && func_020e447c(choice)) {
			func_0205c228(obj + 0x98);
			return;
		}

		struct Elem_0205d81c* elem = func_0205ebd8((struct Struct_0205d81c*)(obj + 0xf4));
		if (elem == NULL) return;
		if (!func_0204d5fc((unsigned char*)elem)) return;
		if (elem->flagsC5 & 0x20) return;

		short x = (short)(elem->fac * 8);
		short y = (short)(elem->fae * 8);
		x += elem->fbc;
		y += elem->fbe;
		struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0xd4);
		if (cont != NULL) {
			func_0205b6e8(cont, 0);
			e = func_0205b76c(cont, 0);
			if (e != NULL) {
				e->flags |= 8;
			}
			func_0205b6a8((struct Container0205a330*)cont, *(int*)(obj + 0x574));
			func_020e438c(cont, 0, x - 8, y - 2);
			func_0205b7c8(cont, 0, 0);
		}
		func_0205c228(obj + 0x98);
		return;
	}

	{
		struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0xd4);
		if (cont == NULL) return;
		e = func_0205b76c(cont, 0);
		if (e != NULL) {
			e->flags &= ~8;
		}
	}
}

#endif
