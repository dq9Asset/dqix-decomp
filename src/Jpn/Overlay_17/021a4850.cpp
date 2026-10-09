#if defined(jpn)
#include <globaldefs.h>

struct S_021a185c;
extern "C" void func_ov017_021a22ec(S_021a185c* obj);

struct S021b8408;
extern "C" void func_ov017_021b8918(S021b8408* obj);

struct S021b6b44;
extern "C" void func_ov017_021b70f4(S021b6b44* obj);

extern "C" void func_ov003_0217dbe0(int* obj);

struct ObjWithField4_021afa9c;
extern "C" void func_ov017_021b01b0(ObjWithField4_021afa9c* obj);

extern "C" void func_ov017_021c0ac8(void* obj);
extern "C" void func_ov017_021c17b0(void* obj);

struct Obj0217f230;
extern "C" void func_ov003_0217df34(Obj0217f230* obj);

extern "C" void func_ov017_021b236c(void);
extern "C" void func_ov017_021b262c(void);
extern "C" void func_ov017_021b2a40(void);

// JPN: func_ov017_021a4850
extern "C" ARM void func_ov017_021a4850(void* unused, void* obj) {
	if (!obj) return;
	if (*((unsigned char*)obj + 1) != 0) return;

	switch (*(signed char*)obj) {
	case 2:
		func_ov017_021a22ec((S_021a185c*)obj);
		break;
	case 0xa:
		func_ov017_021b8918((S021b8408*)obj);
		break;
	case 0x17:
		func_ov017_021b70f4((S021b6b44*)obj);
		break;
	case 0x18:
		func_ov003_0217dbe0((int*)obj);
		break;
	case 0x26:
		func_ov017_021b01b0((ObjWithField4_021afa9c*)obj);
		break;
	case 0x28:
		func_ov017_021c0ac8(obj);
		break;
	case 0x29:
		func_ov017_021c17b0(obj);
		break;
	case 0x2a:
		func_ov003_0217df34((Obj0217f230*)obj);
		break;
	case 0x2b:
		((void (*)(void*))func_ov017_021b236c)(obj);
		break;
	case 0x2c:
		((void (*)(void*))func_ov017_021b262c)(obj);
		break;
	case 0x2d:
		((void (*)(void*))func_ov017_021b2a40)(obj);
		break;
	}
}

#endif
