#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204775c(struct ByteHeader0204693c* p);

struct Obj021bb088;
extern "C" void func_ov017_021bb680(struct Obj021bb088* p);

extern "C" void* func_ov017_0218c1d0(void);
extern "C" unsigned int func_0203af1c(unsigned int* obj, unsigned int mask);

struct BitField0x178_021baedc { unsigned char bit0:1; unsigned char rest:7; };

// JPN: func_ov017_021bb4d4
extern "C" ARM void func_ov017_021bb4d4(void* self, int flag) {
	char* base = (char*)self;
	func_0204775c((struct ByteHeader0204693c*)base);
	*(signed char*)(base + 0x0) = 4;
	*(short*)(base + 0x8) = 0;
	*(short*)(base + 0xa) = 0;
	*(int*)(base + 0x8c) = 0;
	*(unsigned short*)(base + 0x116) = 0;
	*(short*)(base + 0x14a) = -1;
	*(unsigned char*)(base + 0x98) = 0;
	*(unsigned char*)(base + 0x94) = 0;
	*(unsigned char*)(base + 0x95) = 0;
	*(unsigned char*)(base + 0x96) = 0;
	*(unsigned char*)(base + 0x97) = 0;
	*(unsigned char*)(base + 0xc8) = 0;
	*(unsigned char*)(base + 0xc9) = 0;
	*(signed char*)(base + 0x9c) = -1;
	*(int*)(base + 0x10c) = -1;
	*(unsigned char*)(base + 0xfa) = 0;
	*(unsigned char*)(base + 0xfc) = 0;
	*(unsigned char*)(base + 0xfd) = 0;
	*(unsigned char*)(base + 0xfe) = 0;
	*(unsigned char*)(base + 0xff) = 0;
	*(unsigned char*)(base + 0x100) = 0;
	*(unsigned char*)(base + 0x102) = 0;
	*(unsigned char*)(base + 0x103) = 0;
	*(unsigned char*)(base + 0x104) = 0;
	*(unsigned char*)(base + 0x105) = 0;
	*(unsigned char*)(base + 0x106) = 0;
	*(unsigned char*)(base + 0x107) = 0;
	*(unsigned char*)(base + 0x108) = 0;
	if (flag == 0) {
		*(unsigned char*)(base + 0x101) = 0;
	}
	if (flag == 0) {
		*(unsigned short*)(base + 0x118) = 0;
	}
	memset(base + 0xc, 0, 0x68);
	*(unsigned short*)(base + 0x110) = 0;
	func_ov017_021bb680((struct Obj021bb088*)(base + 0xcc));
	if (func_0203af1c((unsigned int*)func_ov017_0218c1d0(), 0x1000) == 0) {
		((SafeAllocator*)(base + 0x78))->ResetAllocatorPointer();
	}
	*(int*)(base + 0x11c) = 0;
	((SafeAllocator*)(base + 0x120))->ResetAllocatorPointer();
	memset(base + 0x138, 0, 0x12);
	memset(base + 0x14c, 0, 0xa);
	*(int*)(base + 0x158) = 0;
	*(unsigned char*)(base + 0xf9) = 0;
	*(signed char*)(base + 0x112) = -1;
	*(int*)(base + 0x15c) = 0;
	*(unsigned char*)(base + 0x160) = 1;
	*(int*)(base + 0x16c) = 0;
	*(int*)(base + 0x164) = 0;
	*(int*)(base + 0x168) = 0;
	*(int*)(base + 0x134) = 0;
	*(unsigned char*)(base + 0xfb) = 0;
	*(unsigned char*)(base + 0x170) = 0;
	*(unsigned char*)(base + 0x171) = 0;
	((BitField0x178_021baedc*)(base + 0x174))->bit0 = 0;
	((BitField0x178_021baedc*)(base + 0x174))->rest = 0;
	*(unsigned char*)(base + 0x175) = 0;
	*(unsigned char*)(base + 0x176) = 0;
	*(unsigned char*)(base + 0x177) = 0;
	*(float*)(base + 0x178) = -1.0f;
	*(unsigned short*)(base + 0x180) = 0;
	memset(base + 0x184, 0, 0x30);
	memset(base + 0x1b4, 0, 0x10);
}

#endif
