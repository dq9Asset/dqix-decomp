#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov031_0223c834(int flag);
extern "C" int func_ov031_02223634(void);
extern "C" void func_ov031_0223e238(void* p);
extern "C" void func_ov031_022240ac(void);
extern "C" void func_ov031_02223c20(void);
extern "C" void func_ov031_0223bef0(void* p);
extern "C" void func_ov031_0223d39c(int a, int b);
extern "C" void func_ov031_02227cb0(int a, int b);
extern "C" void func_ov031_02227ca0(int fn);
extern "C" void func_ov031_02228804(void);
extern "C" void func_ov031_0222938c(void);
extern "C" void func_ov031_02228d7c(void);
extern "C" void func_ov031_0222a608(void);

struct Ctx02290c5c {
	unsigned char field0;
	unsigned char field1;
	char pad2[2];
	void* field4;
	void* field8;
};
extern Ctx02290c5c data_ov031_0229185c;

// JPN: func_ov031_02229d8c
extern "C" ARM void func_ov031_02229d8c(void) {
	if (func_ov031_0223c834(1)) return;
	if (func_ov031_0223c834(0)) return;
	if (!func_ov031_02223634()) return;

	func_ov031_0223e238(data_ov031_0229185c.field8);
	func_ov031_022240ac();
	func_ov031_02223c20();
	func_ov031_0223bef0(data_ov031_0229185c.field4);
	func_ov031_0223d39c(1, 1);
	func_ov031_0223d39c(0, 0x14);

	if (data_ov031_0229185c.field1 == 0) {
		func_ov031_02227cb0(0, 0);
		func_ov031_02227ca0((int)func_ov031_02228804);
		return;
	}

	switch (data_ov031_0229185c.field0) {
	case 0:
		func_ov031_02227cb0(0, 1);
		func_ov031_02227ca0((int)func_ov031_0222938c);
		break;
	case 1:
		func_ov031_02227cb0(0, 1);
		func_ov031_02227ca0((int)func_ov031_02228d7c);
		break;
	case 2:
		func_ov031_02227cb0(0, 1);
		func_ov031_02227ca0((int)func_ov031_0222a608);
		break;
	}
}

#endif
