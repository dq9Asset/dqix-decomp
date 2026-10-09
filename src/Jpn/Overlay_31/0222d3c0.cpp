#if defined(jpn)
#include <globaldefs.h>

extern unsigned char data_ov031_02249aa8[2];
extern "C" void* func_ov031_0223d72c(unsigned int len, int align);

extern void* data_ov031_02291894;

extern "C" void func_ov031_02227d00(int*, int*);
extern "C" void func_ov031_022366ec(void*);
extern "C" int func_ov031_0223e514(unsigned char*, int);
extern "C" void func_ov031_0222d4f4(void);
extern "C" void func_ov031_02224178(int);
extern "C" void func_ov031_02223b4c(int, int, int);
extern "C" void func_ov031_02223cf8(int);
extern "C" int func_ov031_0223cd40(int, int);
extern "C" int func_ov031_0223c624(int, int);
extern "C" void func_ov031_0222db90(void);
extern "C" void func_ov031_0222da9c(void);
extern "C" void func_ov031_02227ca0(int);
extern "C" void func_ov031_0222d5b0(void);

struct BitsAt4_0222cbe0 { unsigned char pad[4]; unsigned short pad2 : 10; unsigned short field2bit : 2; };

// JPN: func_ov031_0222d3c0
extern "C" ARM void func_ov031_0222d3c0(void) {
	unsigned char localbuf[2];
	localbuf[0] = data_ov031_02249aa8[0];
	localbuf[1] = data_ov031_02249aa8[1];
	data_ov031_02291894 = func_ov031_0223d72c(0x2c, 4);

	int local8, local4;
	func_ov031_02227d00(&local8, &local4);

	if (local8 == 0) {
		func_ov031_022366ec((char*)data_ov031_02291894 + 8);
		unsigned char idx = func_ov031_0223e514((unsigned char*)((char*)data_ov031_02291894 + 8), 0x20);
		*((unsigned char*)data_ov031_02291894 + 0x29) = idx;
	}
	func_ov031_0222d4f4();
	func_ov031_02224178(local8 + 9);
	if (local4 == 1) {
		func_ov031_02223b4c(0x35, -1, 0);
	} else {
		func_ov031_02223b4c(localbuf[local8], -1, 0);
	}
	func_ov031_02223cf8(2);
	int r = func_ov031_0223cd40(0, 0);
	*(int*)data_ov031_02291894 = r;
	int r2 = func_ov031_0223c624(0, 0x3e);
	*(int*)((char*)data_ov031_02291894 + 4) = r2;
	BitsAt4_0222cbe0* p = *(BitsAt4_0222cbe0**)((char*)data_ov031_02291894 + 4);
	p->field2bit = 3;
	func_ov031_0222db90();
	func_ov031_0222da9c();
	func_ov031_02227ca0((int)func_ov031_0222d5b0);
}

#endif
