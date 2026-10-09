#if defined(jpn)
#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long dividend, unsigned int divisor, unsigned int flag);
extern "C" int func_ov031_022152dc(unsigned int);
extern "C" int func_ov031_022157a8(void* obj, int mode);
extern "C" int func_ov031_02215990(void*, void*, int, int);

extern int data_ov031_02246ba4;

struct NibbleField_02214ea8 { unsigned char lo : 4; unsigned char hi : 4; };

// JPN: func_ov031_02215688
extern "C" ARM int func_ov031_02215688(char* obj) {
	unsigned long long diff = GetCurrentTimestamp() - *(unsigned long long*)(obj + 0xcb0);
	unsigned long long quotient = _ll_udiv(diff << 6, 0x82ea, 0);
	if (quotient < 150) {
		unsigned char idx = obj[0xd0f];
		char* row = obj + idx * 0x24;
		NibbleField_02214ea8* nf = (NibbleField_02214ea8*)(row + 0x300);
		if (nf->lo != 1) goto ret5;
	}

	{
		unsigned char idx0 = obj[0xd0f];
		char* base2 = obj + 0x300;
		unsigned char v2 = base2[idx0 * 0x24];
		v2 &= ~0xf;
		base2[idx0 * 0x24] = v2;
	}
	int idx = *(unsigned char*)(obj + 0xd0f) + 1;
	obj[0xd0f] = idx;
	if (*(unsigned char*)(obj + 0xd10) <= (unsigned char)idx) {
		*(unsigned char*)(obj + 0xd15) = *(unsigned char*)(obj + 0xd15) + 1;
		obj[0xd0f] = 0;
		obj[0xd11] = (unsigned char)func_ov031_022152dc(*(unsigned char*)(obj + 0xd15));
	}

	if (*(signed char*)(obj + 0xd11) < 0) {
		obj[0xd15] = 0;
		return func_ov031_022157a8(obj, 5);
	}

	*(unsigned long long*)(obj + 0xcb0) = GetCurrentTimestamp();
	idx = *(unsigned char*)(obj + 0xd0f);
	func_ov031_02215990(&data_ov031_02246ba4, obj + 0x304 + idx * 0x24, *(signed char*)(obj + 0xd11), 0x300000);
ret5:
	return 5;
}

#endif
