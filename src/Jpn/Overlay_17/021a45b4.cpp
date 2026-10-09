#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov017_021ae438(void* obj);
extern "C" void func_ov017_021a2310(void* obj);
extern "C" void func_ov017_021bbf28(void* self);
extern "C" void func_ov017_021b9e00(char* p);
extern "C" void func_ov017_021b8948(void* obj);
extern "C" void func_ov017_021a636c(void);
extern "C" void func_ov017_021bb478(void* obj);
extern "C" void func_ov017_021bb1bc(void* obj);
extern "C" void func_ov003_0217d288(int* obj);
extern "C" void func_ov017_021b361c(void);
struct S021b6b5c;
extern "C" void func_ov017_021b710c(S021b6b5c* obj);
extern "C" void func_ov003_0217dbc8(int* obj);
extern "C" void func_ov017_021ab5ec(void* obj);
extern "C" void func_ov017_021ad534(void);
struct ObjWithField4_021afa70;
extern "C" void func_ov017_021b0184(ObjWithField4_021afa70* obj);
extern "C" void func_ov017_021c0ae0(void* obj);
extern "C" void func_ov017_021c1798(void* obj);
struct Obj0217f218;
extern "C" void func_ov003_0217df1c(Obj0217f218* obj);
extern "C" void func_ov017_021b234c(void);
extern "C" void func_ov017_021b2628(void);
extern "C" void func_ov017_021b2a60(void);
extern "C" void func_ov017_021c1bd4(void);
extern "C" void func_ov017_021c1f90(void* obj);
extern "C" void func_ov017_021bf504(void);
extern "C" void func_ov017_021a9a2c(void* obj);
struct S021a9998;
extern "C" void func_ov017_021aa16c(S021a9998* obj);
extern "C" void func_ov017_021a8328(void* obj);
struct Struct020dae68;
extern "C" void func_020dc870(Struct020dae68* obj);

// JPN: func_ov017_021a45b4
extern "C" ARM void func_ov017_021a45b4(void* unused, void* obj) {
	if (!obj) return;
	if (*((unsigned char*)obj + 1) != 0) return;

	switch (*(signed char*)obj) {
	case 1:
		func_ov017_021ae438(obj);
		break;
	case 2:
		func_ov017_021a2310(obj);
		break;
	case 5:
		func_ov017_021b9e00((char*)obj);
		break;
	case 0xa:
		func_ov017_021b8948(obj);
		break;
	case 0xc:
		((void (*)(void*))func_ov017_021a636c)(obj);
		break;
	case 0xf:
		func_ov017_021bb478(obj);
		break;
	case 0x10:
		func_ov017_021bb1bc(obj);
		break;
	case 0x11:
		func_ov003_0217d288((int*)obj);
		break;
	case 4:
		func_ov017_021bbf28(obj);
		break;
	case 0x12:
		((void (*)(void*))func_ov017_021b361c)(obj);
		break;
	case 0x17:
		func_ov017_021b710c((S021b6b5c*)obj);
		break;
	case 0x18:
		func_ov003_0217dbc8((int*)obj);
		break;
	case 0x1a:
		func_ov017_021ab5ec(obj);
		break;
	case 0x1f:
		((void (*)(void*))func_ov017_021ad534)(obj);
		break;
	case 0x26:
		func_ov017_021b0184((ObjWithField4_021afa70*)obj);
		break;
	case 0x28:
		func_ov017_021c0ae0(obj);
		break;
	case 0x29:
		func_ov017_021c1798(obj);
		break;
	case 0x2a:
		func_ov003_0217df1c((Obj0217f218*)obj);
		break;
	case 0x2b:
		((void (*)(void*))func_ov017_021b234c)(obj);
		break;
	case 0x2c:
		((void (*)(void*))func_ov017_021b2628)(obj);
		break;
	case 0x2d:
		((void (*)(void*))func_ov017_021b2a60)(obj);
		break;
	case 0x2e:
		((void (*)(void*))func_ov017_021c1bd4)(obj);
		break;
	case 0x2f:
		func_ov017_021c1f90(obj);
		break;
	case 0x34:
		((void (*)(void*))func_ov017_021bf504)(obj);
		break;
	case 0x38:
		func_ov017_021a9a2c(obj);
		break;
	case 0x3a:
		func_ov017_021aa16c((S021a9998*)obj);
		break;
	case 0x3f:
		func_ov017_021a8328(obj);
		break;
	case 0x4b:
		func_020dc870((Struct020dae68*)obj);
		break;
	}
}

#endif
