#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov031_02224780(void);
extern "C" void func_ov031_02224794(int);
extern "C" void func_ov031_022247a8(int);
extern "C" ARM void func_ov031_02227ca0(int);
extern "C" int func_ov031_02237058(int);
extern "C" int func_ov031_0222dd04(void);
extern "C" void func_ov031_0222da9c(void);
extern "C" void func_ov031_0222db90(void);
extern "C" void func_ov031_0222d874(void);

struct Struct0222ced0 {
	unsigned char pad0[4];
	int* field4;
	unsigned char pad8[0x29 - 8];
	unsigned char field29;
	unsigned char field2a;
};
extern Struct0222ced0* data_ov031_02291894;

// JPN: func_ov031_0222d6b0
extern "C" ARM void func_ov031_0222d6b0(void) {
	int v = func_ov031_02224780();
	switch (v) {
	case 0:
		goto epilogueA;
	case 0x80:
		if (data_ov031_02291894->field29 != 0) {
			func_ov031_02237058(3);
			data_ov031_02291894->field29 -= 1;
			{
				unsigned char* rec = (unsigned char*)data_ov031_02291894 + data_ov031_02291894->field29;
				rec[8] = 0;
			}
			if (data_ov031_02291894->field29 == 0) {
				func_ov031_02224794(0);
			}
			func_ov031_022247a8(1);
		}
		goto epilogueA;
	case 0x82:
		func_ov031_02237058(7);
		data_ov031_02291894->field2a = 0;
		func_ov031_02227ca0((int)func_ov031_0222d874);
		return;
	case 0x83:
		if (func_ov031_0222dd04()) {
			func_ov031_02237058(6);
			data_ov031_02291894->field2a = 1;
		} else {
			data_ov031_02291894->field2a = 2;
			func_ov031_02237058(9);
		}
		*(data_ov031_02291894->field4) = (*(data_ov031_02291894->field4) & 0xc1fffcff) | 0x200;
		func_ov031_02227ca0((int)func_ov031_0222d874);
		return;
	case 0xe01d:
	default:
		if (data_ov031_02291894->field29 != 0x20) {
			func_ov031_02237058(1);
			{
				unsigned char* rec = (unsigned char*)data_ov031_02291894 + data_ov031_02291894->field29;
				rec[8] = (unsigned char)v;
			}
			data_ov031_02291894->field29 += 1;
			func_ov031_02224794(1);
			if (data_ov031_02291894->field29 == 0x20) {
				func_ov031_022247a8(0);
			}
		}
		break;
	}
epilogueA:
	func_ov031_0222da9c();
	func_ov031_0222db90();
}

#endif
