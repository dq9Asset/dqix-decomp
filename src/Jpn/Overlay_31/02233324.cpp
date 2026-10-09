#if defined(jpn)
#include <globaldefs.h>

extern "C" int func_ov031_0223c834(int);
extern "C" ARM int func_ov031_02237b68(void);
extern "C" int func_ov031_02223634(void);
extern "C" void func_ov031_0223c200(int a);
extern "C" void func_ov031_022240ac(void);
extern "C" void func_ov031_02223c20(void);
extern "C" void func_ov031_0223bef0(int a);
typedef void (*Callback_022234d8)(void*, int, int);
extern "C" void func_ov031_02223cb8(int a0, Callback_022234d8 cb);
extern "C" extern int LoadToMainObjStandardPalette(int, int, unsigned int);
extern "C" void func_ov031_0223d39c(int, int);
extern "C" void func_ov031_02227cb0(int, int);
extern "C" void func_ov031_02227ca0(int);
extern "C" void func_ov031_02228804(void);
extern "C" char* func_ov031_02236450(void);
extern "C" void func_ov031_02233a28(void);
extern "C" void func_ov031_02227cec(int, int);
extern "C" void func_ov031_022316d0(unsigned char);
extern "C" void func_ov031_0222f204(void);
extern "C" void func_ov031_02234d00(void);
extern "C" int func_ov031_0223d750(void*);

struct Inner02232b44 {
	int field0;
	int arr1[3];
	int arr2[3];
	unsigned char pad1;
	unsigned char f1d;
};

struct Outer02232b44 {
	unsigned char state;
	unsigned char pad[3];
	Inner02232b44* field4;
};

extern Outer02232b44 data_ov031_022918c0;
extern int data_ov031_0224c8ec;
extern char data_ov031_022918c4;

// JPN: func_ov031_02233324
extern "C" ARM void func_ov031_02233324(void) {
	if (func_ov031_0223c834(1) != 0) return;
	if (func_ov031_0223c834(0) != 0) return;
	if (func_ov031_02237b68() == 0) return;
	if (func_ov031_02223634() == 0) return;

	Outer02232b44* outer = &data_ov031_022918c0;
	unsigned int i = 0;
	do {
		int v = outer->field4->arr1[i];
		if (v != 0) {
			func_ov031_0223c200(v);
		}
		i++;
	} while (i < 3);
	outer = &data_ov031_022918c0;
	i = 0;
	do {
		int v = outer->field4->arr2[i];
		if (v != 0) {
			func_ov031_0223c200(v);
		}
		i++;
	} while (i < 3);

	func_ov031_022240ac();
	func_ov031_02223c20();
	func_ov031_0223bef0(data_ov031_022918c0.field4->field0);
	func_ov031_02223cb8((int)&data_ov031_0224c8ec, (Callback_022234d8)LoadToMainObjStandardPalette);
	func_ov031_0223d39c(1, 1);
	func_ov031_0223d39c(0, 0x14);

	if (data_ov031_022918c0.field4->f1d == 2) {
		func_ov031_02227cb0(0, 0);
		func_ov031_02227ca0((int)func_ov031_02228804);
	} else {
		switch (data_ov031_022918c0.state) {
		case 0:
		case 1:
		case 2:
			func_ov031_02227cb0(2, 0);
			if (*(unsigned char*)(func_ov031_02236450() + 0xe7) == 0xff) {
				func_ov031_02227ca0((int)func_ov031_02233a28);
			} else {
				func_ov031_02227cec(0, 0);
				func_ov031_022316d0(0);
				func_ov031_02227ca0((int)func_ov031_0222f204);
			}
			break;
		case 3:
			func_ov031_02227cb0(2, 1);
			func_ov031_02227ca0((int)func_ov031_02234d00);
			break;
		}
	}
	func_ov031_0223d750(&data_ov031_022918c4);
}

#endif
