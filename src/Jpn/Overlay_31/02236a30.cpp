#if defined(jpn)
#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_ov031_02236954(void);

struct Base02236250 { void* field0; };
extern Base02236250 data_ov031_022918fc;

struct FlagsE6_02236250 { unsigned char mode : 2; unsigned char resv : 6; };

// JPN: func_ov031_02236a30
extern "C" ARM void func_ov031_02236a30(unsigned char* self) {
	unsigned char* base = (unsigned char*)data_ov031_022918fc.field0;

	VectorizedMemset(base + 0x400, 0, 0xef);
	VectorizedInvertedMemcpy(self, base + 0x440, 0x20);

	int count;
	switch (*(int*)(self + 0x20)) {
	case 1:
		((FlagsE6_02236250*)(base + 0x4e6))->mode = 1;
		count = 5;
		break;
	case 2:
		((FlagsE6_02236250*)(base + 0x4e6))->mode = 2;
		count = 0xd;
		break;
	case 3:
		((FlagsE6_02236250*)(base + 0x4e6))->mode = 3;
		count = 0x10;
		break;
	default:
		((FlagsE6_02236250*)(base + 0x4e6))->mode = 0;
		count = 0;
		break;
	}
	((FlagsE6_02236250*)(base + 0x4e6))->resv = 0;

	int i = 0;
	unsigned char* s = base + 0x480;
	unsigned char* d = self + 0x28;
	do {
		VectorizedInvertedMemcpy(d, s, count);
		i++;
		s += 0x10;
		d += 0x20;
	} while (i < 4);

	base[0x4e7] = 2;
	VectorizedMemset(base + 0x4f0, 0, 4);
	base[0x4f5] = 1;
	base[0x4f6] = 1;
	func_ov031_02236954();
}

#endif
