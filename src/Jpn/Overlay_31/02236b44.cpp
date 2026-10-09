#if defined(jpn)
#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_ov031_02236954(void);

struct Base02236364 { void* field0; };
extern Base02236364 data_ov031_022918fc;

struct FlagsE6_02236364 { unsigned char mode : 2; unsigned char resv : 6; };

// JPN: func_ov031_02236b44
extern "C" ARM void func_ov031_02236b44(unsigned char* dst) {
	unsigned char* src = (unsigned char*)data_ov031_022918fc.field0 + 0x400;

	VectorizedMemset(src, 0, 0xef);
	VectorizedInvertedMemcpy(dst, src + 0xd1, 5);
	VectorizedInvertedMemcpy(dst + 0x6, src + 0xd6, 5);
	VectorizedInvertedMemcpy(dst + 0xc, src + 0xdb, 5);
	VectorizedInvertedMemcpy(dst + 0x12, src + 0xe0, 5);
	VectorizedInvertedMemcpy(dst + 0x18, src + 0x60, 0x20);
	VectorizedInvertedMemcpy(dst + 0x39, src + 0x80, 0xd);
	VectorizedInvertedMemcpy(dst + 0x47, src + 0x90, 0xd);
	VectorizedInvertedMemcpy(dst + 0x55, src + 0xa0, 0xd);
	VectorizedInvertedMemcpy(dst + 0x63, src + 0xb0, 0xd);
	VectorizedInvertedMemcpy(dst + 0x71, src + 0x40, 0x20);

	FlagsE6_02236364* f = (FlagsE6_02236364*)(src + 0xe6);
	f->mode = 2;
	f->resv = 0;
	src[0xe7] = 1;

	VectorizedMemset(src + 0xf0, 0, 4);
	src[0xf5] = 1;
	src[0xf6] = 1;
	func_ov031_02236954();
}

#endif
