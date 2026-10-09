#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_02042940(void);
extern "C" void func_ov003_0217011c(void* obj);
extern "C" void func_ov003_0216ff0c(void* obj);
extern "C" void func_02075c80(void* p);
extern "C" int func_ov017_0218c1d0(void);
extern "C" unsigned int func_0203af28(unsigned int* obj);
extern "C" void func_020c7054(int color, int alpha, int depth, int polygonId, int fogEnable);

// JPN: func_ov003_0216da64  (semantic: InitFieldsAndPriority_0216da64)
extern "C" ARM void func_ov003_0216da64(char* obj) {
	if (*(signed char*)(obj + 0x2) != 0) return;

	int baseAddr = func_02042940();
	*(int*)(obj + 0x18) = *(int*)(baseAddr + 0x28);
	func_ov003_0217011c(obj);
	func_ov003_0216ff0c(obj);
	func_02075c80(obj + 0x48);

	volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
	*(int*)(obj + 0x5c) = (*dispcnt & 0x1f00) >> 8;
	*dispcnt = (*dispcnt & ~0x1f00) | 0x700;

	*(int*)(obj + 0x174) = func_0203af28((unsigned int*)func_ov017_0218c1d0());
	func_020c7054(0, 0, 0x7fff, 0, 0);
	*(unsigned char*)(obj + 0x1) = 1;
	*(unsigned char*)(obj + 0x2) = 0;
	*(int*)(obj + 0x16c) = 0;
}

#endif
