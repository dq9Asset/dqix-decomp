#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov031_022235ec(void);
extern "C" void func_ov031_02237058(int a);
extern "C" void func_ov031_0222d33c(void);
extern "C" int FastIntDivide(int numer, unsigned int denom);
extern "C" void func_ov031_022359fc(void);
extern "C" void func_ov031_02223678(void);
extern "C" void func_ov031_0223830c(int a, int b, int c, int d, int e);
extern "C" void func_ov031_02227ca0(int fn);
extern "C" void func_ov031_0222d36c(void);
extern "C" void func_ov031_0222c908(void);

struct Manager0222c01c {
	char* entries;
	char pad4[0x38 - 4];
	int field38;
	char pad3c[0x52 - 0x3c];
	unsigned char field52;
	unsigned char pad53;
	unsigned char field54;
	char pad55[0x57 - 0x55];
	unsigned char field57;
};

struct Ctx02290c8c {
	unsigned char field0;
	unsigned char pad1;
	unsigned short field2;
	Manager0222c01c* field4;
};

extern Ctx02290c8c data_ov031_0229188c;

// JPN: func_ov031_0222c7fc
extern "C" ARM void func_ov031_0222c7fc(void) {
	if (data_ov031_0229188c.field4->field38 != 0 || data_ov031_0229188c.field4->field57 != 0) return;

	int r = func_ov031_022235ec();
	switch (r) {
	case 0:
		func_ov031_02237058(7);
		break;
	case 1:
		if (data_ov031_0229188c.field0 == 4) {
			data_ov031_0229188c.field4->field54 = 1;
			func_ov031_02237058(6);
			func_ov031_0222d33c();
			break;
		}
		{
			int d = FastIntDivide(data_ov031_0229188c.field2, 0x1c);
			int idx = data_ov031_0229188c.field0 + d;
			Manager0222c01c* mgr = data_ov031_0229188c.field4;
			unsigned char* entry = (unsigned char*)(mgr->entries + idx * 0x2a);
			if (entry[0x28] == 2) {
				func_ov031_02237058(9);
				func_ov031_022359fc();
				func_ov031_02223678();
				func_ov031_0223830c(0xe, 1, 1, -1, 0);
				func_ov031_02227ca0((int)func_ov031_0222d36c);
				return;
			}
			mgr->field54 = 1;
			data_ov031_0229188c.field4->field52 = (unsigned char)idx;
			func_ov031_02237058(6);
		}
		break;
	default:
		return;
	}
	func_ov031_02227ca0((int)func_ov031_0222c908);
}

#endif
